/*
 *	TOPPERS/ASP Kernel
 *		Toyohashi Open Platform for Embedded Real-Time Systems/
 *		Advanced Standard Profile Kernel
 *	
 *	Copyright (C) 2007 by Embedded and Real-Time Systems Laboratory
 *				Graduate School of Information Science, Nagoya Univ., JAPAN
 *	Copyright (C) 2007-2011 by Industrial Technology Institute,
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
 *	$Id: sh2a_config.h 2157 2011-07-19 06:25:30Z mit-kimai $
 */

/*
 *		�ץ��å���¸�⥸�塼���SH2A�ѡ�
 *
 *	���Υ��󥯥롼�ɥե�����ϡ�sh7xxx_config.h�ʤޤ��ϡ��������饤��
 *	�롼�ɤ����ե�����ˤΤߤ��饤�󥯥롼�ɤ���롥¾�Υե����뤫��
 *	ľ�ܥ��󥯥롼�ɤ��ƤϤʤ�ʤ���
 */

#ifndef TOPPERS_SH2A_CONFIG_H
#define TOPPERS_SH2A_CONFIG_H

/*  sh7xxx_config.h��target_config.h���饤�󥯥롼�ɤ����  */
#ifndef TOPPERS_TARGET_CONFIG_H
#error  sh7xxx_config.h(target_config.h) is not included!
#endif	/*  TOPPERS_TARGET_CONFIG_H  */

/*
 *	�����μ���
 */
#define SH2A

/*
 *	���ѤǤ���̿�᥻�å�
 *	��SH1��̿��ˤĤ��Ƥϡ����٤ƤΥ����ǥ��ݡ��Ȥ����Τǡ�
 *	��������ʤ���
 */
#define TOPPERS_SUPPORT_SH2_INSTRUCTION
#define TOPPERS_SUPPORT_SH2E_INSTRUCTION
#define TOPPERS_SUPPORT_SH2A_INSTRUCTION

/*
 *	NMI�γ�����ֹ�
 */
#define TINTNO_NMI					NMI_VECTOR

/*
 *	IRQ����ߤ��ɤ�����Ƚ�ꤹ�뤿��Υޥ���
 *	��prc_config.h��������٤����������Υե��������x_config_intatr()
 *	���ǻ��Ѥ��뤿�ᡢ�����˵��Ҥ��Ƥ��롣
 */
#define INTNO_IS_IRQ(intno) 								\
		((TMIN_INTNO_IRQ <= (intno)) && ((intno) <= TMAX_INTNO_IRQ))

/*
 *	������ֹ椫��IRQ�ֹ�ؤ��Ѵ�
 */
#define INTNO_TO_IRQNO(intno) (((intno) - TMIN_INTNO_IRQ))


#ifndef TOPPERS_MACRO_ONLY

#include <sil.h>

/*
 * IRC�ν����
 */
Inline void
irc_initialize(void)
{
	sil_wrh_mem((uint16_t *)ICR0_h, 0x0000U);
	sil_wrh_mem((uint16_t *)ICR1_h, 0x0000U);
	
#ifdef USE_BANKED_REG
	/*
	 * ��NMI,UBC�ʳ��Τ��٤Ƥγ���ߤǥ쥸�����Х󥯤λ��Ѥ����
	 * ������BE�ӥå�=01��IBCR�������̵��
	 * ���쥸�����Х󥯡������С��ե��㳰�����
	 */
	sil_wrh_mem((uint16_t *)IBNR_h, (IBNR_BE0 | IBNR_BOVE));
#else
	/* �쥸�����Х󥯻��Ѷػ� */
	sil_wrh_mem((uint16_t *)IBNR_h, 0x0000U);
#endif /* USE_BANKED_REG */

	init_ipr();	/*	�����ͥ���٥�����쥸�����ν����  */
}


/*
 *	����ߤ�°������
 */
Inline void
x_config_intatr(INTNO intno, ATR intatr)
{
	/*
	 *	IRQ�Τߥ��ݡ��Ȥ���
	 */
	if(INTNO_IS_IRQ(intno)){
		uint32_t icr1_val = sil_reh_mem((uint16_t *)ICR1_h);
		uint32_t offset   = INTNO_TO_IRQNO(intno) * 2U;

		/*
		 *	���å��ȥꥬ�λ��꤬�ʤ���С��ǥե���Ȥǥ���٥�ȥꥬ
		 *	�Ȥ��롣
		 *	�����ӥåȤ򥯥ꥢ�����ޤޤǤ���С�����٥�ȥꥬ�Ȥʤ롣
		 */
		icr1_val &=  ~(0x03U << offset);
		
		if((intatr & TA_POSEDGE) != 0U) {
			/*
			 *	�ݥ��ƥ��֥��å�
			 */
			icr1_val |= IRQ_POSEDGE << offset;
		}

		/*
		 *	���å��ȥꥬ�ǡ������λ��꤬�ʤ���С��ͥ��ƥ��֥��å�
		 *	�Ȥ��롣
		 */
		if(((intatr & TA_NEGEDGE) != 0U) ||
		   (((intatr & TA_EDGE) != 0U) && ((intatr & TA_BOTHEDGE) == 0U))) {
			/*
			 *	�ͥ��ƥ��֥��å�
			 */
			icr1_val |= IRQ_NEGEDGE << offset;
		}
		
		sil_wrh_mem((uint16_t *)ICR1_h, icr1_val);
	}
}

/*
 *	����ߥϥ�ɥ�������ɬ�פ�IRC���
 *
 *	IRQ����ߤǤ��ĥ��å��ȥꥬ�ξ��ϳ�����׵�򥯥ꥢ���롥
 *	���å��ȥꥬ����٥�ȥꥬ����Ƚ�̤���ȥ����С��إåɤ��礭���Τǡ�
 *	��˥��ꥢ���롥
 *	�ʥ�٥�ȥꥬ�ǥ��ꥢ�����򤷤ƤⳲ�Ϥʤ�����
 *
 *	IRQRR�쥸��������١����ߡ��꡼�ɤ��ơ� �����ӥåȤ�0��񤭹��ࡣ
 *	���δ֡�������ߥ�å����֤ˤ��Ƥ���Τϡ��ʲ��Τ褦�ʥ��������ɤ�
 *	���ᡣ
 *
 *	3����γ���ߤ�ͤ��롣
 *	�����ͥ���٤ϡ�l > m > n�ν�Ȥ��롣
 *	�ʳ����l��ͥ���٤��⤤����
 *	
 *	1.	m�γ���ߤ�ȯ��(m�ӥåȤ����å�)
 *	2.	m�γ���ߥϥ�ɥ餬�¹�(n�ϳ���߶ػ�)
 *	3.	IRQRR�꡼��(l = 0, m = 1, n = 0)
 *	4.	l�γ���ߤ�ȯ��(l�ӥåȤ����å�)
 *	5.	l�γ���ߥϥ�ɥ餬�¹�(n�ϳ���߶ػ�)
 *	6.	n�γ���ߤ�ȯ������α��(n�ӥåȤ����å�)
 *	7.	IRQRR�꡼��(l = 1, m = 1, n = 1)
 *	8.	IRQRR�饤��(l = 0, m = 1, n = 1)
 *	9.	l�γ���ߥϥ�ɥ齪λ
 *	10. m�γ���ߥϥ�ɥ�Ƴ�
 *	11. IRQQ�饤��(l = 0, m = 0, n = 0)
 *	
 *	11���ʳ��� n �����ꥢ������ǽ�������롥
 */
Inline void
i_begin_int(INTNO intno)
{
	SIL_PRE_LOC;
	uint32_t irqpr, bitptn;
	if (INTNO_IS_IRQ(intno)) {
		/*
		 * ���١����ߡ��꡼�ɤ��ơ� �����ӥåȤ�0��񤭹��ࡣ
		 *	���ѿ�bitptn���Ѥ��Ƥ���Τϡ�������ߥ�å��ζ�֤�
		 *	��û�����뤿��
		 */
		bitptn = ~(0x01U << INTNO_TO_IRQNO(intno));
		SIL_LOC_INT();
		irqpr = sil_reh_mem((uint16_t *)IRQRR_h);
		irqpr &= bitptn;
		sil_wrh_mem((uint16_t *)IRQRR_h, irqpr);
		SIL_UNL_INT();
	}
}

#endif /* TOPPERS_MACRO_ONLY */

/*
 *	�ץ��å���¸�⥸�塼���SH12A�ѡ�
 */
#include "sh12a_gcc/prc_config.h"

#endif /* TOPPERS_SH2A_CONFIG_H */
