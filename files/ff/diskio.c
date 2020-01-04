/*
 *  FatFs for TOPPERS
 *      FAT File system/
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2005- by Industrial Technology Institute,
 *                          Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2007-2010 by 
 *                     GJ Business Division RICOH COMPANY,LTD. JAPAN
 *  Copyright (C) 2015-2017 by TOPPERS PROJECT Educational Group.
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
 *  @(#) $Id: diskio.c,v 1.3 2017/07/06 16:24:36 roi Exp $
 */

/*
 *  FatFs�����ꤷ�Ƥ��벼�̥쥤��I/F
 *  �������ʣ���ɥ饤�֤��б����٤����������Υ������åȥܡ��ɤǤ�
 *  ���ɥ饤�֤ϣ��ĤΤߥ��ݡ��Ȥ��Ƥ��롣
 */

#include "kernel_impl.h"
#include <string.h>	/*  memcpy()  */
#include <t_syslog.h>
#include <t_stdlib.h>
#include "storagedevice.h"
#include "diskio.h"

#define RETRY_COUNT    8

/*
 *  �ǥ��������ɥ饤�֤ν����
 *��������
 *������ BYTE Drive	ʪ���ɥ饤���ֹ�
 */
DSTATUS
disk_initialize(BYTE Drive)
{
	StorageDevice_t *psdev = SDMGetStorageDevice(Drive);

	if(psdev == NULL || psdev->pdevf == NULL || psdev->pdevf->_sdevf_diskinit == NULL)
		return STA_NODISK;
	return psdev->pdevf->_sdevf_diskinit(psdev);
}


/*
 *  �ǥ��������ɥ饤�֤ξ��ּ���
 *��������
 *������ BYTE Drive	ʪ���ɥ饤���ֹ�
 */
DSTATUS
disk_status(BYTE Drive)
{
	StorageDevice_t *psdev = SDMGetStorageDevice(Drive);

	if(psdev == NULL || psdev->pdevf == NULL || psdev->pdevf->_sdevf_diskstatus == NULL)
		return STA_NODISK;
	return psdev->pdevf->_sdevf_diskstatus(psdev);
}


/*
 *  �ǥ�����������ɤ߹���
 *��������
 *������ BYTE Drive����������ʪ���ɥ饤���ֹ�
 *������ BYTE* Buffer        �ɤ߽Ф��Хåե��ؤΥݥ���
 *������ DWORD SectorNumber  �ɤ߽Ф����ϥ������ֹ�
 *������ BYTE SectorCount    �ɤ߽Ф���������
 */
DRESULT
disk_read(BYTE Drive, BYTE* Buffer, DWORD SectorNumber, BYTE SectorCount)
{
	StorageDevice_t *psdev = SDMGetStorageDevice(Drive);

	if(psdev == NULL || psdev->pdevf == NULL || psdev->pdevf->_sdevf_diskread == NULL)
		return RES_ERROR;
	return psdev->pdevf->_sdevf_diskread(psdev, Buffer, SectorNumber, SectorCount);
}

/*
 *  �ǥ������ؤν񤭹���
 *��������
 *������ BYTE Drive����������ʪ���ɥ饤���ֹ�
 *������ BYTE* Buffer        �񤭹���ǡ����ؤΥݥ���
 *������ DWORD SectorNumber  �񤭹��߳��ϥ������ֹ�
 *������ BYTE SectorCount    �񤭹��ߥ�������
 */
DRESULT
disk_write(BYTE Drive, const BYTE* Buffer, DWORD SectorNumber, BYTE SectorCount)
{
	StorageDevice_t *psdev = SDMGetStorageDevice(Drive);

	if(psdev == NULL || psdev->pdevf == NULL || psdev->pdevf->_sdevf_diskwrite == NULL)
		return RES_ERROR;
	return psdev->pdevf->_sdevf_diskwrite(psdev, Buffer, SectorNumber, SectorCount);
}

DRESULT
disk_ioctl(BYTE Drive, BYTE Func, void* Buffer)
{
	StorageDevice_t *psdev = SDMGetStorageDevice(Drive);

	if(psdev == NULL || psdev->pdevf == NULL || psdev->pdevf->_sdevf_diskioctl == NULL)
		return RES_ERROR;
	return psdev->pdevf->_sdevf_diskioctl(psdev, Func, Buffer);
}

/*
 *  ���ա�����μ���
 *  ����ToDo��̤����
 */
DWORD
get_fattime(void)
{
	SYSTIM systim;
	DWORD  fdate = ((2017-1980)<<25)+(1<<21)+(1<<16);
	DWORD  ftime;

	if(SDeviceHead._get_datetime != 0)
		return (DWORD)SDeviceHead._get_datetime();
	else{
		get_tim(&systim);
		systim = (systim+1000L) /2000L;
		ftime  = systim % 30;
		ftime += ((systim/30) % 60)<<5;
		ftime += ((systim/(60*30))<<11);
		return (fdate+ftime);
	}
}

