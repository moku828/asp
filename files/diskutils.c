/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2010-2015 by GJ Designing Center RICOH COMPANY,LTD. JAPAN
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
 *  @(#) $Id: diskutils.c,v 2.0 2015/05/01 07:32:56 roi Exp $
 */

#include <stdio.h>
#include <string.h>
#include "storagedevice.h"
//#include "monitor.h"

#define NUM_VOLUME_CMD      5

static int_t volume_format(int argc, char **argv);
static int_t volume_dir(int argc, char **argv);
static int_t volume_mkdir(int argc, char **argv);
static int_t volume_rmdir(int argc, char **argv);
static int_t volume_delete(int argc, char **argv);

/*
 *  VOLUME���ޥ�ɥơ��֥�
 */
static const COMMAND_INFO volume_command_info[] = {
	{"FORMAT",		volume_format },	/* �ܥ�塼��ե����ޥå� */
	{"DIR",			volume_dir    },	/* �ǥ��쥯�ȥ�ɽ�� */
	{"MKDIR",		volume_mkdir  },	/* �ǥ��쥯�ȥ���� */
	{"RMDIR",		volume_rmdir  },	/* �ǥ��쥯�ȥ��� */
	{"ERASE",		volume_delete }		/* �ե������� */
};

static const char volume_name[] = "VOLUME";
static const char volume_help[] =
"  Volume  FORMAT   [drive]\n"
"          DIR      [path] \n"
"          MKDIR    [path] \n"
"          RMDIR    [path] \n"
"          ERASE    [path] \n";

static COMMAND_LINK volume_command_link = {
	NULL,
	NUM_VOLUME_CMD,
	volume_name,
	NULL,
	volume_help,
	&volume_command_info[0]
};

static struct dirent2 finfo;

/*
 *  RTC���ޥ������ؿ�
 */
void volume_info_init(intptr_t exinf)
{
	setup_command(&volume_command_link);
}

/*
 *  ���ȥ졼���ܥ�塼��ե����ޥå�
 */
static int_t
volume_format(int argc, char **argv)
{
	printf("not support !\n");
	return 0;
}

/*
 *  ���ȥ졼���ܥ�塼��ǥ��쥯�ȥ�
 */
static int_t
volume_dir(int argc, char **argv)
{
	StorageDevice_t *psdev;
	struct statfs2  status;
	char   *path, *spath, name[16];
	int    devno, no, count;
	void   *dir;

	name[0] = 0;
	if(argc > 1)
		spath = path = argv[1];
	else
		spath = path = &name[1];
	devno = SDMGetDeviceNo((const char **)&path);
	psdev = SDMGetStorageDevice(devno);
	if(psdev == 0){
		printf("\nno device !\n");
		return -1;
	}
	if(psdev->pdevff == 0 || psdev->pdevff->_sdevff_opendir == 0){
		printf("\nno function !\n");
		return -1;
	}
	if((psdev->_sdev_attribute & SDEV_EMPLOY) == 0){
		printf("\nno media !\n");
		return -1;
	}
	count = 0;
	dir = psdev->pdevff->_sdevff_opendir(spath);
	if(dir != NULL){
		if(*spath == 0){
			name[0] = devno + '0';
			name[1] = ':';
			name[2] = '/';
			name[3] = 0;
			spath = name;
		}
		printf("\nDirectory [%s]\n", spath);
		while(psdev->pdevff->_sdevff_readdir(dir, &finfo) != 0 && finfo.d_name[0] != 0){
			count++;
			printf("%3d %s ", count, finfo.d_name);
			no = strlen(finfo.d_name);
			while(no < 24){
				putchar(' ');
				no++;
			}
			printf("%04d/%02d/%02d ", (finfo.d_date>>9)+1980, (finfo.d_date>>5) & 15, finfo.d_date & 31);
			printf("%02d:%02d:%02d ", finfo.d_time>>11, (finfo.d_time>>5) & 63, (finfo.d_time & 31)*2);
			if(finfo.d_type & AM_HID)
				name[0] = '*';
			else
				name[0] = ' ';
			if(finfo.d_type & AM_SYS)
				name[1] = 'S';
			else
				name[1] = ' ';
			name[2] = 'R';
			if(finfo.d_type & AM_RDO)
				name[3] = ' ';
			else
				name[3] = 'W';
			name[4] = 0;
			if(finfo.d_type & AM_DIR)
				printf("<DIR>  \n");
			else if(finfo.d_type & AM_VOL)
				printf("<VOL>  \n");
			else
				printf("[%s]  %8d\n", name, (int)finfo.d_fsize);
		}
		printf("     %d file(s)\n", count);
		psdev->pdevff->_sdevff_closedir(dir);
		if(psdev->pdevff->_sdevff_statfs != 0
			 && psdev->pdevff->_sdevff_statfs(spath, &status) == 0){
			printf("     %d free blocks %d bytes in a block\n", (int)status.f_bfree, (int)status.f_bsize);
		}
	}
	else{
		printf("Disk Error !\n");
	}
	return 0;
}

/*
 *  ���ȥ졼���ܥ�塼��MKDIR
 */
static int_t
volume_mkdir(int argc, char **argv)
{
	StorageDevice_t *psdev;
	char   *path, *spath;
	int    devno;

	if(argc > 1){
		spath = path = argv[1];
		devno = SDMGetDeviceNo((const char **)&path);
		psdev = SDMGetStorageDevice(devno);
		if(psdev == 0){
			printf("\nno device !\n");
			return -1;
		}
		if(psdev->pdevff == 0 || psdev->pdevff->_sdevff_mkdir == 0){
			printf("\nno function !\n");
			return -1;
		}
		printf(" mkdir[%s]\n", path);
		if(psdev->pdevff->_sdevff_mkdir(spath) >= 0)
			printf("   Ok\n");
		else
			printf("   Error\n");
	}
	return 0;
}

/*
 *  ���ȥ졼���ܥ�塼��RMDIR
 */
static int_t
volume_rmdir(int argc, char **argv)
{
	StorageDevice_t *psdev;
	char   *path, *spath;
	int    devno;

	if(argc > 1){
		spath = path = argv[1];
		devno = SDMGetDeviceNo((const char **)&path);
		psdev = SDMGetStorageDevice(devno);
		if(psdev == 0){
			printf("\nno device !\n");
			return -1;
		}
		if(psdev->pdevff == 0 || psdev->pdevff->_sdevff_rmdir == 0){
			printf("\nno function !\n");
			return -1;
		}
		printf(" rmdir[%s]\n", path);
		if(psdev->pdevff->_sdevff_rmdir(spath) >= 0)
			printf("   Ok\n");
		else
			printf("   Error\n");
	}
	return 0;
}

/*
 *  ���ȥ졼���ܥ�塼��ե�������
 */
static int_t
volume_delete(int argc, char **argv)
{
	StorageDevice_t *psdev;
	char   *path, *spath;
	int    devno;

	if(argc > 1){
		spath = path = argv[1];
		devno = SDMGetDeviceNo((const char **)&path);
		psdev = SDMGetStorageDevice(devno);
		if(psdev == 0){
			printf("\nno device !\n");
			return -1;
		}
		if(psdev->pdevff == 0 || psdev->pdevff->_sdevff_unlink == 0){
			printf("\nno function !\n");
			return -1;
		}
		printf(" unlink[%s]\n", path);
		if(psdev->pdevff->_sdevff_unlink(spath) >= 0)
			printf("   Ok\n");
		else
			printf("   Error\n");
	}
	return 0;
}

