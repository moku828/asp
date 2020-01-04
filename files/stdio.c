/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2015-2016 by TOPPERS PROJECT Educational Working Group.
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
 *  @(#) $Id: stdio.c,v 1.3 2016/05/08 08:08:32 roi Exp $
 */
/*
 * ���Υץ�����ITRON���Ѥ�TYPE3���եȥ������Ǥ��롣
 * POSIX�Υե�����ؿ��򶡵뤹�롣
 * ����Ū�ʥ��ȥ졼���ؿ����Ǥ��ꡢɸ��饤�֥�ꥣ��ʬ���Ƥλ��Ѥ�˾�ޤ�����
 * 1. _stdfile_init            �ե����륤��ǥå����ν������Ԥ�
 * 2. open                     �ե�����Υ����ץ�(���̤�����FD��ȯ�Ԥ���)
 * 3. close                    �ե�����Υ�����
 * 4. fstat                    �ե�����Υ��ơ��Ȥμ��Ф�
 * 5. fseek                    �ե�����Υ�����
 * 6. read                     �ե����뤫��Υǡ����ɤ߽Ф�
 * 7. write                    �ե����뤫��Υǡ����񤭹���
 * 8. mmap                     �ե�����ǡ����Υޥåײ�
 * 9. munmap                   �ե�����ǡ����Υ���ޥåײ�
 */

#include <kernel.h>
#include <stdio.h>
#include <stdlib.h>
#include "kernel_cfg.h"
#include "fcntl.h"
#include "storagedevice.h"

#ifndef NUM_FILEIDX
#define NUM_FILEIDX	128
#endif


static struct StdFileIndex stdfile[NUM_FILEIDX];


void stdfile_init(intptr_t exinf)
{
	unsigned int idx;

	for(idx = 0 ; idx < NUM_FILEIDX ; idx++){
		stdfile[idx].sdmdev = 0;
		stdfile[idx].sdmfd = -1;
	}
}

/*
 *  FD�����å��ؿ�
 */
static struct StdFileIndex *fdcheck(int fd)
{
	struct StdFileIndex *pf;

	if(fd <= 0 || fd > NUM_FILEIDX)
		return 0;
	pf = &stdfile[fd-1];
	if(pf->sdmfd == -1)
		return 0;
	else
		return pf;
}

/*
 *  ɸ��ե����륤�󥿡��ե������ؿ�(open)
 */
int open(const char *pathname, int flags)
{
	StorageDevice_t         *psdev;
	StorageDeviceFileFunc_t *pff;
	int             devno, id, no;

	if((devno = SDMGetDeviceNo(&pathname)) < 0)
		return -1;
	if((psdev = SDMGetStorageDevice(devno)) == 0)
		return -1;
	pff = psdev->pdevff;
	if(pff != 0 && pff->_sdevff_open == 0)
		return -1;

	wai_sem(SEM_STDFILE);
	for(no = 0 ; no < NUM_FILEIDX ; no++){
		if(stdfile[no].sdmfd == -1)
			break;
	}
	if(no >= NUM_FILEIDX){
		sig_sem(SEM_STDFILE);
		return -1;
	}

	id = pff->_sdevff_open(devno, pathname, flags);
	if(id < 0){
		sig_sem(SEM_STDFILE);
		return id;
	}
	stdfile[no].sdmfd  = id;
	stdfile[no].sdmdev = psdev;
	sig_sem(SEM_STDFILE);
	return no+1;
}

/*
 *  ɸ��ե����륤�󥿡��ե������ؿ�(close)
 */
int close(int fd)
{
	struct StdFileIndex *ps;
	StorageDevice_t     *psdev;
	int             result;

	if((ps = fdcheck(fd)) == 0)
		return -1;
	wai_sem(SEM_STDFILE);
	psdev = ps->sdmdev;
	if(psdev->pdevff != 0 && psdev->pdevff->_sdevff_close != 0)
		result = psdev->pdevff->_sdevff_close(ps->sdmfd);
	else
		result = -1;
	ps->sdmfd = -1;
	sig_sem(SEM_STDFILE);
	return result;
}

/*
 *  ɸ��ե����륤�󥿡��ե������ؿ�(fstat)
 */
int fstat(int fd, struct stat *buf)
{
	struct StdFileIndex *ps;
	StorageDevice_t     *psdev;

	if((ps = fdcheck(fd)) == 0)
		return -1;
	psdev = ps->sdmdev;
	if(psdev->pdevff != 0 && psdev->pdevff->_sdevff_fstat != 0)
		return psdev->pdevff->_sdevff_fstat(ps->sdmfd, buf);
	else
		return -1;
}

/*
 *  ɸ��ե����륤�󥿡��ե������ؿ�(lseek)
 */
off_t lseek(int fd, off_t offset, int whence)
{
	struct StdFileIndex *ps;
	StorageDevice_t     *psdev;
	int                 result;

	if((ps = fdcheck(fd)) == 0)
		return -1;
	psdev = ps->sdmdev;
	if(psdev->pdevff != 0 && psdev->pdevff->_sdevff_lseek != 0)
		return psdev->pdevff->_sdevff_lseek(ps->sdmfd, offset, whence, &result);
	else
		return -1;
}

/*
 *  ɸ��ե����륤�󥿡��ե������ؿ�(read)
 */
long read(int fd, void *buf, long count)
{
	struct StdFileIndex *ps;
	StorageDevice_t     *psdev;
	int                 result;

	if((ps = fdcheck(fd)) == 0)
		return -1;
	psdev = ps->sdmdev;
	if(psdev->pdevff != 0 && psdev->pdevff->_sdevff_read != 0)
		return psdev->pdevff->_sdevff_read(ps->sdmfd, buf, count, &result);
	else
		return 0;
}

/*
 *  ɸ��ե����륤�󥿡��ե������ؿ�(write)
 */
long write(int fd, const void *buf, long count)
{
	struct StdFileIndex *ps;
	StorageDevice_t     *psdev;
	int                 result;

	if((ps = fdcheck(fd)) == 0)
		return -1;
	psdev = ps->sdmdev;
	if(psdev->pdevff != 0 && psdev->pdevff->_sdevff_write != 0)
		return psdev->pdevff->_sdevff_write(ps->sdmfd, buf, count, &result);
	else
		return 0;
}

/*
 *  �ե�����ޥå״ؿ�(mmap)
 */
void *mmap(void *start, size_t length, int prot, int flags, int fd, off_t offset)
{
	struct StdFileIndex *ps;
	StorageDevice_t     *psdev;

	if((ps = fdcheck(fd)) == 0)
		return (void*)-1;
	psdev = ps->sdmdev;
	if(psdev->pdevff != 0 && psdev->pdevff->_sdevff_mmap != 0)
		return psdev->pdevff->_sdevff_mmap(start, length, prot, flags, ps->sdmfd, offset);
	else
		return (void*)-1;
}

/*
 *  �ե����륢��ޥå״ؿ�(̤����)
 */
int munmap(void *start, size_t length)
{
	return 0;
}

/*
 *  ɸ�������ѣ�ʸ������ʸ
 */
static int local_getc(void *st)
{
	StorageDevice_t     *psdev;
	int  result, res = 0;
	char buf[2];

	if(st == 0 && ((FILE *)st)->_file < 0)
		return -1;
	if((psdev = (StorageDevice_t *)((FILE*)st)->_dev) == 0)
		return -1;
	if(psdev->pdevff != 0 && psdev->pdevff->_sdevff_read != 0){
		result = psdev->pdevff->_sdevff_read(((FILE *)st)->_file, buf, 1, &res);
		if(res < 0)
			((FILE *)st)->_flags |= __SERR;
		if(result == 1)
			return buf[0];
		else
			return -1;
	}
	else
		return -1;
}

/*
 *  ɸ�������ѣ�ʸ������ʸ
 */
static int local_gets(void *st, unsigned int len, char *s)
{
	StorageDevice_t     *psdev;
	int result, res = 0;

	if(st == 0 && ((FILE *)st)->_file < 0)
		return -1;
	if((psdev = (StorageDevice_t *)((FILE*)st)->_dev) == 0)
		return -1;
	if(psdev->pdevff != 0 && psdev->pdevff->_sdevff_read != 0){
		result = psdev->pdevff->_sdevff_read(((FILE *)st)->_file, s, len, &res);
		if(res < 0)
			((FILE *)st)->_flags |= __SERR;
		return result;
	}
	else
		return 0;
}

/*
 *  ɸ��������ʸ������ʸ
 */
static void local_putc(void *st, int c)
{
	StorageDevice_t     *psdev;
	int  res = 0;
	char buf[2];

	if(st == 0 && ((FILE *)st)->_file < 0)
		return;
	if((psdev = (StorageDevice_t *)((FILE*)st)->_dev) == 0)
		return;
	buf[0] = c;
	if(psdev->pdevff != 0 && psdev->pdevff->_sdevff_write != 0){
		psdev->pdevff->_sdevff_write(((FILE *)st)->_file, buf, 1, &res);
		if(res < 0)
			((FILE *)st)->_flags |= __SERR;
	}
}

/*
 *  ɸ��������ʸ�������ʸ
 */
static int local_puts(void *st, unsigned int len, char *s)
{
	StorageDevice_t     *psdev;
	int result, res = 0;

	if(st == 0 && ((FILE *)st)->_file < 0)
		return -1;
	if((psdev = (StorageDevice_t *)((FILE*)st)->_dev) == 0)
		return -1;
	if(psdev->pdevff != 0 && psdev->pdevff->_sdevff_write != 0){
		result = psdev->pdevff->_sdevff_write(((FILE *)st)->_file, s, len, &res);
		if(res < 0)
			((FILE *)st)->_flags |= __SERR;
		return result;
	}
	else
		return 0;
}

/*
 *  ɸ�������ѥǡ����ե�å���ʸ
 */
static int local_flush(FILE *st)
{
	return 0;
}

/*
 *  �̾�ե����������
 */
int _setup_file(FILE *st, StorageDevice_t *pd, int lid)
{
	if(st == NULL)
		return 0;
	st->_file       = lid;
	st->_func_in    = local_getc;
	st->_func_ins   = local_gets;
	st->_func_out   = local_putc;
	st->_func_outs  = local_puts;
	st->_func_flush = local_flush;
	st->_dev        = pd;
	return 1;
}

/*
 *  ɸ�������ϥե����������
 */
int _setupstd_file(FILE *st, int fd)
{
	struct StdFileIndex *ps;

	if(st == NULL)
		return 0;

	st->_func_in    = local_getc;
	st->_func_ins   = local_gets;
	st->_func_out   = local_putc;
	st->_func_outs  = local_puts;
	st->_func_flush = local_flush;

	if((ps = fdcheck(fd)) == 0){
		st->_file = -1;
		st->_dev  = 0;
		return 0;
	}
	else{
		st->_file       = ps->sdmfd;
		st->_dev        = ps->sdmdev;
		return 1;
	}
}

