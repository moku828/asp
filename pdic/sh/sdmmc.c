/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2015-2016 by TOPPERS PROJECT Educational Working Group.
 * 
 *  上記著作権者は，以下の (1)〜(4) の条件か，Free Software Foundation 
 *  によって公表されている GNU General Public License の Version 2 に記
 *  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
 *  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
 *  利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
 *  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
 *  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
 * 
 *  @(#) $Id: sdcard.c,v 1.1 2016/05/04 20:14:33 roi Exp $
 */
/*
 *  SH7262用 SDMMCドライバ
 */
#include "kernel/kernel_impl.h"
#include <t_syslog.h>
#include <t_stdlib.h>
#include <sil.h>
#include <target_syssvc.h>
#include "kernel_cfg.h"
//#include "device.h"
#include "sdmmc.h"

#if 1
#define sil_orb_mem(a, b)		sil_wrb_mem((a), sil_reb_mem(a) | (b))
#define sil_andb_mem(a, b)		sil_wrb_mem((a), sil_reb_mem(a) & ~(b))
#define sil_modb_mem(a, b, c)	sil_wrb_mem((a), (sil_reb_mem(a) & (~b)) | (c))
#define sil_orh_mem(a, b)		sil_wrh_mem((a), sil_reh_mem(a) | (b))
#define sil_andh_mem(a, b)		sil_wrh_mem((a), sil_reh_mem(a) & ~(b))
#define sil_modh_mem(a, b, c)	sil_wrh_mem((a), (sil_reh_mem(a) & (~b)) | (c))
#endif
#define sil_orw_mem(a, b)		sil_wrw_mem((a), sil_rew_mem(a) | (b))
#define sil_andw_mem(a, b)		sil_wrw_mem((a), sil_rew_mem(a) & ~(b))
#define sil_modw_mem(a, b, c)	sil_wrw_mem((a), (sil_rew_mem(a) & (~b)) | (c))

#if 1
#define	PCCR1		((uint16_t *)0xFFFE384C)
#define	PCIOR0		((uint16_t *)0xFFFE3852)
#define	PCDR0		((uint16_t *)0xFFFE3856)
#define	PFCR3		((uint16_t *)0xFFFE38A8)
#define	PFCR2		((uint16_t *)0xFFFE38AA)
#define	STBCR5		((uint8_t  *)0xFFFE0410)
#define	SPCR_0		((uint8_t  *)0xFFFF8000)
#define	SPPCR_0		((uint8_t  *)0xFFFF8002)
#define	SPSR_0		((uint8_t  *)0xFFFF8003)
#define	SPDR_0		((uint8_t  *)0xFFFF8004)
#define	SPSCR_0		((uint8_t  *)0xFFFF8008)
#define	SPSSR_0		((uint8_t  *)0xFFFF8009)
#define	SPBR_0		((uint8_t  *)0xFFFF800A)
#define	SPDCR_0		((uint8_t  *)0xFFFF800B)
#define	SPCKD_0		((uint8_t  *)0xFFFF800C)
#define	SPND_0		((uint8_t  *)0xFFFF800E)
#define	SPCMD_00	((uint16_t *)0xFFFF8010)
#define	SPBFCR_0	((uint8_t  *)0xFFFF8020)
#define	SPBFDR_0	((uint16_t *)0xFFFF8022)
#define	STBCR2		((uint8_t  *)0xFFFE0018)
#define	SAR_0		((uint32_t *)0xFFFE1000)
#define	DAR_0		((uint32_t *)0xFFFE1004)
#define	DMATCR_0	((uint32_t *)0xFFFE1008)
#define	CHCR_0		((uint32_t *)0xFFFE100C)
#define	DMAOR		((uint16_t *)0xFFFE1200)
#define	DMARS0		((uint16_t *)0xFFFE1300)
#else
#ifdef TOPPERS_STM32F769_DISCOVERY
#define TADR_SDMMC_BASE         TADR_SDMMC2_BASE
#define GPIO_AF10_SDMMC2        0x0A	/* SDMMC2 Alternate Function mapping */
#define GPIO_AF11_SDMMC2        0x0B	/* SDMMC2 Alternate Function mapping */
#define RCC_APB2ENR_SDMMCEN     RCC_APB2ENR_SDMMC2EN
#define SD_DETECT_CLOCK         RCC_AHB1ENR_GPIOIEN
#define SD_DETECT_PORT          TADR_GPIOI_BASE
#define SD_DETECT_PIN           15
#define TADR_DMA_RX             TADR_DMA2_STM0_BASE
#define TADR_DMA_TX             TADR_DMA2_STM5_BASE
#define DMA_RX_CHANNEL          DMA_CHANNEL_11
#define DMA_TX_CHANNEL          DMA_CHANNEL_11

#else
#define TADR_SDMMC_BASE         TADR_SDMMC1_BASE
#define GPIO_AF12_SDMMC1        0x0C	/* SDMMC1 Alternate Function mapping */
#define RCC_APB2ENR_SDMMCEN     RCC_APB2ENR_SDIOEN
#define SD_DETECT_CLOCK         RCC_AHB1ENR_GPIOCEN
#define SD_DETECT_PORT          TADR_GPIOC_BASE
#define SD_DETECT_PIN           13
#define TADR_DMA_RX             TADR_DMA2_STM3_BASE
#define TADR_DMA_TX             TADR_DMA2_STM6_BASE
#define DMA_RX_CHANNEL          DMA_CHANNEL_4
#define DMA_TX_CHANNEL          DMA_CHANNEL_4

#endif
#endif


#define CLKCR_CLEAR_MASK                ((SDMMC_CLKCR_CLKDIV  | SDMMC_CLKCR_PWRSAV |\
                                          SDMMC_CLKCR_BYPASS  | SDMMC_CLKCR_WIDBUS |\
                                          SDMMC_CLKCR_NEGEDGE | SDMMC_CLKCR_HWFC_EN))
/* --- DCTRL Register ---*/
/* SDMMC DCTRL Clear Mask */
#define DCTRL_CLEAR_MASK                ((SDMMC_DCTRL_DTEN    | SDMMC_DCTRL_DTDIR |\
                                          SDMMC_DCTRL_DTMODE  | SDMMC_DCTRL_DBLOCKSIZE))

/* --- CMD Register ---*/
/* CMD Register clear mask */
#define CMD_CLEAR_MASK                  ((SDMMC_CMD_CMDINDEX | SDMMC_CMD_WAITRESP |\
                                          SDMMC_CMD_WAITINT  | SDMMC_CMD_WAITPEND |\
                                          SDMMC_CMD_CPSMEN   | SDMMC_CMD_SDIOSUSPEND))

/*
 *  SDMMCデータブロック長
 */
#define DATA_BLOCK_SIZE                 (9 << 4)

/*
 *  SDMMCでスタックに使用するフラグ
 */
#define SDMMC_STATIC_FLAGS              (SDMMC_STA_CCRCFAIL | SDMMC_STA_DCRCFAIL | SDMMC_STA_CTIMEOUT |\
                                         SDMMC_STA_DTIMEOUT | SDMMC_STA_TXUNDERR | SDMMC_STA_RXOVERR  |\
                                         SDMMC_STA_CMDREND  | SDMMC_STA_CMDSENT  | SDMMC_STA_DATAEND  |\
                                         SDMMC_STA_DBCKEND)

/*
 *  RESPONSE1エラー値
 */
#define SD_OCR_ERROR                    0xFDFFE008

/*
 *  RESPONSE6エラー値
 */
#define SD_R6_GENERAL_UNKNOWN_ERROR     0x00002000
#define SD_R6_ILLEGAL_CMD               0x00004000
#define SD_R6_COM_CRC_FAILED            0x00008000

#define SDMMC_WAIT_STATUS               (SDMMC_STA_CCRCFAIL | SDMMC_STA_CMDREND | SDMMC_STA_CTIMEOUT)
#define SDMMC_INT1_ERROR                (SDMMC_STA_DCRCFAIL | SDMMC_STA_DTIMEOUT | SDMMC_STA_RXOVERR)
#define SDMMC_INT2_ERROR                (SDMMC_INT1_ERROR | SDMMC_STA_TXUNDERR)
#define SDMMC_INT_MASK                  (SDMMC_INT2_ERROR | SDMMC_STA_DATAEND | SDMMC_STA_TXFIFOHE | SDMMC_STA_RXFIFOHF)

/*
 *  カードタイプ定義
 */
#define SD_HIGH_CAPACITY                0x40000000
#define SD_STD_CAPACITY                 0x00000000

/*
 *  SCRのビット定義
 */
#define SD_WIDE_BUS_SUPPORT             0x00040000
#define SD_SINGLE_BUS_SUPPORT           0x00010000
#define SD_CARD_LOCKED                  0x02000000

/*
 *  CSDのクラスサポート定義
 */
#define SD_CCCC_LOCK_UNLOCK             0x00000080
#define SD_CCCC_WRITE_PROT              0x00000040
#define SD_CCCC_ERASE                   0x00000020

#define SD_MAX_VOLT_TRIAL               0x0000FFFF
#define SDMMC_CMD0TIMEOUT               (5000*1000)


/*static*/ ER sdmmc_sendcommand(SDMMC_Handle_t *hsd, uint32_t cmd, uint32_t arg, ER (*func)(SDMMC_Handle_t *, uint32_t));

static ER sdmmc_checkrep1(SDMMC_Handle_t *hsd, uint32_t Cmd);
static ER sdmmc_checkrep7(SDMMC_Handle_t *hsd, uint32_t Cmd);
static ER sdmmc_checkrep3_spi(SDMMC_Handle_t *hsd, uint32_t Cmd);
#if 0
static ER sdmmc_checkrep2(SDMMC_Handle_t *hsd, uint32_t Cmd);
static ER sdmmc_checkrep3(SDMMC_Handle_t *hsd, uint32_t Cmd);
static ER sdmmc_checkrep6(SDMMC_Handle_t *hsd, uint32_t Cmd);
static ER sdmmc_command_wait(SDMMC_Handle_t *hsd);

static ER sdmmc_enable_widebus(SDMMC_Handle_t *hsd);
static ER sdmmc_disable_widebus(SDMMC_Handle_t *hsd);
static ER sdmmc_getSCR(SDMMC_Handle_t *hsd, uint32_t *pSCR);
static ER sdmmc_getpstate(SDMMC_Handle_t *hsd, uint8_t *pStatus);
#endif

static SDMMC_Handle_t SdHandle;

void gpio_init()
{
	sil_andh_mem(PCCR1, 0x3330);
	sil_modh_mem(PCIOR0, 0x00E0, 0x0080);
	sil_orh_mem(PCDR0, 0x0080);
}

void spi_init()
{
	sil_andb_mem(STBCR5, 0x02);
	sil_wrb_mem(SPCR_0, 0x08);
	sil_wrb_mem(SPPCR_0, 0x00);
	sil_wrb_mem(SPSCR_0, 0x00);
	sil_wrb_mem(SPBR_0, 0x05);
	sil_wrb_mem(SPDCR_0, 0x20);
	sil_wrb_mem(SPCKD_0, 0x00);
	sil_wrb_mem(SPND_0, 0x00);
	sil_wrh_mem(SPCMD_00, 0xA78B);
	sil_orb_mem(SPBFCR_0, 0xC0);
	sil_modb_mem(SPBFCR_0, 0x37, 0x00);
	sil_andb_mem(SPBFCR_0, 0xC0);
	sil_orb_mem(SPCR_0, 0xC0);
	sil_modh_mem(PFCR3, 0x0007, 0x0003);
	sil_modh_mem(PFCR2, 0x7070, 0x3030);
}

void gpio_cs_assert(uint8_t assert)
{
	if (assert)
		sil_andh_mem(PCDR0, 0x0080);
	else
		sil_orh_mem(PCDR0, 0x0080);
}

uint8_t spi_trans(uint8_t tx)
{
	uint8_t rx;

	sil_wrb_mem(SPDR_0, tx);
	while ((sil_reh_mem(SPBFDR_0) & 0x0F00) != 0x0000) ;
	while ((sil_reh_mem(SPBFDR_0) & 0x003F) == 0x0000) ;
	rx = sil_reb_mem(SPDR_0);

	return rx;
}

void spi_speed_lowspeed(uint32_t lowspeed)
{
	if (lowspeed)
	{
		sil_andb_mem(SPCR_0, 0x40);
		sil_wrb_mem(SPBR_0, 0x3B);
		sil_orb_mem(SPCR_0, 0x40);
	}
	else
	{
		sil_andb_mem(SPCR_0, 0x40);
		sil_wrb_mem(SPBR_0, 0x05);
		sil_orb_mem(SPCR_0, 0x40);
	}
}

void spi_data_dmytx(uint32_t enable)
{
	if (enable)
	{
		sil_wrb_mem(SPDCR_0, 0xA0);
	}
	else
	{
		sil_wrb_mem(SPDCR_0, 0x20);
	}
}

ER dma_init()
{
	ER ret = E_OK;

	sil_andb_mem(STBCR2, 0x20);
	sil_andh_mem(DMAOR, 0x0001);
	sil_andw_mem(CHCR_0, 0x00000001);
	sil_modw_mem(CHCR_0, 0xB014FF3C, 0x00004800);
	sil_modh_mem(DMARS0, 0x00FF, 0x0052);
	sil_orh_mem(DMAOR, 0x0007);

	return ret;
}

ER dma_start(uint8_t *dst, uint8_t *src, uint32_t len)
{
	ER ret = E_OK;

	sil_wrw_mem(SAR_0, (uint32_t)src);
	sil_wrw_mem(DAR_0, (uint32_t)dst);
	sil_wrw_mem(DMATCR_0, len);
	sil_orw_mem(CHCR_0, 0x00000005);

	return ret;
}

ER dma_end()
{
	ER ret = E_OK;

	return ret;
}

void sd_trans_dmyclk()
{
	volatile uint8_t rx;
	volatile uint32_t i;

	while ((sil_reh_mem(SPBFDR_0) & 0x0F3F) != 0x0000) ;
	for (i = 0; i < 10; i++)
	{
		sil_wrb_mem(SPDR_0, 0xFF);
		while ((sil_reh_mem(SPBFDR_0) & 0x0F00) != 0x0000) ;
		while ((sil_reh_mem(SPBFDR_0) & 0x003F) == 0x0000) ;
		rx = sil_reb_mem(SPDR_0);
	}
}

ER sd_trans_cmd(uint8_t *cmd, uint32_t resp_len, uint8_t *resp, bool_t spi_mode)
{
	ER ret = E_OK;
	volatile uint32_t i, j;

	gpio_cs_assert(spi_mode ? 1 : 0);
	spi_trans(0xFF);

	for (i = 0; i < 6; i++)
		spi_trans(cmd[i]);

	for (j = 0; j < 8; j++)
	{
		resp[0] = spi_trans(0xFF);
		if ((resp[0] & 0x80) == 0x80) continue;
		for (i = 1; i < resp_len; i++)
			resp[i] = spi_trans(0xFF);
		break;
	}
	if (j == 8)
		ret = E_SYS;

	gpio_cs_assert(0);
	spi_trans(0xFF);

	return ret;
}

ER sd_trans_data_rx_dma_start(uint32_t data_len, uint8_t *data, uint32_t spi_mode)
{
	ER ret = E_OK;
	volatile uint32_t i;
	volatile uint8_t rx;

	gpio_cs_assert(spi_mode ? 1 : 0);
	spi_trans(0xFF);

	while (1)
	{
		rx = spi_trans(0xFF);
		if ((rx & 0xE0) == 0x00) return E_SYS;
		if (rx == 0xFE) break;
		for (i = 0; i < 0x40000; i++) ;
	}
	spi_data_dmytx(1);

	dma_start(data, SPDR_0, data_len);

	return ret;
}

ER sd_trans_data_rx_dma_end()
{
	ER ret = E_OK;

	dma_end();

	spi_data_dmytx(0);
	spi_trans(0xFF);
	spi_trans(0xFF);

	gpio_cs_assert(0);
	spi_trans(0xFF);

	return ret;
}

#if 0
/*
 * SDMMC 受信DMAコールバック関数
 */
static void
sdmmc_rxdma_callback(DMA_Handle_t *hdma)
{
	isig_sem(SDMMC_SEM);
}

/*
 * SDMMC 送信DMAコールバック関数
 */
static void
sdmmc_txdma_callback(DMA_Handle_t *hdma)
{
	isig_sem(SDMMC_SEM);
}
#endif


/*
 *  SDMMC初期化
 *  parameter1  addr: Pointer to SDMMC register base
 */
void
sdmmc_init(intptr_t exinf)
{
#if 1
	gpio_init();
	spi_init();
	dma_init();
#else
	GPIO_Init_t GPIO_Init_Data;
	volatile unsigned long tmp;

	/* AHB1ENRクロックイネーブル */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AHB1ENR), SD_DETECT_CLOCK);
#ifdef TOPPERS_STM32F769_DISCOVERY
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AHB1ENR), RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIODEN | RCC_AHB1ENR_GPIOGEN);
#else
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AHB1ENR), RCC_AHB1ENR_GPIOCEN | RCC_AHB1ENR_GPIODEN);
#endif
	tmp = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AHB1ENR));
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AHB1ENR), RCC_AHB1ENR_DMA2EN);
	tmp = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AHB1ENR));

	GPIO_Init_Data.mode      = GPIO_MODE_INPUT;
	GPIO_Init_Data.pull      = GPIO_PULLUP;
	GPIO_Init_Data.speed     = GPIO_SPEED_HIGH;
	gpio_setup(SD_DETECT_PORT, &GPIO_Init_Data, SD_DETECT_PIN);

	/* SDIOクロックイネーブル */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB2ENR), RCC_APB2ENR_SDMMCEN);
	tmp = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB2ENR));
	(void)(tmp);

	GPIO_Init_Data.mode      = GPIO_MODE_AF;
	GPIO_Init_Data.pull      = GPIO_PULLUP;
	GPIO_Init_Data.otype     = GPIO_OTYPE_PP;
	GPIO_Init_Data.speed     = GPIO_SPEED_HIGH;
#ifdef TOPPERS_STM32F769_DISCOVERY
	GPIO_Init_Data.alternate = GPIO_AF10_SDMMC2;
	gpio_setup(TADR_GPIOB_BASE, &GPIO_Init_Data, 3);
	gpio_setup(TADR_GPIOB_BASE, &GPIO_Init_Data, 4);
	GPIO_Init_Data.alternate = GPIO_AF11_SDMMC2;
	gpio_setup(TADR_GPIOD_BASE, &GPIO_Init_Data, 6);
	gpio_setup(TADR_GPIOD_BASE, &GPIO_Init_Data, 7);
	gpio_setup(TADR_GPIOG_BASE, &GPIO_Init_Data, 9);
	gpio_setup(TADR_GPIOG_BASE, &GPIO_Init_Data, 10);
#else
	GPIO_Init_Data.alternate = GPIO_AF12_SDMMC1;
	gpio_setup(TADR_GPIOC_BASE, &GPIO_Init_Data, 8);
	gpio_setup(TADR_GPIOC_BASE, &GPIO_Init_Data, 9);
	gpio_setup(TADR_GPIOC_BASE, &GPIO_Init_Data, 10);
	gpio_setup(TADR_GPIOC_BASE, &GPIO_Init_Data, 11);
	gpio_setup(TADR_GPIOC_BASE, &GPIO_Init_Data, 12);
	gpio_setup(TADR_GPIOD_BASE, &GPIO_Init_Data, 2);
#endif
#endif
}

/*
 *  SDカード有無チェック
 */
bool_t
sdmmc_sense(int id)
{
/*
	if((sil_rew_mem((uint32_t *)(SD_DETECT_PORT+TOFF_GPIO_IDR)) & (1<<SD_DETECT_PIN)) != 0)
		return false;
	else
*/
		return true;
}

/*
 *  SDMMCオープン
 */
SDMMC_Handle_t*
sdmmc_open(int id)
{
#if 1
	SDMMC_Handle_t *hsd = &SdHandle;
	ER ret;
	volatile uint8_t sdsc;

	/*  1MSの待ち */
	dly_tsk(1);

	sd_trans_dmyclk();
	spi_speed_lowspeed(1);

	/*
	 *  CMD0: GO_IDLE_STATE
	 */
	ret = sdmmc_sendcommand(hsd, MCI_CMD0, 0, sdmmc_checkrep1);
	if (ret != E_OK) while (1) ;
	if (hsd->R1 != 0x01) while (1);

	/*
	 *  CMD8: SEND_IF_COND
	 */
	ret = sdmmc_sendcommand(hsd, MCI_CMD8, 0x000001AA, sdmmc_checkrep7);
	if (ret != E_OK) while (1) ;
	if (hsd->cardtype == SD_CARD_V11) sdsc = 1;
	else sdsc = 0;
	if (sdsc)
	{
		while (1)
		{
			/*
			 *  ACMD41: SD_SEND_OP_COND
			 */
			ret = sdmmc_sendcommand(hsd, MCI_CMD55, 0, sdmmc_checkrep1);
			if (ret != E_OK) while (1) ;
			ret = sdmmc_sendcommand(hsd, MCI_ACMD41, 0, sdmmc_checkrep1);
			if (ret != E_OK) while (1) ;
			if (hsd->R1 == 0x00) break;
			dly_tsk(25);
		}
	}
	else
	{
		while (1)
		{
			/*
			 *  ACMD41: SD_SEND_OP_COND
			 */
			ret = sdmmc_sendcommand(hsd, MCI_CMD55, 0, sdmmc_checkrep1);
			if (ret != E_OK) while (1) ;
			ret = sdmmc_sendcommand(hsd, MCI_ACMD41, 0x40000000, sdmmc_checkrep1);
			if (ret != E_OK) while (1) ;
			if (hsd->R1 == 0x00) break;
			dly_tsk(25);
		}
		{
			/*
			 *  CMD58: READ_OCR
			 */
			ret = sdmmc_sendcommand(hsd, MCI_CMD58, 0, sdmmc_checkrep3_spi);
			if (ret != E_OK) while (1) ;
			if (hsd->R1 != 0x00) while (1);
			if ((hsd->OCR & 0x40000000) == 0x00000000) sdsc = 1;
			else sdsc = 0;
		}
	}
	spi_speed_lowspeed(0);
	//while (1) ;

	return hsd;
#else
	static DMA_Handle_t dma_rx_handle;
	static DMA_Handle_t dma_tx_handle;
	ER       ercd = E_OK;
	SDMMC_Handle_t *hsd = &SdHandle;
	uint32_t response = 0, count = 0, validvoltage = 0;
	uint32_t sdtype = SD_STD_CAPACITY;
	int      timeout;

	hsd->base       = TADR_SDMMC_BASE;
	hsd->ClockMode  = SDMMC_TRANSFER_CLK_DIV;
	hsd->BusWide    = SDMMC_BUS_WIDE_4B;
	hsd->RetryCount = 32;
	/*
	 *  初期設定、BUS WIDEは１ビット
	 */
	sil_modw_mem((uint32_t *)(hsd->base+TOFF_SDIO_CLKCR), CLKCR_CLEAR_MASK, (SDMMC_INIT_CLK_DIV | SDMMC_BUS_WIDE_1B));

	/*
	 *  SDMMCクロック停止後、電源オンし、１秒後クロック再開
	 */
	sil_andw_mem((uint32_t *)(hsd->base+TOFF_SDIO_CLKCR), SDMMC_CLKCR_CLKEN);
	sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_POWER), SDMMC_POWER_PWRCTRL);

	/*  1MSの待ち */
	dly_tsk(1);
	sil_orw_mem((uint32_t *)(hsd->base+TOFF_SDIO_CLKCR), SDMMC_CLKCR_CLKEN);

	/*
	 *  CMD0: GO IDLE STATE
	 */
	sdmmc_sendcommand(hsd, MCI_CMD0, 0, NULL);

	/*  コマンドステート終了待ち */
	timeout = 5000;
	while((timeout > 0) && ((sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_STA)) & SDMMC_STA_CMDSENT) == 0)){
		dly_tsk(1);
		timeout--;
	}
	if(timeout == 0){
		return NULL;
	}

	/* ステートフラグをクリア */
	sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_ICR), SDMMC_STATIC_FLAGS);

	/*
	 *  CMD8: SEND IF COND
	 */
	sdmmc_sendcommand(hsd, MCI_CMD8, 0x000001AA, NULL);
	ercd = sdmmc_command_wait(hsd);
	if(ercd != E_OK || ((sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_STA)) & SDMMC_STA_CTIMEOUT) != 0)){
		/*
		 * タイムアウトならタイムアウトをクリア
		 */
		sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_ICR), SDMMC_STA_CTIMEOUT);
	}
	else if((sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_STA)) & SDMMC_STA_CMDREND) != 0){
		/*
		 *  レスポンスエンドならSDCARDV2.0確定
		 */
		sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_ICR), SDMMC_STA_CMDREND);
		hsd->cardtype = SD_CARD_V20; 
		sdtype        = SD_HIGH_CAPACITY;
	}

	/*
	 * CMD55を送信
	 */
	ercd = sdmmc_sendcommand(hsd, MCI_CMD55, 0, sdmmc_checkrep1);
	if(ercd == E_OK){
		/*
		 *  SDCARD確定:VOLTAGEの確認
		 */
		while(validvoltage == 0 && count < SD_MAX_VOLT_TRIAL){
			/* SEND CMD55 APP_CMD with RCA as 0 */
			ercd = sdmmc_sendcommand(hsd, MCI_CMD55, 0, sdmmc_checkrep1);
			if(ercd != E_OK){
				return NULL;
			}
			/*
			 * 引数0x8010000でCMD41を送信
			 */
			ercd = sdmmc_sendcommand(hsd, MCI_ACMD41, (0x80100000 | sdtype), sdmmc_checkrep3);
			if(ercd != E_OK){
				return NULL;
			}
			/*
			 * レスポンスから制御ボルテージを取得
			 */
			response = sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_RESP));
			validvoltage = (((response >> 31) == 1) ? 1 : 0);
			count++;
		}
		if(count >= SD_MAX_VOLT_TRIAL){
			return NULL;
		}

		if((response & SD_HIGH_CAPACITY) == SD_HIGH_CAPACITY){
			/*
			 *  HC-SDCARD確定
			 */
			hsd->cardtype = SD_CARD_HC;
		}
	}

	/*
	 *  受信DMAのコンフィギュレーション
	 */
	dma_rx_handle.Init.Channel             = DMA_RX_CHANNEL;
	dma_rx_handle.Init.Direction           = DMA_PERIPH_TO_MEMORY;
	dma_rx_handle.Init.PeriphInc           = DMA_PINC_DISABLE;
	dma_rx_handle.Init.MemInc              = DMA_MINC_ENABLE;
	dma_rx_handle.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
	dma_rx_handle.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
	dma_rx_handle.Init.Mode                = DMA_PFCTRL;
	dma_rx_handle.Init.Priority            = DMA_PRIORITY_VERY_HIGH;
	dma_rx_handle.Init.FIFOMode            = DMA_FIFOMODE_ENABLE;
	dma_rx_handle.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
	dma_rx_handle.Init.MemBurst            = DMA_MBURST_INC4;
	dma_rx_handle.Init.PeriphBurst         = DMA_PBURST_INC4;
	dma_rx_handle.base = TADR_DMA_RX;

	/*
	 *  受信DMAハンドルの設定
	 */
	hsd->hdmarx = &dma_rx_handle;
	dma_deinit(&dma_rx_handle);
	dma_init(&dma_rx_handle);

	/*
	 *  送信DMAのコンフィギュレーション
	 */
	dma_tx_handle.Init.Channel             = DMA_TX_CHANNEL;
	dma_tx_handle.Init.Direction           = DMA_MEMORY_TO_PERIPH;
	dma_tx_handle.Init.PeriphInc           = DMA_PINC_DISABLE;
	dma_tx_handle.Init.MemInc              = DMA_MINC_ENABLE;
	dma_tx_handle.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
	dma_tx_handle.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
	dma_tx_handle.Init.Mode                = DMA_PFCTRL;
	dma_tx_handle.Init.Priority            = DMA_PRIORITY_VERY_HIGH;
	dma_tx_handle.Init.FIFOMode            = DMA_FIFOMODE_ENABLE;
	dma_tx_handle.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
	dma_tx_handle.Init.MemBurst            = DMA_MBURST_INC4;
	dma_tx_handle.Init.PeriphBurst         = DMA_PBURST_INC4;
	dma_tx_handle.base = TADR_DMA_TX;

	/*
	 *  送信DMAハンドルの設定
	 */
	hsd->hdmatx = &dma_tx_handle;
	dma_deinit(&dma_tx_handle);
	dma_init(&dma_tx_handle); 
  	return hsd;
#endif
}

/*
 *  SDMMCクローズ
 */
ER
sdmmc_close(SDMMC_Handle_t *hsd)
{
#if 1
	return E_OK;
#else
	if(hsd == NULL)
		return E_PAR;

	/* SDの電源オフ */ 
	sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_POWER), 0x00000000);
	hsd->status = 3;
	return E_OK;
#endif
}

/*
 *  SDMMCカードイレーズ
 *  parameter1  hsd: SDMMCハンドラ
 *  parameter2  startaddr: スタートバイト位置
 *  parameter3  endaddr: エンドバイト位置
 *  return :ERコード
 */
ER
sdmmc_erase(SDMMC_Handle_t *hsd, uint64_t startaddr, uint64_t endaddr)
{
#if 1
	return E_OK;
#else
	ER ercd = E_OK;
	uint32_t delay = 0;
	volatile uint32_t maxdelay = 0;
	uint8_t cardstate = 0;

	if(hsd == NULL)
		return E_PAR;

	/*
	 *  イレーズコマンド有り無し判定
	 */
	if(((hsd->CSD[1] >> 20) & SD_CCCC_ERASE) == 0){
		return E_OBJ;
	}

	/*
	 *  コマンド受付待ちカウント取得
	 */
	maxdelay = 120000 / (((sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_CLKCR))) & 0xFF) + 2);

	if((sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_RESP)) & SD_CARD_LOCKED) == SD_CARD_LOCKED){
		return E_OBJ;
	}

	/*
	 *  HC SDCARDの設定アドレス補正
	 */
	if(hsd->cardtype == SD_CARD_HC){
		startaddr /= 512;
		endaddr   /= 512;
	}

	/* According to sd-card spec 1.0 ERASE_GROUP_START (CMD32) and erase_group_end(CMD33) */
	if(hsd->cardtype == SD_CARD_V11 || hsd->cardtype == SD_CARD_V20 || hsd->cardtype == SD_CARD_HC){
		/* Send CMD32 SD_ERASE_GRP_START with argument as addr  */
		ercd = sdmmc_sendcommand(hsd, MCI_CMD32, (uint32_t)startaddr, sdmmc_checkrep1);
		if (ercd != E_OK){
			return ercd;
		}

		/* Send CMD33 SD_ERASE_GRP_END with argument as addr  */
		ercd = sdmmc_sendcommand(hsd, MCI_CMD33, (uint32_t)endaddr, sdmmc_checkrep1);
		if(ercd != E_OK){
			return ercd;
		}
	}

	/*
	 *  CMD38 ERASE送信
	 */
	ercd = sdmmc_sendcommand(hsd, MCI_CMD38, 0, sdmmc_checkrep1);
	if(ercd != E_OK){
		return ercd;
	}

	for (; delay < maxdelay; delay++){
	}

	/*
	 *  プログラミング終了待ち
	 */
	ercd = sdmmc_getpstate(hsd, &cardstate);
	delay = 120*1000;
	while(delay > 0 && ercd == E_OK && ((cardstate == SD_CARD_PROGRAMMING) || (cardstate == SD_CARD_RECEIVING))){
		ercd = sdmmc_getpstate(hsd, &cardstate);
		dly_tsk(1);
		delay--;
	}
	return ercd;
#endif
}

/*
 *  SDMMCブロックREAD
 *  parameter1  hsd: SDMMCハンドラ
 *  parameter2  pbuf: 読み出しデータ格納領域のポインタ(uint32_t型)
 *  parameter3  ReadAddr: カード上の読み出し位置
 *  parameter4  blocksize: ブロックサイズ
 *  parameter5  num: 読み出しブロック数
 *  return      ERコード
 */
ER
sdmmc_blockread(SDMMC_Handle_t *hsd, uint32_t *pbuf, uint64_t ReadAddr, uint32_t blocksize, uint32_t num)
{
#if 1
	ER ret;
	{
		/*
		 *  CMD16: SET_BLOCKLEN
		 */
		ret = sdmmc_sendcommand(hsd, MCI_CMD16, blocksize, sdmmc_checkrep1);
		if (ret != E_OK) while (1) ;
		if (hsd->R1 != 0x00) while (1);
	}
	{
		/*
		 *  CMD17: READ_SINGLE_BLOCK
		 */
		ret = sdmmc_sendcommand(hsd, MCI_CMD17, 0, sdmmc_checkrep1);
		if (ret != E_OK) while (1) ;
		if (hsd->R1 != 0x00) while (1);
	}
	{
		ret = sd_trans_data_rx_dma_start(blocksize, (uint8_t*)pbuf, 1);
		if (ret != 0) while (1) ;
	}
	return E_OK;
#else
	ER ercd = E_OK;

	if(hsd == NULL)
		return E_PAR;

	/*
	 *  データコントロールレジスタをクリア
	 */
	sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_DCTRL), 0);

	/*
	 *  ステートをクリア
	 */
	hsd->status  = 0;

	/*
	 *  リードコマンド選択
	 */
	if(num > 1)
		hsd->SdCmd = MCI_CMD18;
	else
		hsd->SdCmd = MCI_CMD17;

	/*
	 *  転送割込み設定
	 */
	sil_orw_mem((uint32_t *)(hsd->base+TOFF_SDIO_MASK), (SDMMC_INT1_ERROR | SDMMC_STA_DATAEND));

	/*
	 *  DMA転送設定
	 */
	sil_orw_mem((uint32_t *)(hsd->base+TOFF_SDIO_DCTRL), SDMMC_DCTRL_DMAEN);

	/*
	 *  コールバック関数設定
	 */
	hsd->hdmarx->xfercallback  = sdmmc_rxdma_callback;
	hsd->hdmarx->errorcallback = NULL;

	/*
	 *  受信DMAスタート
	 */
	if(((uint32_t)pbuf) < 0x40000000)
		flushinvalidatedcache_by_addr((uint8_t *)pbuf, (blocksize * num));
	dma_start(hsd->hdmarx, hsd->base+TOFF_SDIO_FIFO, (uint32_t)pbuf, (uint32_t)(blocksize * num)/4);
	if(hsd->cardtype == SD_CARD_HC){
		blocksize = 512;
		ReadAddr /= 512;
	}

	/*
	 *  CMD16:ブロックサイズ設定
	 */
	ercd = sdmmc_sendcommand(hsd, MCI_CMD16, (uint32_t)blocksize, sdmmc_checkrep1);
	if(ercd != E_OK){
		return ercd;
	}

	/*
	 *  SD-DPSMを設定
	 */
	sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_DTIMER), 0xFFFFFFFF);
	sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_DLEN), blocksize * num);
	sil_modw_mem((uint32_t *)(hsd->base+TOFF_SDIO_DCTRL), DCTRL_CLEAR_MASK,
				(SDMMC_DBSIZE_512B | SDMMC_DCTRL_DTDIR | SDMMC_DCTRL_DTEN));

	/*
	 *  READコマンド送信
	 */
	ercd = sdmmc_sendcommand(hsd, hsd->SdCmd, (uint32_t)ReadAddr, sdmmc_checkrep1);

	/*
	 *  送信エラーならエラー設定をする
	 */
	if (ercd != E_OK){
		hsd->status = 2;
	}
	return ercd;
#endif
}

/*
 *  SDMMCブロックWRITE
 *  parameter1  hsd: SDMMCハンドラ
 *  parameter2  pbuf: 書込みデータ格納領域のポインタ(uint32_t型)
 *  parameter3  WritedAddr: カード上の書き込み位置
 *  parameter4  blocksize: ブロックサイズ
 *  parameter5  num: 書込みブロック数
 *  return      ERコード
 */
ER
sdmmc_blockwrite(SDMMC_Handle_t *hsd, uint32_t *pbuf, uint64_t WriteAddr, uint32_t blocksize, uint32_t num)
{
#if 1
	return E_OK;
#else
	ER       ercd = E_OK;

	if(hsd == NULL)
		return E_PAR;

	/*
	 *  データコントロールレジスタをクリア
	 */
	sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_DCTRL), 0);

	/*
	 *  ステートをクリア
	 */
	hsd->status = 0;

	/*
	 *  ライトコマンド選択
	 */
	if(num > 1)
		hsd->SdCmd = MCI_CMD25;
	else
		hsd->SdCmd = MCI_CMD24;

	/*
	 *  転送割込み設定
	 */
	sil_orw_mem((uint32_t *)(hsd->base+TOFF_SDIO_MASK), (SDMMC_INT2_ERROR | SDMMC_STA_DATAEND));

	/*
	 *  コールバック関数設定
	 */
	hsd->hdmatx->xfercallback  = sdmmc_txdma_callback;
	hsd->hdmatx->errorcallback = NULL;

	/*
	 *  送信DMAスタート
	 */
	if(((uint32_t)pbuf) < 0x40000000)
		flushinvalidatedcache_by_addr((uint8_t *)pbuf, (blocksize * num));
	dma_start(hsd->hdmatx, (uint32_t)pbuf, hsd->base+TOFF_SDIO_FIFO, (uint32_t)(blocksize * num)/4);
	if(hsd->cardtype == SD_CARD_HC){
		blocksize = 512;
		WriteAddr /= 512;
	}

	/*
	 *  DMA転送設定
	 */
	sil_orw_mem((uint32_t *)(hsd->base+TOFF_SDIO_DCTRL), SDMMC_DCTRL_DMAEN);

	/*
	 *  CMD16:ブロックサイズ設定
	 */
	ercd = sdmmc_sendcommand(hsd, MCI_CMD16, (uint32_t)blocksize, sdmmc_checkrep1);
	if(ercd != E_OK){
		return ercd;
	}

	/*
	 *  WRITEコマンド送信
	 */
	ercd = sdmmc_sendcommand(hsd, hsd->SdCmd, (uint32_t)WriteAddr, sdmmc_checkrep1);
	if(ercd != E_OK){
		return ercd;
	}

	/*
	 *  SD-DPSMを設定
	 */
	sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_DTIMER), 0xFFFFFFFF);
	sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_DLEN), blocksize * num);
	sil_modw_mem((uint32_t *)(hsd->base+TOFF_SDIO_DCTRL), DCTRL_CLEAR_MASK,
					(SDMMC_DBSIZE_512B | SDMMC_DCTRL_DTEN));

	/*
	 *  送信エラーならエラー設定をする
	 */
	if(ercd != E_OK){
		hsd->status = 2;
	}
	return ercd;
#endif
}

/*
 *  SDMMCブロック転送終了待ち
 *  parameter1  hsd: SDMMCハンドラ
 *  parameter2  Timeout: タイムアウト値(1msec)
 *  return      ERコード
 */
ER
sdmmc_wait_transfar(SDMMC_Handle_t *hsd, uint32_t Timeout)
{
#if 1
	wai_sem(SDMMC_SEM);
	sd_trans_data_rx_dma_end();
	return E_OK;
#else
	DMA_Handle_t *hdma = hsd->hdmarx;
	ER           tercd = E_OK, ercd = E_OK;
	int          timeout;
	uint32_t     tmp1, tmp2;

	if(hsd == NULL)
		return E_PAR;

	if(Timeout > 60*1000);
		Timeout = 60*1000;
	timeout = Timeout;
	/*
	 *  DMA/SD転送の終了割込み待ち
	 */
	tmp1 = hdma->status;
	tmp2 = hsd->status;

	while((tmp1 == DMA_STATUS_BUSY || tmp2 == 0) && timeout > 0){
		tmp1 = hdma->status;
		tmp2 = hsd->status;
		twai_sem(SDMMC_SEM, 10);
		timeout -= 10;
	}

	timeout = Timeout;
	if(hsd->status != 1){
		ercd = hsd->status;
	}

	if(hsd->SdCmd == MCI_CMD18 || hsd->SdCmd == MCI_CMD17){	/* 読み出し処理待ち */
		dma_end(hsd->hdmarx);
		/*
		 *  受信ACTオフ待ち
		 */
		while((sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_STA)) & SDMMC_STA_RXACT) != 0 && timeout > 0){
			dly_tsk(1);
			timeout--;  
		}

		/*
		 *  マルチブロック転送ならCMD12を送信
		 */
		if(hsd->SdCmd == MCI_CMD18){
			tercd = sdmmc_sendcommand(hsd, MCI_CMD12, 0, sdmmc_checkrep1);
		}
		if(ercd == E_OK)
			ercd = tercd;
		if(timeout == 0 && ercd == E_OK)
			ercd = E_TMOUT;

		/*
		 *  転送フラグをクリア
		 */
		sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_ICR), SDMMC_STATIC_FLAGS);
	}
	else{	/* 書き込み待ち処理 */
		dma_end(hsd->hdmatx);
		/*
		 *  送信ACTオフ待ち
		 */
		while((sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_STA)) & SDMMC_STA_TXACT) != 0 && timeout > 0){
			dly_tsk(1);
			timeout--;
		}

		/*
		 *  マルチブロック転送ならCMD12を送信
		 */
		if(hsd->SdCmd == MCI_CMD25){
			tercd = sdmmc_sendcommand(hsd, MCI_CMD12, 0, sdmmc_checkrep1);
		}
		if(ercd == E_OK)
			ercd = tercd;
		if(timeout == 0 && ercd == E_OK)
			ercd = E_TMOUT;

		/*
		 *  転送フラグをクリア
		 */
		sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_ICR), SDMMC_STATIC_FLAGS);

		/*
		 *  送信終了待ち
		 */
		while(sdmmc_getstatus(hsd) != SD_TRANSFER_OK){
			dly_tsk(1);
		}
	}
	return ercd;
#endif
}

/*
 *  SDカード割込みテストルーチン
 *  parameter1  hsd: SDMMCハンドラ
 */
void
sdmmc_checkint(SDMMC_Handle_t *hsd)
{
#if 1
	return;
#else
	uint32_t status = sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_STA));

	/* データエンドを検証 */
	if((status & SDMMC_STA_DATAEND) != 0){
		sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_ICR), SDMMC_STA_DATAEND);
		hsd->status = 1;	/* 終了番号をセット */
	}
	else if((status & SDMMC_INT2_ERROR) != 0){
 		sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_ICR), (status & SDMMC_INT2_ERROR));
		hsd->status = E_SDTRS;
	}

	/* 割込みをマスク */
	sil_andw_mem((uint32_t *)(hsd->base+TOFF_SDIO_MASK), SDMMC_INT_MASK);
#endif
}


/*
 *  SDカードの情報を取り込む
 *  parameter1  hsd: SDMMCハンドラ
 *  parameter2  pCardInfo: カードインフォ構造体へのポインタ
 *  return      ERコード
 */
ER
sdmmc_getcardinfo(SDMMC_Handle_t *hsd, SDMMC_CardInfo_t *pCardInfo)
{
#if 1
	return E_OK;
#else
	ER ercd = E_OK;
	uint32_t devicesize;
	uint8_t  blocklen, mul;

	pCardInfo->cardtype = (uint8_t)(hsd->cardtype);
	pCardInfo->RCA      = (uint16_t)(hsd->RCA);

	if(hsd->cardtype == SD_CARD_V11 || hsd->cardtype == SD_CARD_V20){
		/* ブロック長を取り込む */
		blocklen       = (uint8_t)((hsd->CSD[1] & 0x000F0000) >> 16);
		devicesize = (hsd->CSD[1] & 0x000003FF) << 2;
		devicesize |= (hsd->CSD[2] & 0xC0000000) >> 30;
		mul = (hsd->CSD[2] & 0x00038000) >> 15;
		pCardInfo->capacity  = (devicesize + 1) ;
		pCardInfo->capacity *= (1 << (mul + 2));
		pCardInfo->blocksize = 1 << (blocklen);
		pCardInfo->capacity *= pCardInfo->blocksize;
	}
	else if(hsd->cardtype == SD_CARD_HC){
		devicesize = (hsd->CSD[1] & 0x0000003F) << 16;
		devicesize |= (hsd->CSD[2] & 0xFFFF0000) >> 16;
		pCardInfo->capacity  = (uint64_t)(devicesize + 1) << 19 /* 512 * 1024*/;
		pCardInfo->blocksize = 512;
	}
	else{
		pCardInfo->capacity  = 0;
		pCardInfo->blocksize = 512;
		ercd = E_OBJ;
	}
	pCardInfo->maxsector = pCardInfo->capacity / 512;
	pCardInfo->status    = (uint8_t)((hsd->CSD[3] >> 8) & 0xff);
#if 1	/* ROI DEBUG */
	syslog_1(LOG_NOTICE, "## status[%02x] ##", pCardInfo->status);
	syslog_5(LOG_NOTICE, "## cardtype(%d) capacity[%08x%08x] blocksize(%d) maxsector(%u) ##", pCardInfo->cardtype, (uint32_t)(pCardInfo->capacity>>32), (uint32_t)(pCardInfo->capacity & 0xffffffff), pCardInfo->blocksize, pCardInfo->maxsector);
#endif	/* ROI DEBUG */
	return ercd;
#endif
}

/*
 *  WIDE BUS設定
 *  parameter1  hsd: SDMMCハンドラ
 *  return      ERコード
 */
ER
sdmmc_set_widebus(SDMMC_Handle_t *hsd)
{
#if 1
	return E_OK;
#else
	ER ercd = E_OK;

	/* MMC Card does not support this feature */
	if(hsd->cardtype == MMC_CARD){
		return E_PAR;
	}
	else if(hsd->cardtype == SD_CARD_V11 || hsd->cardtype == SD_CARD_V20 || hsd->cardtype == SD_CARD_HC){
		if(hsd->BusWide == SDMMC_BUS_WIDE_8B)
			ercd = E_NOSPT;
		else if(hsd->BusWide == SDMMC_BUS_WIDE_4B)
			ercd = sdmmc_enable_widebus(hsd);
		else if(hsd->BusWide == SDMMC_BUS_WIDE_1B)
			ercd = sdmmc_disable_widebus(hsd);
		else
			ercd = E_PAR;
		if(ercd == E_OK){
			/*
			 *  最終ペリフェラル設定
			 */
			sil_modw_mem((uint32_t *)(hsd->base+TOFF_SDIO_CLKCR), CLKCR_CLEAR_MASK, ((hsd->ClockMode | hsd->BusWide)));
		}
	}
	return ercd;
#endif
}

/*
 *  CIDの取得
 *  SDカードCMD2,MMCカードCMD1送信後のレスポンス受信
 *  parameter1  hsd: SDMMCハンドラ
 *  return      ERコード
 */
ER
sdmmc_checkCID(SDMMC_Handle_t *hsd)
{
#if 1
	return E_OK;
#else
	ER  ercd = E_OK;
	int i;

	if((sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_POWER)) & SDMMC_POWER_PWRCTRL) == 0){
    	return E_OBJ;
	}

	if(hsd->cardtype == SD_IO_CARD)
		return E_OK;
	for(i = 0 ; i < hsd->RetryCount ; i++){
	    /*
		 *  CMD2送信
		 */
		ercd = sdmmc_sendcommand(hsd, MCI_CMD2, 0, sdmmc_checkrep2);
		if(ercd == E_OK){
			/*
			 *  CID取り込み
			 */
			hsd->CID[0] = sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_RESP));
			hsd->CID[1] = sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_RESP2));
			hsd->CID[2] = sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_RESP3));
			hsd->CID[3] = sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_RESP4));
			return E_OK;
		}
		sil_dly_nse(2000);
	}
	return ercd;
#endif
}

/*
 *  相対アドレス(RCA)の取得
 *  parameter1  hsd: SDMMCハンドラ
 *  return      ERコード
 */
ER
sdmmc_setaddress(SDMMC_Handle_t *hsd)
{
#if 1
	return E_OK;
#else
	ER       ercd = E_OK;
	int i;

	if(hsd->cardtype == SD_CARD_V11 || hsd->cardtype == SD_CARD_V20 ||
		hsd->cardtype == SD_IO_COMBO_CARD || hsd->cardtype == SD_CARD_HC){

		for(i = 0 ; i < hsd->RetryCount ; i++){
			/*
			 *  CMD3送信、RCA受信
			 */
			ercd = sdmmc_sendcommand(hsd, MCI_CMD3, 0, sdmmc_checkrep6);
		    if(ercd == E_OK)
				return E_OK;
			sil_dly_nse(2000);
		}
		return E_TMOUT;
	}
    hsd->RCA = 1;
	return ercd;
#endif
}

/*
 *  CSD(Card Specific DATA)の取得
 *  parameter1  hsd: SDMMCハンドラ
 *  return      ERコード
 */
ER
sdmmc_sendCSD(SDMMC_Handle_t *hsd)
{
#if 1
	return E_OK;
#else
	ER  ercd = E_OK;
	int i;

	if(hsd->cardtype == SD_IO_CARD)
		return E_OK;
	for(i = 0 ; i < hsd->RetryCount ; i++){
		/*
		 *  CMD9送信、CSD要求
		 */
		ercd = sdmmc_sendcommand(hsd, MCI_CMD9, (uint32_t)(hsd->RCA << 16), sdmmc_checkrep2);
		if(ercd == E_OK){
			/*
			 *  CSD取得
			 */
			hsd->CSD[0] = sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_RESP));
			hsd->CSD[1] = sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_RESP2));
			hsd->CSD[2] = sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_RESP3));
			hsd->CSD[3] = sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_RESP4));
			return E_OK;
		}
		sil_dly_nse(2000);
	}
	return ercd;
#endif
}

/*
 *  SELECT_CARDコマンドの送信
 *  parameter1  hsd: SDMMCハンドラ
 *  return      ERコード
 */
ER
sdmmc_select_card(SDMMC_Handle_t *hsd, uint64_t addr)
{
#if 1
	return E_OK;
#else
	ER  ercd = E_OK;
	int i;

	for(i = 0 ; i < hsd->RetryCount ; i++){
		/*
		 *  CMD7送信 カードセレクト
		 */
		ercd = sdmmc_sendcommand(hsd, MCI_CMD7, (uint32_t)addr, sdmmc_checkrep1);
		if(ercd == E_OK)
			return E_OK;
		sil_dly_nse(2000);
	}
	return ercd;
#endif
}

/*
 *  SDMMCコンフィギュレーション
 *  parameter1  hsd: SDMMCハンドラ
 *  return      ERコード
 */
ER
sdmmc_configuration(SDMMC_Handle_t *hsd)
{
#if 1
	return E_OK;
#else
	/*
	 *  最終コンフィギュレーション
	 */
	sil_modw_mem((uint32_t *)(hsd->base+TOFF_SDIO_CLKCR), CLKCR_CLEAR_MASK, ((hsd->ClockMode | SDMMC_BUS_WIDE_1B)));
	return E_OK;
#endif
}

/*
 *  SDカードステートを取得
 *  parameter1  hsd: SDMMCハンドラ
 *  return      カードステート
 */
uint32_t
sdmmc_getstatus(SDMMC_Handle_t *hsd)
{
#if 1
	return E_OK;
#else
	ER ercd = E_OK;
	uint32_t resp1 = 0;
	uint32_t cardstate = SD_CARD_TRANSFER;

	/*
	 *  CMD13送信
	 */
	ercd = sdmmc_sendcommand(hsd, MCI_CMD13, (uint32_t)(hsd->RCA << 16), sdmmc_checkrep1);
	if(ercd != E_OK){
		return ercd;
	}

	/*
	 *  SDカードステータス取り込み
	 */
	resp1 = sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_RESP));
	cardstate = ((resp1 >> 9) & 0x0F);

	/*
	 *  カードステータスをカードステートに変換
	 */
	if(cardstate == SD_CARD_TRANSFER){
		return SD_TRANSFER_OK;
	}
	else if(cardstate == SD_CARD_ERROR){
		return SD_TRANSFER_ERROR;
	}
	else{
		return SD_TRANSFER_BUSY;
	}
#endif
}

#if 0
/*
 *  WIDE BUSモード設定
 */
static ER
sdmmc_enable_widebus(SDMMC_Handle_t *hsd)
{
#if 1
	return E_OK;
#else
	ER ercd = E_OK;
	uint32_t scr[2];

	if((sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_RESP)) & SD_CARD_LOCKED) == SD_CARD_LOCKED){
		return E_OBJ;
	}
	dly_tsk(1);

	/* Get SCR Register */
	ercd = sdmmc_getSCR(hsd, scr);
	if(ercd != E_OK){
		return ercd;
	}

	/*
	 *  WIDE BUS設定処理
	 */
	if((scr[1] & SD_WIDE_BUS_SUPPORT) != 0){
		/*
		 *  CMD55送信(APPEDコマンド要求
		 */
		ercd = sdmmc_sendcommand(hsd, MCI_CMD55, (uint32_t)(hsd->RCA << 16), sdmmc_checkrep1);
		if(ercd != E_OK){
			return ercd;
		}

		/*
		 *  WIDE BUS設定でACMD6コマンド送信
		 */
		ercd = sdmmc_sendcommand(hsd, MCI_ACMD6, 2, sdmmc_checkrep1);
		return ercd;
	}
 	return E_OBJ;
#endif
}

/*
 *  WIDE BUSモード停止
 */
static ER
sdmmc_disable_widebus(SDMMC_Handle_t *hsd)
{
#if 1
	return E_OK;
#else
	ER ercd = E_OK;
	uint32_t scr[2];

	if((sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_RESP)) & SD_CARD_LOCKED) == SD_CARD_LOCKED){
		return E_SYS;
	}
	dly_tsk(1);

	/* Get SCR Register */
	ercd = sdmmc_getSCR(hsd, scr);
	if(ercd != E_OK){
		return ercd;
	}

	/*
	 *  1ビットバス設定処理
	 */
	if((scr[1] & SD_SINGLE_BUS_SUPPORT) != 0){
		/*
		 *  CMD55送信(APPEDコマンド要求
		 */
		ercd = sdmmc_sendcommand(hsd, MCI_CMD55, (uint32_t)(hsd->RCA << 16), sdmmc_checkrep1);
		if(ercd != E_OK){
			return ercd;
		}

		/*
		 *  1 BIT BUS設定でACMD6コマンド送信
		 */
		ercd = sdmmc_sendcommand(hsd, MCI_ACMD6, 0, sdmmc_checkrep1);
		return ercd;
	}
    return E_OBJ;
#endif
}

/*
 *  SCRの取得
 */
static ER
sdmmc_getSCR(SDMMC_Handle_t *hsd, uint32_t *pSCR)
{
#if 1
	return E_OK;
#else
	ER ercd = E_OK;
	uint32_t index = 0;
	uint32_t recvdata[2];

	/*
	 * 8バイトブロックサイズ設定
	 */
	ercd = sdmmc_sendcommand(hsd, MCI_CMD16, 8, sdmmc_checkrep1);
	if(ercd != E_OK){
		return ercd;
	}

	/*
	 *  CMD55送信(APPEDコマンド要求
	 */
	ercd = sdmmc_sendcommand(hsd, MCI_CMD55, (uint32_t)((hsd->RCA) << 16), sdmmc_checkrep1);
	if(ercd != E_OK){
		return ercd;
	}
	sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_DTIMER),0xFFFFFFFF);
	sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_DLEN), 8);
	sil_modw_mem((uint32_t *)(hsd->base+TOFF_SDIO_DCTRL), DCTRL_CLEAR_MASK,
				(SDMMC_DBSIZE_8B | SDMMC_DCTRL_DTDIR | SDMMC_DCTRL_DTEN));
  
	/*
	 *  ACMD51送信、SCR要求
	 */
	ercd = sdmmc_sendcommand(hsd, MCI_ACMD51, 0, sdmmc_checkrep1);
	if(ercd != E_OK){
		return ercd;
	}

	while((sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_STA)) & (SDMMC_INT1_ERROR | SDMMC_STA_DBCKEND)) == 0){
		if((sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_STA)) & SDMMC_STA_RXDAVL) != 0){
			*(recvdata + index) = sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_FIFO));
			index++;
		}
	}

	if((sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_STA)) & SDMMC_STA_DTIMEOUT) != 0){
		sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_ICR), SDMMC_STA_DTIMEOUT);
		return E_TMOUT;
	}
	else if((sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_STA)) & SDMMC_STA_DCRCFAIL) != 0){
		sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_ICR), SDMMC_STA_DCRCFAIL);
		return E_SDCRC;
	}
	else if((sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_STA)) & SDMMC_STA_RXOVERR) != 0){
		sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_ICR), SDMMC_STA_RXOVERR);
    	return E_SDTRS;
	}
	/*
	 *  スタティック・フラグをクリア
	 */
	sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_ICR), SDMMC_STATIC_FLAGS);

	*(pSCR + 1) = ((recvdata[0] & 0x000000FF) << 24)  | ((recvdata[0] & 0x0000FF00) << 8) |
		((recvdata[0] & 0x00FF0000) >> 8) | ((recvdata[0] & 0xFF000000) >> 24);

	*(pSCR) = ((recvdata[1] & 0x000000FF) << 24)  | ((recvdata[1] & 0x0000FF00) << 8) |
		((recvdata[1] & 0x00FF0000) >> 8) | ((recvdata[1] & 0xFF000000) >> 24);
	return E_OK;
#endif
}

/*
 *  プログラミングステートを取り出す
 */
static
ER sdmmc_getpstate(SDMMC_Handle_t *hsd, uint8_t *pStatus)
{
#if 1
	return E_OK;
#else
	volatile uint32_t respValue = 0;
	ER  ercd;

	sdmmc_sendcommand(hsd, MCI_CMD13, (uint32_t)(hsd->RCA << 16), NULL);
	ercd = sdmmc_command_wait(hsd);
	if(ercd != E_OK){
		return ercd;
	}
	if((sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_STA)) & SDMMC_STA_CTIMEOUT) != 0){
		sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_ICR), SDMMC_STA_CTIMEOUT);
		return E_TMOUT;
	}
	else if((sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_STA)) & SDMMC_STA_CCRCFAIL) != 0){
		sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_ICR), SDMMC_STA_CCRCFAIL);
		return E_SDCRC;
	}
	else{	/* エラーなし */
		/*
		 *  レスポンス・コマンド・インデックスの確認
		 */
		if((uint8_t)sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_RESPCMD)) != (MCI_CMD13 & CMD_INDEX)){
			return E_SDECMD;
		}
 
		/*
		 *  スタティック・フラグをクリア
	 	 */
		sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_ICR), SDMMC_STATIC_FLAGS);

		/*
		 *  レスポンス１を取得
		 */
		respValue = sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_RESP));

		/*
		 *  カードステータスを取り出す
		 */
		*pStatus = (uint8_t)((respValue >> 9) & 0x0000000F);

		/*
		 *  レスポンス１のエラーチェック
	 	 */
		if((respValue & SD_OCR_ERROR) == 0)
			return E_OK;
		else
			return E_SYS;
	}
#endif
}
#endif

/*
 *  SDMMC割込みハンドラ
 */
void sdmmc_handler(void)
{
#if 1
	return;
#else
	sdmmc_checkint(&SdHandle);
	isig_sem(SDMMC_SEM);
#endif
}


/*
 * SDMMCコマンド送信
 */
/*static*/ ER
sdmmc_sendcommand(SDMMC_Handle_t *hsd, uint32_t cmd, uint32_t arg, ER (*func)(SDMMC_Handle_t *, uint32_t))
{
#if 1
	ER ret = E_OK;
	volatile uint32_t i;

	gpio_cs_assert(1);
	spi_trans(0xFF);

	spi_trans((uint8_t)cmd);
	for (i = 0; i < 4; i++)
		spi_trans((uint8_t)(arg >> (8 * (3 - i))));
	spi_trans((cmd == MCI_CMD0) ? 0x95 : ((cmd == MCI_CMD8) ? 0x87 : 0x01));
	if(func != NULL){
		ret = func(hsd, cmd);
	}

	gpio_cs_assert(0);
	spi_trans(0xFF);

	return ret;
#else
	uint32_t addr = hsd->base;

	sil_wrw_mem((uint32_t *)(addr+TOFF_SDIO_ARG), arg);
	sil_modw_mem((uint32_t *)(addr+TOFF_SDIO_CMD), CMD_CLEAR_MASK, ((cmd & CMD_MASK) | SDMMC_CMD_CPSMEN));
	if(func != NULL){
		ER ercd = sdmmc_command_wait(hsd);
		if(ercd != E_OK){
			return ercd;
		}
		if((sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_STA)) & SDMMC_STA_CTIMEOUT) != 0){
			sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_ICR), SDMMC_STA_CTIMEOUT);
			return E_TMOUT;
		}
		return func(hsd, cmd);
	}
	else
		return E_OK;
#endif
}

/*
 *  R1レスポンス
 */
static ER
sdmmc_checkrep1(SDMMC_Handle_t *hsd, uint32_t Cmd)
{
#if 1
	ER ret = E_OK;
	volatile uint32_t i, j;
	uint32_t resp_len;
	uint8_t resp[5];

	resp_len = 1;

	for (j = 0; j < 8; j++)
	{
		resp[0] = spi_trans(0xFF);
		if ((resp[0] & 0x80) == 0x80) continue;
		for (i = 1; i < resp_len; i++)
			resp[i] = spi_trans(0xFF);
		break;
	}
	if (j == 8)
		return E_SYS;

	hsd->R1 = resp[0];

	return ret;
#else
	uint32_t respValue;

	if((sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_STA)) & SDMMC_STA_CCRCFAIL) != 0){
		sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_ICR), SDMMC_STA_CCRCFAIL);
		return E_SDCRC;
	}

	/*
	 *  レスポンス・コマンド・インデックス確認
	 */
	if((uint8_t)sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_RESPCMD)) != (Cmd & CMD_INDEX) && (Cmd & CMD_IGNOREIRES) == 0){
		return E_SDECMD;
	}

	/*
	 *  スタティック・フラグをクリア
	 */
	sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_ICR), SDMMC_STATIC_FLAGS);

	/*
	 *  レスポンス１のエラーチェック
	 */
	respValue = sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_RESP));
	if((respValue & SD_OCR_ERROR) == 0)
		return E_OK;
	else
		return E_SDCOM;
#endif
}

/*
 *  R7レスポンス
 */
static ER
sdmmc_checkrep7(SDMMC_Handle_t *hsd, uint32_t Cmd)
{
	ER ret = E_OK;
	volatile uint32_t i, j;
	uint32_t resp_len;
	uint8_t resp[5];

	resp_len = 5;

	for (j = 0; j < 8; j++)
	{
		resp[0] = spi_trans(0xFF);
		if ((resp[0] & 0x80) == 0x80) continue;
		for (i = 1; i < resp_len; i++)
			resp[i] = spi_trans(0xFF);
		break;
	}
	if (j == 8)
		return E_SYS;

	if ((resp[0] & 0x04) == 0x04)
	{
		hsd->cardtype = SD_CARD_V11;
	}
	else
	{
		hsd->cardtype = SD_CARD_V20;
		if (((resp[3] & 0x0F) != 0x01) || (resp[4] != 0xAA)) while (1) ;
	}

	hsd->R1 = resp[0];

	return ret;
}

/*
 *  R3レスポンス(SPI)
 */
static ER
sdmmc_checkrep3_spi(SDMMC_Handle_t *hsd, uint32_t Cmd)
{
	ER ret = E_OK;
	volatile uint32_t i, j;
	uint32_t resp_len;
	uint8_t resp[5];

	resp_len = 5;

	for (j = 0; j < 8; j++)
	{
		resp[0] = spi_trans(0xFF);
		if ((resp[0] & 0x80) == 0x80) continue;
		for (i = 1; i < resp_len; i++)
			resp[i] = spi_trans(0xFF);
		break;
	}
	if (j == 8)
		return E_SYS;

	hsd->R1 = resp[0];
	hsd->OCR = ((resp[1] << 24) | (resp[2] << 16) | (resp[3] << 8) | resp[4]);

	return ret;
}

#if 0
/*
 *  R2レスポンス
 */
static ER
sdmmc_checkrep2(SDMMC_Handle_t *hsd, uint32_t Cmd)
{
#if 1
	return E_OK;
#else
	if((sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_STA)) & SDMMC_STA_CCRCFAIL) != 0){
		sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_ICR), SDMMC_STA_CCRCFAIL);
		return E_SDCRC;
	}
	sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_ICR), SDMMC_STATIC_FLAGS);
	return E_OK;
#endif
}

/*
 *  R3レスポンス
 */
static ER
sdmmc_checkrep3(SDMMC_Handle_t *hsd, uint32_t Cmd)
{
#if 1
	return E_OK;
#else
	sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_ICR), SDMMC_STATIC_FLAGS);
	return E_OK;
#endif
}

/*
 *  R6レスポンス
 */
static ER
sdmmc_checkrep6(SDMMC_Handle_t *hsd, uint32_t Cmd)
{
#if 1
	return E_OK;
#else
	uint32_t respValue;

	if((sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_STA)) & SDMMC_STA_CCRCFAIL) != 0){
		sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_ICR), SDMMC_STA_CCRCFAIL);
		return E_SDCRC;
	}

	/*
	 *  レスポンス・コマンド・インデックス確認
	 */
	if((uint8_t)sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_RESPCMD)) != (Cmd & CMD_INDEX)){
		return E_SDECMD;
	}
	sil_wrw_mem((uint32_t *)(hsd->base+TOFF_SDIO_ICR), SDMMC_STATIC_FLAGS);

	/*
	 *  レスポンス１の確認
	 */
	respValue = sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_RESP));
	if((respValue & SD_R6_GENERAL_UNKNOWN_ERROR) == SD_R6_GENERAL_UNKNOWN_ERROR){
		return E_OBJ;
	}
	if((respValue & SD_R6_ILLEGAL_CMD) == SD_R6_ILLEGAL_CMD){
		return E_SDECMD;
	}
	if((respValue & SD_R6_COM_CRC_FAILED) == SD_R6_COM_CRC_FAILED){
		return E_SDCRC;
	}
    hsd->RCA = (uint16_t) (respValue >> 16);
	return E_OK;
#endif
}

/*
 *  コマンド転送待ち
 */
static ER
sdmmc_command_wait(SDMMC_Handle_t *hsd)
{
#if 1
	return E_OK;
#else
	int timeout = SDMMC_CMD0TIMEOUT;

	while((sil_rew_mem((uint32_t *)(hsd->base+TOFF_SDIO_STA)) & SDMMC_WAIT_STATUS) == 0){
		if(timeout == 0)
			return E_TMOUT;
		sil_dly_nse(1000);
		timeout--;
	}
	return E_OK;
#endif
}
#endif

/*
 *  STREAM DMA 割込みサービスルーチン
 */
void
stream_dma_isr(intptr_t exinf)
{
	sil_andw_mem(CHCR_0, 0x00000002);
	isig_sem(SDMMC_SEM);
}


