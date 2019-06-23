/*
 *	TOPPERS/ASP Kernel
 *		Toyohashi Open Platform for Embedded Real-Time Systems/
 *		Advanced Standard Profile Kernel
 *	
 *	Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *								Toyohashi Univ. of Technology, JAPAN
 *	Copyright (C) 2005-2007 by Embedded and Real-Time Systems Laboratory
 *				Graduate School of Information Science, Nagoya Univ., JAPAN
 *	Copyright (C) 2001-2009 by Industrial Technology Institute,
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
 *	$Id: prc_config.c 2216 2011-08-08 02:41:49Z mit-kimai $
 */

/*
 *		�ץ��å���¸�⥸�塼���SH12A�ѡ�
 */

#include "kernel_impl.h"
#include "check.h"
#include "task.h"

/*
 * ����ƥ����Ȼ��ȤΤ�����ѿ�
 */
uint32_t excnest_count; /* �㳰�ʳ����/CPU�㳰�ˤΥͥ��Ȳ���Υ������ */

/*
 *	CPU��å��ե饰�¸��Τ�����ѿ�
 */
bool_t		lock_flag;		/* CPU��å��ե饰���ͤ��ݻ������ѿ� */
uint32_t	saved_iipm;		/* �����ͥ���٥ޥ�������¸�����ѿ� */

/*
 *	�Ƴ�����ֹ����IPR�ξ�������ơ��֥�
 *	���Ƥ�����ϡ��ץ��å�������˰ۤʤ�Τ��ᡤ
 *	�ץ��å������������ե�������������
 */
const IPR_INFO ipr_info_tbl[TNUM_INH] = {
	IPR_INFO_TBL_DATA
};

/*
 *	�����ͥ�Υ٥���
 */
extern const FP vectors;

/*
 *	�ץ��å���¸�ν����
 */
void
prc_initialize(void)
{
   /*
	*  �����ͥ뵯ư�����󥿥�������ƥ����ȤȤ���ư����뤿�ᡢ
	*  1�ˤ��Ƥ�����
	*/
	excnest_count = 1U;
	
	/*
	 *	CPU��å��ե饰�¸��Τ�����ѿ��ν����
	 */
	lock_flag = true;
	saved_iipm = IIPM_ENAALL;
	
	/*
	 *	����ߥ���ȥ���ν����
	 *	�ץ��å�����������
	 */
	irc_initialize();

	/*
	 *	�٥������١����쥸�����ν����
	 */
	set_vbr(&vectors);
}

/*
 *	�ץ��å���¸�ν�λ����
 */
void
prc_exit(void)
{
	extern void    software_term_hook(void);
	void (*volatile fp)(void) = software_term_hook;

	/*
	 *	software_term_hook�ؤΥݥ��󥿤򡤰�övolatile����Τ���fp����
	 *	�����Ƥ���Ȥ��Τϡ�0�Ȥ���Ӥ���Ŭ���Ǻ������ʤ��褦�ˤ��뤿
	 *	��Ǥ��롥
	 */
	if (fp != 0) {
		(*fp)();
	}
}

/*
 *	������׵�饤��°��������
 */
void
x_config_int(INTNO intno, ATR intatr, PRI intpri)
{
	assert(VALID_INTNO_CFGINT(intno));

	/*
	 *	��ö����ߤ�ػߤ���
	 */
	if(intno != TINTNO_NMI) {
		assert((-15 <= intpri) && (intpri <= TMAX_INTPRI));
		(void)x_disable_int(intno);
	}

	/*
	 *	��٥�ȥꥬ/���å��ȥꥬ������
	 */
	x_config_intatr(intno, intatr);

	/*
	 *	������׵�ޥ������(ɬ�פʾ��)
	 *	Ʊ���˳����ͥ���٤⥻�åȤ����
	 */
	if ((intno != TINTNO_NMI) && ((intatr & TA_ENAINT) != 0U)) {
		(void) x_enable_int(intno);
	}
}


/*
 * CPU�㳰�ϥ�ɥ�ν����
 * �����ޥ���ˤ���������asp/kernel/exception.h�ǥץ�ȥ��������
 * ������Ƥ��뤿�ᡢ�ؿ��Ȥ���������ʤ���Фʤ�ʤ���
 */
void
initialize_exception(void)
{
	/* ���⤷�ʤ� */
}

#ifndef OMIT_DEFAULT_EXC_HANDLER
/*
 *	��Ͽ����Ƥ��ʤ��㳰��ȯ������ȸƤӽФ����
 */
void
default_exc_handler(void *p_excinf)
{
	uint32_t *sp	= (uint32_t*)p_excinf;
	uint32_t vector = *(sp + P_EXCINF_OFFSET_VECTOR);
	uint32_t pc 	= *(sp + P_EXCINF_OFFSET_PC);
	uint32_t sr 	= *(sp + P_EXCINF_OFFSET_SR);
	uint32_t pr 	= *(sp + P_EXCINF_OFFSET_PR);
	uint32_t *sp_val = sp + P_EXCINF_OFFSET_SP;
	uint32_t reg, i;
	char 	 *msg;
	
	switch(vector) {
		case GENERAL_ILLEGAL_INSTRUCTION_VECTOR:
			msg = "General illegal instruction exception occurs.";
			break;
		case RAM_ERROR_VECTOR:
			msg = "RAM error exception occurs.";
			break;
		case SLOT_ILLEGAL_INSTRUCTION_VECTOR:
			msg = "Slot illegal instruction exception occurs.";
			break;
		case CPU_ADDRESS_ERROR_VECTOR:
			msg = "CPU address error exception occurs.";
			break;
		case DMA_ADDRESS_ERROR_VECTOR:
			msg = "DMA address error exception occurs.";
			break;

#ifdef FPU_VECTOR
		case FPU_VECTOR:
			msg = "FPU exception occurs.";
			break;
#endif /*  FPU_VECTOR  */

#ifdef SH2A
		case BANK_OVER_FLOW_VECTOR:
			msg = "Bank over flow exception occurs.";
			break;
		case BANK_UNDER_FLOW_VECTOR:
			msg = "Bank under flow exception occurs.";
			break;
#endif /*  SH2A  */

		default:
   			msg = "Unregistered exception occurs.";
   			break;
   	}
	syslog_1(LOG_EMERG, "%s", msg);

	syslog_3(LOG_EMERG, "VectorNo = %d PC = 0x%08x SP = 0x%08p",
		   vector, pc, sp_val);
	syslog_2(LOG_EMERG, "SR = 0x%08x PR=0x%08x", sr, pr);
	for(i = 0; i < 8; ++i) {
		reg = *(sp + P_EXCINF_OFFSET_R0 + i);
		syslog_2(LOG_EMERG, " r%d=0x%08x", i, reg);
	}
	target_exit();
}
#endif /* OMIT_DEFAULT_EXC_HANDLER */

#ifndef OMIT_DEFAULT_INT_HANDLER
/*
 *	̤��Ͽ�γ���ߤ�ȯ���������˸ƤӽФ����
 */
void
default_int_handler(INTNO intno)
{
	syslog_0(LOG_EMERG, "Unregistered Interrupt occurs.");
	syslog_1(LOG_EMERG, "INTNO = %d",intno);
	target_exit();
}
#endif /* OMIT_DEFAULT_INT_HANDLER */
