/*
 *	TOPPERS/ASP Kernel
 *		Toyohashi Open Platform for Embedded Real-Time Systems/
 *		Advanced Standard Profile Kernel
 *	
 *	Copyright (C) 2007 by Embedded and Real-Time Systems Laboratory
 *				Graduate School of Information Science, Nagoya Univ., JAPAN
 *	Copyright (C) 2007-2010 by Industrial Technology Institute,
 *								Miyagi Prefectural Government, JAPAN
 *	
 *	�嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *	�����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *	�ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *	(1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *		��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *		����������˴ޤޤ�Ƥ��뤳�ȡ�
 *	(2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *		�ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *		�ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *		��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *	(3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *		�ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *		�ȡ�
 *	  (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *		  �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *	  (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
 *		  ��𤹤뤳�ȡ�
 *	(4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *		������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 *		�ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *		ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
 *		���դ��뤳�ȡ�
 *	
 *	�ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *	���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *	���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *	�������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *	����Ǥ�����ʤ���
 *	
 *	$Id: target_config.h 1824 2010-07-02 06:50:03Z mit-kimai $
 */

/*
 *	�������åȰ�¸�⥸�塼���FRK-SH2A�ѡ�
 *
 *	�����ͥ�Υ������åȰ�¸���Υ��󥯥롼�ɥե����롥kernel_impl.h�Υ���
 *	���åȰ�¸���ΰ����դ��Ȥʤ롥
 */

#ifndef TOPPERS_TARGET_CONFIG_H
#define TOPPERS_TARGET_CONFIG_H

/*
 *	�������åȥ����ƥ�Υϡ��ɥ������񸻤����
 */
#include "frksh2a.h"

/*
 *	�ȥ졼�����˴ؤ�������
 */
#ifdef TOPPERS_ENABLE_TRACE
#include "logtrace/trace_config.h"

/*
 *	���Ϥ�������̤����
 *	��ɬ�פ˱�����asp/arch/logtrace/trace_dump.c��trace_print()��
 *	���б���������̤��ɵ����롣
 */
#define LOG_INH_ENTER			/*	 17(0x11)  */
#define LOG_INH_LEAVE			/*	145(0x91)  */
#define LOG_EXC_ENTER			/*	 22(0x16)  */
#define LOG_EXC_LEAVE			/*	150(0x96)  */

#endif /* TOPPERS_ENABLE_TRACE */

/*
 *	�������åȰ�¸��ʸ�����Ϥ˻��Ѥ���ݡ��Ȥ����
 */
#define TARGET_PUTC_PORTID 2

/*
 *	ASP�����ͥ�ư����Υ���ޥåפȴ�Ϣ�������
 */

/*
 *	�ǥե���Ȥ��󥿥�������ƥ������ѤΥ����å��ΰ�����
 */
/*  �����å�������  */
#ifdef ROM_BOOT				/*	ROM��  */
#define DEFAULT_ISTKSZ	  0x8000U
#else	/*	ROM_BOOT  */	/*	�ǥХå���	*/
#define DEFAULT_ISTKSZ	  0x2000U
#endif /*  ROM_BOOT  */

/*	�����å��ΰ���� */
#define DEFAULT_ISTK_BOTTOM		INNER_RAM_PAGE4_END

/*	�����å��ΰ����Ƭ���ϡʥ����å��ΰ����ǤϤʤ��Τǡ���ա� */
#define DEFAULT_ISTK	  (void *)(DEFAULT_ISTK_BOTTOM - DEFAULT_ISTKSZ)

#ifndef TOPPERS_MACRO_ONLY

/*
 *	�������åȥ����ƥ��¸�ν����
 */
extern void target_initialize(void);

/*
 *	�������åȥ����ƥ�ν�λ
 *
 *	�����ƥ��λ������˻Ȥ���
 */
extern void target_exit(void) NoReturn;

#endif /* TOPPERS_MACRO_ONLY */

/*
 *	���������Ԥ��Τ��������������SIL�Υ������åȰ�¸����
 */
#ifdef ROM_BOOT		/*	ROM���ξ��  */
#define SIL_DLY_TIM1	 75
#define SIL_DLY_TIM2	 21

#else				/*	RAM��ǥǥХå�������  */
#define SIL_DLY_TIM1	 1466
#define SIL_DLY_TIM2	  682

#endif


/*
 *	STBCR2��4�ν���͡ʳ�1�Х��ȡ�
 */
	/*
	 *	��H-UDI
	 *	����ROM���������
	 *	�����ǥХå�����ư��
	 *	��UBC�����
	 *	��DMAC�����
	 */
#ifdef ROM_BOOT		/*	ROM���ξ��  */
#define STBCR2_VALUE	 (STBCR2_HUDI | STBCR2_UCB | STBCR2_DMAC)
#else				/*	RAM��ǥǥХå�������  */
#define STBCR2_VALUE	 (STBCR2_UCB | STBCR2_DMAC)
#endif

	/*
	 *	����������ϥ⡼�ɻ���ü�Ҿ��֤��ݻ����롣
	 *	��MTU2S�����
	 *	��MTU2�����
	 *	��POE2�����
	 *	��IIC3�����
	 *	��ADC�����
	 *	��DAC�����
	 *	���ե�å�������ư��
	 */
#define STBCR3_VALUE	 (STBCR3_HZ | STBCR3_MTU2S | STBCR3_MTU2 | STBCR3_POE2 \
						  | STBCR3_IIC3 | STBCR3_ADC | STBCR3_DAC)

	/*
	 *	��SCFI0�����
	 *	��SCFI1��ư��
	 *	��SCFI2�����
	 *	��SCFI3�����
	 *	��CMT��ư��
	 *	��WAVEIF�����
	 */
#define STBCR4_VALUE	 (STBCR4_SCIF0 | STBCR4_SCIF2 |  STBCR4_SCIF3 | STBCR4_WAVEIF)


/*
 *  ����ߵ��Ĥ�ͭ���ˤʤ�ޤǤλ����Ԥ��򤹤뤿���nop̿��
 *  
 *  ��SH7211�ϰ���Ū�ʥ���å������¢���Ƥ��ʤ�����ˡ�
 *  ����¢�ե�å���ROM���Ф��ƤΤ�ͭ����ROM����å����
 *  ����¢���Ƥ��롣����ROM����å���Ͼ��ON�ǡ�OFF�ˤϤǤ��ʤ���
 *  �����Τ��ᡢENABLE_CACHE�ޥ���ǤϤʤ���ROM_BOOT�ޥ����
 *  ���Ѥ��ơ��ٱ��ɬ�פ�̿�����Ƚ�̤��Ƥ��롣
 */
#ifdef ROM_BOOT		/*  ROM����å���αƶ����������  */
	/*
	 *  ROM����å���θ��̤��θ
	 *  ����CPU����INTC����ã�����ޤǤ��ٱ�
	 *  �����ʥ����ѥ������3I��cycʬ��6̿��� 
	 */

	/*  �ǥ����ѥå�����  */
#define LDC_NOP_DISPATCHER		nop; nop; nop; nop; nop; nop

	/*  set_sr�ѡ����Υ������åȤǤ�ɬ�פʤ�  */
// #define LDC_NOP_SET_SR			"nop; nop"

	/*  TOPPERS_set_iipm�Ѥ�target_sil.h�˵��Ҥ��롣  */

#endif	/*  ROM_BOOT  */

/*
 *	�ץ��å���¸�⥸�塼���SH7262�ѡ�
 */
#include "sh12a_gcc/sh7262_config.h"

#endif	/* TOPPERS_TARGET_CONFIG_H */
