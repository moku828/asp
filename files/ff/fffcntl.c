/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2012 by GT Development Center RICOH COMPANY,LTD. JAPAN
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
 *  @(#) $Id: fffcntl.c,v 1.2 2016/05/06 08:07:10 roi Exp $
 */

/*
 * FatFS��POSIX�Ѵ��Ѵؿ�
 * 1. ff_opendir               FatFS�ե�����Υ����ץ�ǥ��쥯�ȥ�
 * 2. ff_closedir              FatFS�ե�����Υ������ǥ��쥯�ȥ�
 * 3. ff_readdir               FatFS�ե�����Υǥ��쥯�ȥꥨ��ȥ��ɤ߽Ф�
 * 4. ff_mkdir                 FatFS�ե�����Υǥ��쥯�ȥ����
 * 5. ff_unlink                FatFS�ե�����Υǥ��쥯�ȥ�ޤ��ϥե�������
 * 6. ff_rename                FatFS�ե�����Υ�͡���
 * 7. ff_chmod                 FatFS�ե�����Υ����󥸥⡼��
 * 8. ff_stat                  FatFS�ե�����Υ����쥯�ȥ��ơ��Ȥμ��Ф�
 * 9. ff_statfs                FatFS�ե�����Υ����ƥॹ�ơ������μ��Ф�
 * 10.ff_open                  FatFS�ե�����Υ����ץ�
 * 11.ff_close                 FatFS�ե�����Υ�����
 * 12.ff_fstat                 FatFS�ե�����Υ��ơ��Ȥμ��Ф�
 * 13.ff_fseek                 FatFS�ե�����Υ�����
 * 14.ff_read                  FatFS�ե����뤫��Υǡ����ɤ߽Ф�
 * 15.ff_write                 FatFS�ե�����ؤΥǡ����񤭹���
 *
 */

#include <stdlib.h>
#include <string.h>
#include "storagedevice.h"
#include "ff.h"

#ifndef NUM_DIRNEST
#define NUM_DIRNEST 4
#endif
#ifndef NUM_FIL
#define NUM_FIL     16
#endif

#define	S_IRUSR	0000400	/* read permission, owner */
#define	S_IWUSR	0000200	/* write permission, owner */
#define	S_IXUSR 0000100/* execute/search permission, owner */
#define	S_IRGRP	0000040	/* read permission, group */
#define	S_IWGRP	0000020	/* write permission, grougroup */
#define	S_IXGRP 0000010/* execute/search permission, group */
#define	S_IROTH	0000004	/* read permission, other */
#define	S_IWOTH	0000002	/* write permission, other */
#define	S_IXOTH 0000001/* execute/search permission, other */

#define	FF_EINVAL 22	/* Invalid argument */

static void *ff_opendir(const char *pathname);
static int ff_closedir(void *dir);
static int ff_readdir(void *dir, void *pdirent);
static int ff_mkdir(const char *pathname);
static int ff_unlink(const char *pathname);
static int ff_rename(const char *oname, const char *nname);
static int ff_chmod(const char *name, int mode);
static int ff_stat(const char *name, struct stat *buf);
static int ff_statfs(const char *name, void *status);
static int ff_open(int devno, const char *pathname, int flags);
static int ff_close(int fd);
static int ff_fstat(int fd, struct stat *buf);
static off_t ff_lseek(int fd, off_t offset, int whence, int *res);
static long ff_read(int fd, void *buf, long count, int *res);
static long ff_write(int fd, const void *buf, long count, int *res);


const StorageDeviceFileFunc_t fatfsSDeviceFileFunc = {
	ff_opendir,
	ff_closedir,
	ff_readdir,
	ff_mkdir,
	ff_unlink,
	ff_unlink,
	ff_rename,
	ff_chmod,
	ff_stat,
	ff_statfs,
	ff_open,
	ff_close,
	ff_fstat,
	ff_lseek,
	ff_read,
	ff_write,
	0
};

typedef struct DIRPACK {
	DIR      dir;
	FILINFO  finfo;
} DIRP;

static FIL   FileObj[NUM_FIL];
static DIRP  dirobj[NUM_DIRNEST];
static UH    long_file_name[128];
static int   opendircount = 0;
static char  sddevname[256];
static int   ff_errno;

/*
 *  FatFs�ե�����ǥ��쥯�ȥꥪ���ץ�
 */
static void *ff_opendir(const char *pathname)
{
	DIRP *dirp;
	FRESULT result;

	if(opendircount >= NUM_DIRNEST)
		return NULL;
	dirp = &dirobj[opendircount++];
	if((result = f_opendir(&dirp->dir, pathname)) != FR_OK){
		ff_errno = result;
		opendircount--;
		return NULL;
	}
	else
		return dirp;
}

/*
 *  FatFs�ե�����ǥ��쥯�ȥꥯ����
 */
static int ff_closedir(void *dir)
{
	if(opendircount > 0)
		opendircount--;
	return 0;
}

/*
 *  FatFs�ե�����ǥ��쥯�ȥ��ɤ߹���
 */
static int ff_readdir(void *dir, void *pdirent)
{
	struct dirent2 *pd = pdirent;
	DIRP   *dirp = dir;
	FRESULT result;

#if _USE_LFN != 0
	dirp->dir.lfn = long_file_name;
#endif
	if((result = f_readdir(&dirp->dir, &dirp->finfo)) != FR_OK){
		ff_errno = result;
		return 0;
	}
	if(dirp->dir.sect == 0)
		return 0;
	pd->d_fsize = dirp->finfo.fsize;
	pd->d_date  = dirp->finfo.fdate;
	pd->d_time  = dirp->finfo.ftime;
	pd->d_type  = dirp->finfo.fattrib;
#if _USE_LFN != 0
	if(dirp->dir.lfn_idx != 0xffff){
		UH *pw, data;
		UB *p, *pe;
		pw = dirp->dir.lfn;
		p  = pd->d_name;
		pe = p+254;
		while(*pw != 0 && p < pe){
			data = ff_convert(*pw, 0);
			if(data <= 0x80)
				*p++ = (UB)data;
			else{
				*p++ = data >> 8;
				*p++ = (UB)data;
			}
			pw++;
		}
		*p = 0;
	}
	else
#endif
	{
		int     i;
		for(i = 0 ; i < (8+1+3) && dirp->finfo.fname[i] != 0 ; i++)
			pd->d_name[i] = dirp->finfo.fname[i];
		pd->d_name[i] = 0;
	}
	return 1;
}

/*
 *  FatFs�ǥ��쥯�ȥ����
 */
static int ff_mkdir(const char *pathname)
{
	int result = f_mkdir(pathname);
	if(result == FR_OK)
		return 0;
	else{
		ff_errno = result;
		return -1;
	}
}

/*
 *  FatFs�ǥ��쥯�ȥ�/�ե�������
 */
static int ff_unlink(const char *pathname)
{
	int result = f_unlink(pathname);
	if(result == FR_OK)
		return 0;
	else{
		ff_errno = result;
		return -1;
	}
}

/*
 *  FatFs��͡���
 */
static int ff_rename(const char *oname, const char *nname)
{
	int result = f_rename(oname, nname);
	if(result == FR_OK)
		return 0;
	else{
		ff_errno = result;
		return -1;
	}
}

/*
 *  FatFs�⡼���ѹ�
 */
static int ff_chmod(const char *name, int mode)
{
	FRESULT result;
	BYTE value = 0;
	BYTE mask  = AM_RDO;

	if((mode & (S_IWUSR|S_IWGRP|S_IWOTH)) == 0){
		value |= AM_RDO;
	}
	result = f_chmod(name, value, mask);
	if(result == FR_OK)
		return 0;
	else{
		ff_errno = result;
		return -1;
	}
}

/*
 *  FatFsľ�ܥե����륹�ơ��ȼ���
 */
static int ff_stat(const char *name, struct stat *buf)
{
	FILINFO finfo;
	FRESULT result;

	memset(buf, 0, sizeof(struct stat));
	finfo.lfname = NULL;
	result = f_stat(name, &finfo);
	if(result == FR_OK){
		buf->st_mode = S_IRUSR|S_IRGRP|S_IROTH;
		if((finfo.fattrib & AM_RDO) == 0)
			buf->st_mode |= S_IWUSR|S_IWGRP|S_IWOTH;
		buf->st_blksize = 512;
		buf->st_blocks  = (finfo.fsize+buf->st_blksize-1)/buf->st_blksize;
		buf->st_size = finfo.fsize;
		return 0;
	}
	else{
		ff_errno = result;
		return -1;
	}
}

/*
 *  FatFs�����ƥॹ�ơ������μ��Ф�
 */
static int ff_statfs(const char *name, void *status)
{
	struct statfs2 *p = status;
	FATFS   *fatfs;
	DWORD   nclust;
	FRESULT result;

	result = f_getfree(name, &nclust, &fatfs);
	if(result == FR_OK){
		memset(p, 0, sizeof(struct statfs2));
		p->f_bsize  = fatfs->csize * _MAX_SS;
		p->f_blocks = fatfs->max_clust-1;
		p->f_bfree  = nclust;
		return 0;
	}
	else{
		ff_errno = result;
		return -1;
	}
}

/*
 *  FatFs�ե����륪���ץ�
 */
static int ff_open(int devno, const char *pathname, int flags)
{
	int result, i;
	unsigned char mode;

	if(devno < 0 || devno >= MAXIMUM_DEVNO){
		ff_errno = FF_EINVAL;
		return -1;
	}
	sddevname[0] = devno + '0';
	sddevname[1] = ':';
	strcpy(&sddevname[2], pathname);
	mode = (flags+1) & 3;
	if(flags & O_CREAT)
		mode |= FA_OPEN_ALWAYS;
	if(flags & O_EXCL)
		mode |= FA_CREATE_NEW;
	result = -1;
	for(i = 0 ; i < NUM_FIL ; i++){
		if(FileObj[i].fs == 0){
			result = f_open(&FileObj[i], sddevname, mode);
			if(result == 0)
				return (i);
			else
				FileObj[i].fs = 0;
			break;
		}
	}
	ff_errno = result;
	return -1;
}

/*
 *  FatFs�ե����륯����
 */
static int ff_close(int fd)
{
	FRESULT result;

	if(fd >= NUM_FIL){
		ff_errno = FF_EINVAL;
		return -1;
	}
	result = f_close(&FileObj[fd]);
	if(result == FR_OK)
		return 0;
	else{
		ff_errno = result;
		return -1;
	}
}

/*
 *  FatFs�ե����륹�ơ��ȼ���
 */
static int ff_fstat(int fd, struct stat *buf)
{
	if(fd >= NUM_FIL){
		ff_errno = FF_EINVAL;
		return -1;
	}
	memset(buf, 0, sizeof(struct stat));
	buf->st_size = FileObj[fd].fsize;
#ifdef _EXT_RTOS
	buf->st_mtime = (FileObj[fd.fdate<<16)
                   | FileObj[fd].ftime;
#endif
	buf->st_atime = buf->st_ctime
                  = buf->st_mtime;
	buf->st_mode = S_IRUSR|S_IRGRP|S_IROTH;
	if((FileObj[fd].flag & FA_WRITE) != 0)
		buf->st_mode |= S_IWUSR|S_IWGRP|S_IWOTH;
	return 0;
}

/*
 *  FatFs�ե����륷����
 */
static off_t ff_lseek(int fd, off_t offset, int whence, int *res)
{
	off_t off = 0;
	FRESULT result;

	*res = -1;
	if(fd >= NUM_FIL){
		ff_errno = FF_EINVAL;
		return -1;
	}
	switch (whence) {
	case SEEK_SET:
		off = offset;
		break;
	case SEEK_CUR:
		off = FileObj[fd].fptr + offset;
		break;
	case SEEK_END:
		off = FileObj[fd].fsize + offset;
		break;
	default:
		ff_errno =  FF_EINVAL;
		return -1;
	}
	result = f_lseek(&FileObj[fd], off);
	if(result != FR_OK){
		ff_errno = result;
		off = -1;
	}
	else
		*res = 0;
	return off;
}

/*
 *  FatFs�ե������ɤߤ���
 */
static long ff_read(int fd, void *buf, long count, int *res)
{
	long n;
	unsigned int n2;
	FRESULT result;

	*res = -1;
	if(fd >= NUM_FIL){
		ff_errno = FF_EINVAL;
		return 0;
	}
	result =  f_read(&FileObj[fd], buf, count, &n2);
	n = n2;
	if(result != FR_OK){
		ff_errno = result;
		n = 0;
	}
	else
		*res = 0;
	return n;
}

/*
 *  FatFs�ե�����񤭹���
 */
static long ff_write(int fd, const void *buf, long count, int *res)
{
	long n = 0;
	unsigned int n2 = 0;
	FRESULT result;

	*res = -1;
	if(fd >= NUM_FIL){
		ff_errno = FF_EINVAL;
		return 0;
	}
	result = f_write(&FileObj[fd], buf, count, &n2);
	n = n2;
	if(result != FR_OK){
		ff_errno = result;
		n = 0;
	}
	else
		*res = 0;
	return n;
}

/* This function is called each time errno is evaluated. */
int *__errno(void)
{
	return (int *)&ff_errno;
}

