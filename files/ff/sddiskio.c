/*
 *  TOPPERS/JSP/ASP/FMP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
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
 *  @(#) $Id: sddickio.c,v 1.3 2018/06/25 18:16:40 roi Exp $
 */

/*
 * ���Υץ�����ITRON���Ѥ�FF�ɥ饤�С����եȥ������Ǥ��롣
 * �ӣĥ��������ѥ��ȥ졼���ؿ��򥵥ݡ��Ȥ���
 * ����Ū�ʥ��ȥ졼���ؿ����Ǥ��ꡢɸ��饤�֥�ꥣ��ʬ���Ƥλ��Ѥ�˾�ޤ�����
 * 1. sd_init                  ���δؿ����ν�����ؿ�(bss����������ξ�礳�δؿ�������)
 * 2. sdcard_sense             SD-CARD�Υ��󥹤�Ԥ�
 * 3. sdcard_diskstatus        SD-CARD�Υ��ơ���������:�ʤ�
 * 4. sdcard_diskread          SD-CARD���ɤ߹���:�ʤ�
 * 5. sdcard_diskwrite         SD-CARD�ν񤭹���:�ʤ�
 * 6. sdcard_iocil             SD-CARD��IO����:�ʤ�
 *
 */

#include "kernel_impl.h"
#include <stdlib.h>
#include <string.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "fcntl.h"
//#include "device.h"
#include "mcicmd.h"
#include "storagedevice.h"
#include "ff.h"
#include "diskio.h"
#include "sddiskio.h"

static int sdcard_sense(void *psdev, BOOL on);
static int sdcard_diskstatus(void *psdev);
static int sdcard_diskread(void *pif, BYTE *Buffer, DWORD SectorNumber, BYTE SectorCount);
static int sdcard_diskwrite(void *pif, const BYTE *Buffer, DWORD SectorNumber, BYTE SectorCount);
static int sdcard_diskioctl(void *pif, BYTE Func, void* Buffer);

static const StorageDeviceFunc_t fatfsSDeviceFunc = {
	sdcard_sense,
	sdcard_diskstatus,
	sdcard_diskstatus,
	(int (*)())sdcard_diskread,
	(int (*)())sdcard_diskwrite,
	(int (*)())sdcard_diskioctl
};

static MCIINFO SDCardInfo;
static FATFS ActiveFatFsObj __attribute__ ((aligned (32)));

#ifdef DMA_ALINE
static unsigned int abuff[512/sizeof(unsigned int)];

static void mem_cpy(unsigned char *d, unsigned char *s, int len)
{
	while(len > 0){
		*d++ = *s++;
		len--;
	}
}
#endif

/*
 *  FatFs��SD�����ɥե�����ɥ饤�Фν����
 */
void sd_init(intptr_t exinf)
{
	StorageDevice_t *psdev;

	SDMSetupDevice(SDCARD_DEVNO, &psdev);
	psdev->pdevf            = (StorageDeviceFunc_t *)&fatfsSDeviceFunc;
	psdev->pdevff           = (StorageDeviceFileFunc_t *)&fatfsSDeviceFileFunc;
	psdev->_sdev_secsize    = 512;
	psdev->_sdev_port       = SDCRAD_PORTID;
#ifdef SDEV_INSWAIT_TIME
	psdev->_sdev_inswait    = SDEV_INSWAIT_TIME;
#else
	psdev->_sdev_inswait    = 0;
#endif
	psdev->_sdev_attribute |= SDEV_INSERTCHK|SDEV_CHKREMOVE;
	psdev->_sdev_local[0]   = &ActiveFatFsObj;
}

/*
 *  SDCARD���󥹴ؿ�
 */
static int sdcard_sense(void *pif, BOOL on)
{
	StorageDevice_t *psdev = pif;
	bool_t   exist = mci_ses_por(((StorageDevice_t *)psdev)->_sdev_port);
	MCIPCB   *pmci;
	int      result = FR_DISK_ERR;

	pmci = psdev->_sdev_local[1];
	if(on && !exist){
		f_mount(psdev->_sdev_devno, 0);
		psdev->_sdev_attribute &= ~SDEV_DEVERROR;
		mci_cls_por(pmci);
		return TRUE;
	}
	else if(!on && exist){
		psdev->_sdev_instimer += SENSE_TIME;
		if((psdev->_sdev_attribute & SDEV_ONEEXIT) != 0 && psdev->_sdev_instimer < psdev->_sdev_inswait)
			return FALSE;
		pmci = mci_opn_por(((StorageDevice_t *)psdev)->_sdev_port);
		if(pmci == NULL)
			return FALSE;
		psdev->_sdev_local[1] = pmci;
		if(MciCheckCID(pmci) != E_OK){
			psdev->_sdev_attribute |= SDEV_DEVERROR;
			return TRUE;
		}
		if(MciSetAddress(pmci) != E_OK){
			psdev->_sdev_attribute |= SDEV_DEVERROR;
			return TRUE;
		}
		if(MciSendCID(pmci) != E_OK){
			psdev->_sdev_attribute |= SDEV_DEVERROR;
			return TRUE;
		}
		if(MciGetCardInfo(pmci, &SDCardInfo) != E_OK)
			psdev->_sdev_attribute |= SDEV_DEVERROR;
		else{
			psdev->_sdev_maxsec = SDCardInfo.maxsector;
			if(MciSelectCard(pmci, (((uint32_t)SDCardInfo.RCA) << 16)) != E_OK)
				psdev->_sdev_attribute |= SDEV_DEVERROR;
		}
		if(MciConfiguration(pmci) != E_OK)
			psdev->_sdev_attribute |= SDEV_DEVERROR;
		if(MciSetWideBus(pmci) != E_OK)
			psdev->_sdev_attribute |= SDEV_DEVERROR;
		if((psdev->_sdev_attribute & SDEV_DEVERROR) == 0)
			result = f_mount(psdev->_sdev_devno, &ActiveFatFsObj);
		if(result != FR_OK)
			psdev->_sdev_attribute |= SDEV_DEVERROR;
		else
			psdev->_sdev_local[0]   = &ActiveFatFsObj;
#if 1
		syslog_3(LOG_NOTICE, "## attr[%04x] max(%d) result(%d) ##", psdev->_sdev_attribute, psdev->_sdev_maxsec, result);
#endif
		return TRUE;
	}
	else
		return FALSE;
}

/*
 *  FatFs��SDCARD���ơ������ؿ�
 */
static int sdcard_diskstatus(void *pif)
{
	StorageDevice_t *psdev = pif;
	MCIPCB          *pmci;

	if(psdev == NULL)
		return STA_NODISK;
	pmci = psdev->_sdev_local[1];
	if((psdev->_sdev_attribute & (SDEV_EMPLOY|SDEV_NOTUSE)) != SDEV_EMPLOY || pmci == NULL)
		return STA_NOINIT;
	else if((pmci->status & SDMODE_PROTECT) != 0)
		return STA_PROTECT;
	else
		return 0;
}

/*
 *  FatFs��SDCARD�ɤ߹��ߴؿ�
 */
static int sdcard_diskread(void *pif, BYTE *Buffer, DWORD SectorNumber, BYTE SectorCount)
{
 	StorageDevice_t *psdev = pif;
	MCIPCB          *pmci;
	ER              ercd = E_OK;
	int             retry = 0;
#ifdef DMA_ALINE
	unsigned int    align = ((unsigned int)Buffer) & 3;
	int             i;
#endif

	pmci = psdev->_sdev_local[1];
	if((psdev->_sdev_attribute & (SDEV_EMPLOY|SDEV_NOTUSE)) != SDEV_EMPLOY || pmci == NULL)
		return RES_ERROR;
#ifndef DMA_ALINE
	do{
		ercd = mci_red_blk(pmci, Buffer, SectorNumber * psdev->_sdev_secsize, psdev->_sdev_secsize, SectorCount);
		if(ercd == E_OK)
			ercd = mci_wai_trn(pmci, 30*1000);
		retry++;
	}while(ercd != E_OK && retry < RETRY_COUNT);
#else
	if(align == 0){
		do{
			ercd = mci_red_blk(pmci, Buffer, SectorNumber * psdev->_sdev_secsize, psdev->_sdev_secsize, SectorCount);
			if(ercd == E_OK)
				ercd = mci_wai_trn(pmci, 30*1000);
			retry++;
		}while(ercd != E_OK && retry < RETRY_COUNT);
	}
	else{
		for(i = 0 ; i < SectorCount ; i++, SectorNumber++, Buffer += psdev->_sdev_secsize){
			do{
				ercd = mci_red_blk(pmci, abuff, SectorNumber * psdev->_sdev_secsize, psdev->_sdev_secsize, 1);
				if(ercd == E_OK)
					ercd = mci_wai_trn(pmci, 30*1000);
				retry++;
			}while(ercd != E_OK && retry < RETRY_COUNT);
			mem_cpy(Buffer, abuff, psdev->_sdev_secsize);
		}
	}
#endif
	if(ercd == E_OK)
		return RES_OK;
	else
		return RES_ERROR;
}

/*
 *  FatFs��SDCARD�񤭹��ߴؿ�
 */
static int sdcard_diskwrite(void *pif, const BYTE *Buffer, DWORD SectorNumber, BYTE SectorCount)
{
	StorageDevice_t *psdev = pif;
	MCIPCB          *pmci;
	ER              ercd = E_OK;
	int             retry = 0;
#ifdef DMA_ALINE
	unsigned int    align = ((unsigned int)Buffer) & 3;
	int             i;
#endif

	pmci = psdev->_sdev_local[1];
	if((psdev->_sdev_attribute & (SDEV_EMPLOY|SDEV_NOTUSE)) != SDEV_EMPLOY || pmci == NULL)
		return RES_ERROR;
#ifndef DMA_ALINE
	do{
		ercd = mci_wri_blk(pmci, (void *)Buffer, SectorNumber * psdev->_sdev_secsize, psdev->_sdev_secsize, SectorCount);
		if(ercd == E_OK)
			ercd = mci_wai_trn(pmci, 30*1000);
		retry++;
	}while(ercd != E_OK && retry < RETRY_COUNT);
#else
	if(align == 0){
		do{
			ercd = mci_wri_blk(pmci, (void *)Buffer, SectorNumber * psdev->_sdev_secsize, psdev->_sdev_secsize, SectorCount);
			if(ercd == E_OK)
				ercd = mci_wai_trn(pmci, 30*1000);
			retry++;
		}while(ercd != E_OK && retry < RETRY_COUNT);
	}
	else{
		for(i = 0 ; i < SectorCount ; i++, SectorNumber++, Buffer += psdev->_sdev_secsize){
			mem_cpy(abuff, Buffer, psdev->_sdev_secsize);
			do{
				ercd = mci_wri_blk(pmci, (void *)abuff, SectorNumber * psdev->_sdev_secsize, psdev->_sdev_secsize, 1);
				if(ercd == E_OK)
					ercd = mci_wai_trn(pmci, 30*1000);
				retry++;
			}while(ercd != E_OK && retry < RETRY_COUNT);
		}
	}
#endif
	if(ercd == E_OK)
		return RES_OK;
	else
		return RES_ERROR;
}


/*
 *  FatFs��SDCARDIO����ؿ�
 */
static int sdcard_diskioctl(void *pif, BYTE Func, void* Buffer)
{
	StorageDevice_t *psdev = (StorageDevice_t *)pif;
	DRESULT         result;

	if(psdev == NULL)
		return RES_ERROR;
	if((psdev->_sdev_attribute & (SDEV_EMPLOY|SDEV_NOTUSE)) != SDEV_EMPLOY)
		return RES_ERROR;
	switch(Func){
	case CTRL_SYNC:
		result = RES_OK;			/* no action */
		break;
	case GET_SECTOR_COUNT:
		*((DWORD *)Buffer) = psdev->_sdev_maxsec;
		syslog_2(LOG_NOTICE, "ioctl notuse (%d)(%d) ", (int)Func, psdev->_sdev_maxsec);
		result = RES_OK;
		break;
	case GET_BLOCK_SIZE:
		*((DWORD *)Buffer) = 135;	/* ERASE_BLK */
		syslog_1(LOG_NOTICE, "call disk_ioctl(GET_BLOCK_SIZE, %08x)", (int)(*((DWORD *)Buffer)));
		result = RES_OK;
		break;
	default:
		syslog_2(LOG_NOTICE, "call disk_ioctl(%d, %08x)", (int)psdev->_sdev_devno, (int)Buffer);
		slp_tsk();
		result = RES_PARERR;
		break;
	}
	return result;
}

