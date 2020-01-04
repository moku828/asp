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
 *  @(#) $Id: sdcard.h,v 1.0 2016/01/17 21:31:56 roi Exp $
 */
/*
 *  SH7262�� SDMMC�ɥ饤�Х��󥯥롼�ɥե�����
 */

#ifndef _SDMMC_H_
#define _SDMMC_H_

#ifdef __cplusplus
 extern "C" {
#endif


/*
 *  SD����������
 */
#if 1
#define INHNO_DMARX     DMAC0_DEI0_VECTOR	/* ����ߥϥ�ɥ��ֹ� */
#define INTNO_DMARX     DMAC0_DEI0_VECTOR	/* ������ֹ� */
#define INTPRI_DMARX    -6          /* �����ͥ���� */
#define INTATR_DMARX    0           /* �����°�� */
#define DMARX_SID       0
#else
#ifdef TOPPERS_STM32F769_DISCOVERY
#define INHNO_SDMMC     IRQ_VECTOR_SDMMC2	/* ����ߥϥ�ɥ��ֹ� */
#define INTNO_SDMMC     IRQ_VECTOR_SDMMC2	/* ������ֹ� */
#define INTPRI_SDMMC    -5          /* �����ͥ���� */
#define INTATR_SDMMC    TA_EDGE     /* �����°�� */

#define INHNO_DMARX     IRQ_VECTOR_DMA2_STREAM0	/* ����ߥϥ�ɥ��ֹ� */
#define INTNO_DMARX     IRQ_VECTOR_DMA2_STREAM0	/* ������ֹ� */
#define INTPRI_DMARX    -6          /* �����ͥ���� */
#define INTATR_DMARX    TA_EDGE     /* �����°�� */
#define DMARX_SID       DMA2STM0_SID

#define INHNO_DMATX     IRQ_VECTOR_DMA2_STREAM5	/* ����ߥϥ�ɥ��ֹ� */
#define INTNO_DMATX     IRQ_VECTOR_DMA2_STREAM5	/* ������ֹ� */
#define INTPRI_DMATX    -6          /* �����ͥ���� */
#define INTATR_DMATX    TA_EDGE     /* �����°�� */
#define DMATX_SID       DMA2STM5_SID
#else
#define INHNO_SDMMC     IRQ_VECTOR_SDMMC	/* ����ߥϥ�ɥ��ֹ� */
#define INTNO_SDMMC     IRQ_VECTOR_SDMMC	/* ������ֹ� */
#define INTPRI_SDMMC    -5          /* �����ͥ���� */
#define INTATR_SDMMC    TA_EDGE     /* �����°�� */

#define INHNO_DMARX     IRQ_VECTOR_DMA2_STREAM3	/* ����ߥϥ�ɥ��ֹ� */
#define INTNO_DMARX     IRQ_VECTOR_DMA2_STREAM3	/* ������ֹ� */
#define INTPRI_DMARX    -6          /* �����ͥ���� */
#define INTATR_DMARX    TA_EDGE     /* �����°�� */
#define DMARX_SID       DMA2STM3_SID

#define INHNO_DMATX     IRQ_VECTOR_DMA2_STREAM6	/* ����ߥϥ�ɥ��ֹ� */
#define INTNO_DMATX     IRQ_VECTOR_DMA2_STREAM6	/* ������ֹ� */
#define INTPRI_DMATX    -6          /* �����ͥ���� */
#define INTATR_DMATX    TA_EDGE     /* �����°�� */
#define DMATX_SID       DMA2STM6_SID
#endif
#endif


#define CMD_SHORTRESP       (1<<6)	/* short response */
#define CMD_LONGRESP        (1<<7)	/* long response */
#define CMD_SLONGRESP       (CMD_SHORTRESP|CMD_LONGRESP)
#define CMD_TIMEOUT         (1<<8)	/* timeout request bit */
#define CMD_SETLAST         (1<<10)
#define CMD_MASK            0xFFFF
#define CMD_IGNOREIRES      (1<<16)
#define CMD_INDEX           0x003F

/*
 *  SD/MMC ���ޥ�ɥꥹ��
 */
#if 1
#define MCI_CMD0			(0x0000|CMD_SHORTRESP)					/* GO_IDLE_STATE(SPI) */
#else
#define MCI_CMD0			(0x0000)								/* GO_IDLE_STATE(MMC) or RESET(SD) */
#endif
#define MCI_CMD1			(0x0001|CMD_SHORTRESP|CMD_IGNOREIRES)	/* SEND_OP_COND(MMC) or CMD1(SD) */
#define MCI_CMD2			(0x0002|CMD_SLONGRESP|CMD_IGNOREIRES)	/* ALL SEND_CID */
#define MCI_CMD3			(0x0003|CMD_SHORTRESP)					/* SET_RELATE_ADDR */
#define MCI_CMD6			(0x0006|CMD_SHORTRESP)
#define MCI_CMD7			(0x0007|CMD_SHORTRESP)					/* SELECT/DESELECT_CARD */
#define MCI_CMD8            (0x0008|CMD_SHORTRESP)					/* HS_SEND_EXT_CSD */
#define MCI_CMD9			(0x0009|CMD_SLONGRESP|CMD_IGNOREIRES)	/* SEND_CSD */
#define MCI_CMD12			(0x000C|CMD_SHORTRESP)					/* Stop either READ or WRITE operation */
#define MCI_CMD13			(0x000D|CMD_SHORTRESP)					/* SEND_STATUS */
#define MCI_CMD16			(0x0010|CMD_SHORTRESP)					/* SET_BLOCK_LEN */
#define MCI_CMD17			(0x0011|CMD_SHORTRESP)					/* READ_SINGLE_BLOCK */
#define MCI_CMD18			(0x0012|CMD_SHORTRESP)					/* READ_MULTI_BLOCK */
#define MCI_CMD24			(0x0018|CMD_SHORTRESP)					/* WRITE_SINGLE_BLOCK */
#define MCI_CMD25			(0x0019|CMD_SHORTRESP)					/* WRITE_MULTI_BLOCK */
#define MCI_CMD32			(0x0020|CMD_SHORTRESP)					/* ERASE_GRP_START */
#define MCI_CMD33			(0x0021|CMD_SHORTRESP)					/* ERASE_GRP_END */
#define MCI_CMD38			(0x0026|CMD_SHORTRESP)					/* ERASE */
#define MCI_CMD55			(0x0037|CMD_SHORTRESP)					/* APP_CMD, the following will a ACMD */
#if 1
#define MCI_CMD58			(0x003A|CMD_SHORTRESP)					/* READ_OCR */
#endif

#define MCI_ACMD6			(0x0006|CMD_SHORTRESP)					/* ACMD6 for SD card BUSWIDTH */
#define MCI_ACMD13			(0x000D|CMD_SHORTRESP)					/* ACMD23 for SD card status */
#define MCI_ACMD41			(0x0029|CMD_SHORTRESP|CMD_IGNOREIRES)	/* ACMD41 for SD card */
#define MCI_ACMD51			(0x0033|CMD_SHORTRESP)					/* ACMD41 for SD SCR */

#define RES_CMD1            (MCI_CMD1 & CMD_INDEX)
#define RES_CMD12           (MCI_CMD12 & CMD_INDEX)
#define RES_ACMD41          (MCI_ACMD41 & CMD_INDEX)

#define OCR_INDEX			0x00FF8000

#define CARD_STATUS_ACMD_ENABLE		(1<<5)
#define CARD_STATUS_RDY_DATA		(1<<8)
#define CARD_STATUS_CURRENT_STATE	(0x0F<<9)
#define CARD_STATUS_ERASE_RESET		(1<<13)

#define SLOW_RATE			1
#define NORMAL_RATE			2

#define SD_1_BIT 			0
#define SD_4_BIT			1

#define SD_CARD_V11         0
#define SD_CARD_V20         1
#define SD_CARD_HC          2
#define MMC_CARD			3
#define SD_IO_CARD          4
#define HS_MM_CARD          5
#define SD_IO_COMBO_CARD    6
#define MMC_CARD_HC         7


#define MCI_NOTEND          0
#define MCI_END             1
#define MCI_ERREND          2

#define SDMODE_PROTECT      (1<<5)

/*
 *  SDMMC��ĥ���顼���
 */
#define E_SDCOM             (-80)	/* ���ޥ�ɥ��顼 */
#define E_SDCRC             (-81)	/* CRC���顼 */
#define E_SDECMD            (-82)	/* ���ޥ�ɥ���ǥå������顼 */
#define E_SDVOL             (-83)	/* �Ű����顼 */
#define E_SDTRS             (-84)	/* �̿����顼 */

/*
 *  ������ž���������
 */
#define SD_TRANSFER_OK      0	/* ž������ */
#define SD_TRANSFER_BUSY    1	/* ž���� */
#define SD_TRANSFER_ERROR   2	/* ž�����顼 */


/*
 *  �Х������
 */
#define SDMMC_BUS_WIDE_1B   0x00000000
#define SDMMC_BUS_WIDE_4B   SDMMC_CLKCR_WIDBUS_0
#define SDMMC_BUS_WIDE_8B   SDMMC_CLKCR_WIDBUS_1


/*
 *  SDMMC�ѥǡ����֥�å����������
 */
#define SDMMC_DBSIZE_1B     0x00000000
#define SDMMC_DBSIZE_2B     SDMMC_DCTRL_DBLOCKSIZE_0
#define SDMMC_DBSIZE_4B     SDMMC_DCTRL_DBLOCKSIZE_1
#define SDMMC_DBSIZE_8B     (SDMMC_DCTRL_DBLOCKSIZE_0|SDMMC_DCTRL_DBLOCKSIZE_1)
#define SDMMC_DBSIZE_16B    SDMMC_DCTRL_DBLOCKSIZE_2
#define SDMMC_DBSIZE_32B    (SDMMC_DCTRL_DBLOCKSIZE_0|SDMMC_DCTRL_DBLOCKSIZE_2)
#define SDMMC_DBSIZE_64B    (SDMMC_DCTRL_DBLOCKSIZE_1|SDMMC_DCTRL_DBLOCKSIZE_2)
#define SDMMC_DBSIZE_128B   (SDMMC_DCTRL_DBLOCKSIZE_0|SDMMC_DCTRL_DBLOCKSIZE_1|SDMMC_DCTRL_DBLOCKSIZE_2)
#define SDMMC_DBSIZE_256B   SDMMC_DCTRL_DBLOCKSIZE_3
#define SDMMC_DBSIZE_512B   (SDMMC_DCTRL_DBLOCKSIZE_0|SDMMC_DCTRL_DBLOCKSIZE_3)
#define SDMMC_DBSIZE_1024B  (SDMMC_DCTRL_DBLOCKSIZE_1|SDMMC_DCTRL_DBLOCKSIZE_3)
#define SDMMC_DBSIZE_2048B  (SDMMC_DCTRL_DBLOCKSIZE_0|SDMMC_DCTRL_DBLOCKSIZE_1|SDMMC_DCTRL_DBLOCKSIZE_3) 
#define SDMMC_DBSIZE_4096B  (SDMMC_DCTRL_DBLOCKSIZE_2|SDMMC_DCTRL_DBLOCKSIZE_3)
#define SDMMC_DBSIZE_8192B  (SDMMC_DCTRL_DBLOCKSIZE_0|SDMMC_DCTRL_DBLOCKSIZE_2|SDMMC_DCTRL_DBLOCKSIZE_3)
#define SDMMC_DBSIZE_16384B (SDMMC_DCTRL_DBLOCKSIZE_1|SDMMC_DCTRL_DBLOCKSIZE_2|SDMMC_DCTRL_DBLOCKSIZE_3)

/*
 *  SDMMC���������ȿ�
 */
#define SDMMC_INIT_CLK_DIV  0x76

/*
 *  SDMMC�ǡ���ž���Ѽ��ȿ�
 */
#define SDMMC_TRANSFER_CLK_DIV 0x0


/*
 *  SDMMC�ϥ�ɥ鹽¤�����
 */

typedef struct
{
	uint32_t                base;		/* SDMMC�쥸�����١������ɥ쥹 */
	uint32_t                ClockMode;	/* ���ꥯ��å��⡼�� */
	uint32_t                BusWide;	/* ����Х��� */
	uint32_t                RetryCount;	/* ��ȥ饤��� */
	uint32_t                cardtype;	/* �����ɥ����� */
	uint32_t                OCR;		/* OCR�� */
	uint32_t                RCA;		/* RCA�� */
	uint32_t                CSD[4];		/* CSD�� */
	uint32_t                CID[4];		/* CID�� */
	volatile uint32_t       status;		/* ž������ */
	volatile uint32_t       SdCmd;		/* ž�����ꥳ�ޥ�� */
	uint8_t                 R1;			/* R1�쥹�ݥ� */
#if 0
	DMA_Handle_t            *hdmarx;	/* ������DMA�ϥ�ɥ� */
	DMA_Handle_t            *hdmatx;	/* ������DMA�ϥ�ɥ� */
#endif
}SDMMC_Handle_t;

/*
 *  SDMMC�����ɾ���¤��
 */
typedef struct
{
	uint64_t                capacity;	/* ����(�Х���) */
	uint32_t                blocksize;	/* �֥�å������� */
	uint32_t                maxsector;	/* ���祻������ */
	uint16_t                RCA;		/* SD RCA */
	uint8_t                 cardtype;	/* �����ɼ��� */
	uint8_t                 status;		/* ���ơ����� */

}SDMMC_CardInfo_t;


/*
 *  CMD13�����ɾ���
 */
#define SD_CARD_READY           0x00000001	/* �����ɥ�ǥ����� */
#define SD_CARD_IDENTIFICATION	0x00000002	/* �����ɥ����ǥ�ƥ��ե������������� */
#define SD_CARD_STANDBY         0x00000003	/* �����ɥ�����Х����� */
#define SD_CARD_TRANSFER        0x00000004	/* ������ž������ */
#define SD_CARD_SENDING         0x00000005	/* �������������� */
#define SD_CARD_RECEIVING       0x00000006	/* �����ɼ������� */
#define SD_CARD_PROGRAMMING     0x00000007	/* �����ɥץ���ߥ󥰾��� */
#define SD_CARD_DISCONNECTED    0x00000008	/* �����ɥǥ������ͥ��Ⱦ��� */
#define SD_CARD_ERROR           0x000000FF	/* �����ɥ��顼���� */


extern void sdmmc_init(intptr_t exinf);
extern bool_t sdmmc_sense(int id);
extern SDMMC_Handle_t *sdmmc_open(int id);
extern ER sdmmc_close(SDMMC_Handle_t *hsd);
extern ER sdmmc_erase(SDMMC_Handle_t *hsd, uint64_t startaddr, uint64_t endaddr);
extern ER sdmmc_blockread(SDMMC_Handle_t *hsd, uint8_t *pbuf, uint64_t ReadAddr, uint32_t blocksize, uint32_t num);
extern ER sdmmc_blockwrite(SDMMC_Handle_t *hsd, uint8_t *pbuf, uint64_t WriteAddr, uint32_t blocksize, uint32_t num);
extern ER sdmmc_wait_transfar(SDMMC_Handle_t *hsd, uint32_t Timeout);
extern void sdmmc_checkint(SDMMC_Handle_t *hsd);

extern ER sdmmc_getcardinfo(SDMMC_Handle_t *hsd, SDMMC_CardInfo_t *pCardInfo);
extern ER sdmmc_checkCID(SDMMC_Handle_t *hsd);
extern ER sdmmc_setaddress(SDMMC_Handle_t *hsd);
extern ER sdmmc_sendCSD(SDMMC_Handle_t *hsd);
extern ER sdmmc_select_card(SDMMC_Handle_t *hsd, uint64_t addr);
extern ER sdmmc_configuration(SDMMC_Handle_t *hsd);
extern ER sdmmc_set_widebus(SDMMC_Handle_t *hsd);
extern uint32_t sdmmc_getstatus(SDMMC_Handle_t *hsd);

extern void stream_dma_isr(intptr_t exinf);


#ifdef __cplusplus
}
#endif


#endif /* _SDMMC_H_ */

