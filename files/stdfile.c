/*
 *  TOPPERS/ASP/FMP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile/Flexible MultiProcessor Kernel
 * 
 *  Copyright (C) 2008-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2015-2018 by TOPPERS PROJECT Educational Working Group.
 * 
 *  �嵭����Ԥϡ��ʲ��� (1)��(4) �ξ�狼��Free Software Foundation 
 *  �ˤ�äƸ�ɽ����Ƥ��� GNU General Public License �� Version 2 �˵�
 *  �Ҥ���Ƥ���������������˸¤ꡤ�ܥ��եȥ��������ܥ��եȥ�����
 *  ����Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ������ۡʰʲ���
 *  ���ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *      �ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����
 *  �ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ
 *  ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
 * 
 *  @(#) $Id: stdfile.c,v 1.5 2018/06/25 22:02:45 roi Exp $
 */
/*
 * TOPPERS/ASP/FMP+FATFS�б���POSIX�ե�����ؿ�
 */
#include <kernel.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "storagedevice.h"
#include "kernel_cfg.h"

#ifndef NUM_FIL
#define NUM_FIL 16
#endif

/* sys/dirent.h */
struct dirent {
  unsigned long  d_fileno;		/* file number of entry */
  unsigned short d_reclen;		/* length of this record */
  unsigned char  d_type; 		/* file type, see below */
  unsigned char  d_namlen;		/* length of string in d_name */
#define	MAXNAMLEN	255
  char	d_name[MAXNAMLEN + 1];	/* name must be no longer than this */
};

/* File types */
#define DT_UNKMOWN  0
#define DT_FIFO     1
#define DT_CHAR     2
#define DT_DIR      4
#define DT_BLK      6
#define DT_REG      8
#define DT_LNK      10
#define DT_SOCK     12
#define DT_WHT      14


static FILE iod[NUM_FIL];
static StorageDevice_t *pdirpsdev = 0;

extern int _setup_file(FILE *st, StorageDevice_t *pd, int lid);

/*
 *  allocate file structure
 */
static FILE *alloc_file(void)
{
  FILE *fp;
  int i;

  loc_cpu();
  for(fp = iod, i = 0 ; i < NUM_FIL ; fp++, i++){
    if(fp->_flags == 0){
      fp->_flags = __SRW;
      unl_cpu();
      return fp;
    }
  }
  unl_cpu();
  return 0;
}

/*
 *  free file structure
 */
static void free_file(FILE * fp)
{
  if(fp != NULL)
    fp->_flags = 0;
}

/*
 *  fopen - open a file
 *  notice - not support text mode.
 *           not support append mode.
 */
FILE *fopen(const char *name, const char *type)
{
  StorageDevice_t         *psdev;
  StorageDeviceFileFunc_t *pff;
  FILE                    *fp;
  int                     devno, i, id;
  unsigned int            mode = 0;
  unsigned int            stat = 0;

  if((devno = SDMGetDeviceNo(&name)) < 0)
    return NULL;
  if((psdev = SDMGetStorageDevice(devno)) == 0)
    return NULL;
  pff = psdev->pdevff;
  if(pff != 0 && pff->_sdevff_open == 0)
    return NULL;

  if((fp = alloc_file()) != 0){
    for(i = 0 ; i < 8 && type[i] >= ' ' ; i++){
      switch(type[i]){
      case 'r':
        stat |= O_RDONLY;
        fp->_flags |= __SRD;
        break;
      case 'w':
        stat |= O_WRONLY | O_CREAT;
        fp->_flags |= __SWR;
        break;
      case 'a':
        stat |= O_RDWR | O_CREAT;
        fp->_flags |= __SRD | __SWR;
        break;
      case 'b':
        break;
      case '+':
        break;
      }
    }
    if((stat & O_ACCMODE) == (O_WRONLY | O_RDWR))
      mode = (stat & ~O_ACCMODE) | O_RDWR;
    else
      mode = stat;
    wai_sem(SEM_STDFILE);
    id = pff->_sdevff_open(devno, name, mode);
    sig_sem(SEM_STDFILE);
    if(id < 0){
      free_file(fp);
      return NULL;
    }
    _setup_file(fp, psdev, id);
    return fp;
  }
  else
    return NULL;
}

/*
 *  fclose - close a file
 */
int fclose(FILE *fp)
{
  StorageDevice_t  *psdev;
  int              result;

  if(fp == NULL)
    return -1;
  psdev = fp->_dev;
  wai_sem(SEM_STDFILE);
  if(psdev->pdevff != 0 && psdev->pdevff->_sdevff_close != 0)
    result = psdev->pdevff->_sdevff_close(fp->_file);
  else
    result = -1;
  sig_sem(SEM_STDFILE);
  free_file(fp);
  return result;
}

/*
 *  fseek - seek a file
 */
int fseek(FILE *fp, long offset, int whence)
{
  StorageDevice_t  *psdev;
  int result, res = 0;

  if(fp == NULL)
    return -1;
  psdev = fp->_dev;
  if(psdev->pdevff != 0 && psdev->pdevff->_sdevff_lseek != 0){
    result = psdev->pdevff->_sdevff_lseek(fp->_file, offset, whence, &res);
    if(res < 0)
        fp->_flags |= __SERR;
    return result;
  }
  else
    return -1;
}

/*
 *  ftell - get position file indicator
 */
long ftell(FILE *fp)
{
  StorageDevice_t  *psdev;
  long result;
  int  res = 0;

  if(fp == NULL)
    return -1;
  psdev = fp->_dev;
  if(psdev->pdevff != 0 && psdev->pdevff->_sdevff_lseek != 0){
    result = psdev->pdevff->_sdevff_lseek(fp->_file, 0, SEEK_CUR, &res);
    if(res < 0)
        fp->_flags |= __SERR;
    return result;
  }
  else
    return -1;
}

/*
 *  stat - get file status
 *       - set st_mode, st_atime, st_atimensec, st_mtime, st_mtimensec
 *             st_ctime, st_ctimensec, st_blksize, st_blocks, st_size
 */
int stat(const char *name, struct stat *buf)
{
  StorageDevice_t *psdev;
  int             devno;
  const char      *sname = name;

  devno = SDMGetDeviceNo((const char **)&name);
  psdev = SDMGetStorageDevice(devno);
  if(psdev == NULL)
    return -1;
  if(psdev->pdevff == 0 || psdev->pdevff->_sdevff_stat == 0)
    return -1;
  if(psdev->pdevff->_sdevff_stat(sname, buf) >= 0)
    return 0;
  else
    return -1;
}

/*
 *  lstat from fsiunixlike.c, fslpux.c
 */
int lstat(const char *path, struct stat *buf)
{
  return stat(path, buf);
}

/*
 *  access from fsiunixlike.c(2)
 *  mode=0-file exist, mode=2-writeable OK-0 Err--1
 */
int access(const char *path, int mode)
{
  struct stat     buf;
  int             res = -1;

  if(stat(path, &buf) >= 0){
    res = 0;
    if((mode & 0x02) != 0 && (buf.st_flags & 0x0001) != 0)	/* read only(no debug) */
      res = -1;
  }
  return res;
}

/*
 *  mkdir - make directory
 *        - not support mode
 */
int mkdir(const char *path, mode_t mode)
{
  StorageDevice_t *psdev;
  int             devno;

  devno = SDMGetDeviceNo((const char **)&path);
  psdev = SDMGetStorageDevice(devno);
  if(psdev == NULL)
    return -1;
  if(psdev->pdevff == 0 || psdev->pdevff->_sdevff_mkdir == 0)
    return -1;
  if(psdev->pdevff->_sdevff_mkdir(path) >= 0)
    return 0;
  else
    return -1;
}

/*
 *  rmdir from fsiunixlike.c(3), fslpux.c, device.c
 */
int rmdir(const char *path)
{
  StorageDevice_t *psdev;
  int             devno;

  devno = SDMGetDeviceNo((const char **)&path);
  psdev = SDMGetStorageDevice(devno);
  if(psdev == NULL)
    return -1;
  if(psdev->pdevff == 0 || psdev->pdevff->_sdevff_rmdir == 0)
    return -1;
  if(psdev->pdevff->_sdevff_rmdir(path) >= 0)
    return 0;
  else
    return -1;
}

/*
 *  chmod from fsiunixlike.c(2)
 */
int chmod(const char *path, mode_t mode)
{
  StorageDevice_t *psdev;
  int             devno;

  devno = SDMGetDeviceNo((const char **)&path);
  psdev = SDMGetStorageDevice(devno);
  if(psdev == NULL)
    return -1;
  if(psdev->pdevff == 0 || psdev->pdevff->_sdevff_chmod == 0)
    return -1;
  if(psdev->pdevff->_sdevff_chmod(path, mode) >= 0)
    return 0;
  else
    return -1;
}

/*
 *  remove - remove a file
 */
int remove(const char *name)
{
  StorageDevice_t *psdev;
  int             devno;

  devno = SDMGetDeviceNo((const char **)&name);
  psdev = SDMGetStorageDevice(devno);
  if(psdev == NULL)
    return -1;
  if(psdev->pdevff == 0 || psdev->pdevff->_sdevff_unlink == 0)
    return -1;
  if(psdev->pdevff->_sdevff_unlink(name) >= 0)
    return 0;
  else
    return -1;
}

/*
 *  unlink - remove file
 */
bool_t unlink(const char *path)
{
  StorageDevice_t *psdev;
  int             devno;

  devno = SDMGetDeviceNo((const char **)&path);
  psdev = SDMGetStorageDevice(devno);
  if(psdev == NULL)
    return -1;
  if(psdev->pdevff == 0 || psdev->pdevff->_sdevff_unlink == 0)
    return -1;
  if(psdev->pdevff->_sdevff_unlink(path) >= 0)
    return 0;
  else
    return -1;
}

/*
 *  rename - change file name
 */
int rename(const char *oldpath, const char *newpath)
{
  StorageDevice_t *psdev;
  int             devno;

  devno = SDMGetDeviceNo((const char **)&oldpath);
  psdev = SDMGetStorageDevice(devno);
  if(psdev == NULL)
    return -1;
  if(psdev->pdevff == 0 || psdev->pdevff->_sdevff_rename == 0)
    return -1;
  if(psdev->pdevff->_sdevff_rename(oldpath, newpath) >= 0)
    return 0;
  else
    return -1;
}

/*
 *  mkstemp from fsiunixlike.c, device.c
 */
int mkstemp(char *path)
{
	printf("### mkstemp() !! ##\n");
	slp_tsk();
	return 0;
}

/*
 *  opendir from fsiunixlike.c, fslpux.c(2), device.c
 */
void *opendir(const char *path)
{
  int             devno;

  devno = SDMGetDeviceNo((const char **)&path);
  pdirpsdev = SDMGetStorageDevice(devno);
  if(pdirpsdev == NULL)
    return NULL;
  if(pdirpsdev->pdevff == 0 || pdirpsdev->pdevff->_sdevff_opendir == 0)
    return NULL;
  return pdirpsdev->pdevff->_sdevff_opendir(path);
}

/*
 *  closedir from fsiunixlike.c(2), fslpux.c(4)
 */
int closedir(void *dir)
{
  if(pdirpsdev == NULL)
    return 0;
  if(pdirpsdev->pdevff == 0 || pdirpsdev->pdevff->_sdevff_closedir == 0)
    return 0;
  return pdirpsdev->pdevff->_sdevff_closedir(dir);
}

/*
 *  readdir from fsiunixlike.c, fslpux.c(2), device.c
 */
struct dirent *readdir(void *dir)
{
  static struct dirent  Dirent;
  static struct dirent2 finfo;
  struct dirent *pdirent;
  int    i;

  if(pdirpsdev == 0)
    return NULL;
  if(pdirpsdev->pdevff == 0 || pdirpsdev->pdevff->_sdevff_readdir == 0)
    return NULL;
  if(pdirpsdev->pdevff->_sdevff_readdir(dir, &finfo) == 0)
    return NULL;
  pdirent = &Dirent;
  memset(pdirent, 0, sizeof(struct dirent));
  for(i = 0 ; i < MAXNAMLEN && finfo.d_name[i] != 0 ; i++)
    pdirent->d_name[i] = finfo.d_name[i];
  pdirent->d_namlen = i;
  pdirent->d_reclen = i;
  if(finfo.d_type & AM_DIR)
    Dirent.d_type = DT_DIR;
  else
    Dirent.d_type = DT_BLK;
  return pdirent;
}

/*
 *  statfs from fslpux.c
 */
int statfs(const char *path, struct statfs2 *status)
{
  StorageDevice_t *psdev;
  int             devno;
  const char      *name = path;

  devno = SDMGetDeviceNo((const char **)&path);
  psdev = SDMGetStorageDevice(devno);
  if(psdev == NULL)
    return -1;
  if(psdev->pdevff == 0 || psdev->pdevff->_sdevff_statfs == 0)
    return -1;
  return psdev->pdevff->_sdevff_statfs(name, (void *)status);
}

