/*
 *	TOPPERS/ASP Kernel
 *		Toyohashi Open Platform for Embedded Real-Time Systems/
 *		Advanced Standard Profile Kernel
 *	
 *	Copyright (C) 2007 by Embedded and Real-Time Systems Laboratory
 *				Graduate School of Information Science, Nagoya Univ., JAPAN
 *	Copyright (C) 2010-2011 by Industrial Technology Institute,
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
 *	$Id: prc_cmt.c 2144 2011-06-29 07:57:57Z mit-kimai $
 */

/*
 *	�����ޥɥ饤�С�SH12A�ѡ�
 *	
 *	CMT0�����
 */

#include "kernel_impl.h"
#include "time_event.h"
#include <sil.h>
#include "target_timer.h"

/*
 *  �����ޥ�������
 */
Inline void
target_timer_start(void)
{
	/* CMT0�������� */
	sil_orh_reg((uint16_t *)CMSTR_h, CMSTR_STR0);
}

/*
 *  ���������
 */
Inline void
target_timer_stop(void)
{
	/* CMT0��� */
	sil_anh_reg((uint16_t *)CMSTR_h, ~CMSTR_STR0);
}

/*
 *  �����޳�����׵�򥯥ꥢ
 */
Inline void
target_timer_clear_int(void)
{
	sil_anh_reg((uint16_t *)CMCSR_0_h, ~CMCSR_CMF);
}

/*
 *	�����ޤε�ư����
 */
void
target_timer_initialize(intptr_t exinf)
{
	CLOCK	 cyc = TO_CLOCK(TIC_NUME, TIC_DENO);

	/*
	 *	�����޼��������ꤷ�������ޤ�ư��򳫻Ϥ��롥
	 */
	target_timer_stop();		/* ��������� */

	assert(cyc <= MAX_CLOCK);	/* �����޾���ͤΥ����å� */

	/* ʬ��������(PCLOCK/8)������ߵ��� */
	sil_wrh_mem((uint16_t *)CMCSR_0_h, (CMCSR_CKS | CMCSR_CMIE));

	/*constant�쥸�����򥻥å� */
	sil_wrh_mem((uint16_t *)CMCOR_0_h, cyc);

	target_timer_clear_int();	/* ������׵�򥯥ꥢ */
	target_timer_start();		/* �����ޥ������� */
}

/*
 *	�����ޤ���߽���
 */
void
target_timer_terminate(intptr_t exinf)
{
	target_timer_stop();		/* ��������� */
	target_timer_clear_int();	/* ������׵�򥯥ꥢ */
}

/*
 *	�����޳���ߥϥ�ɥ�
 */
void
target_timer_handler(void)
{
	target_timer_clear_int();	/* ������׵�򥯥ꥢ */
	
	i_begin_int(INTNO_TIMER);
	signal_time();				/* ������ƥ��å��ζ��� */
	i_end_int(INTNO_TIMER);
}
