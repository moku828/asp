/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2010 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
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
 *      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
 *      ���դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
 * 
 *  @(#) $Id: sample1.c 1797 2010-06-07 04:24:19Z ertl-hiro $
 */

/* 
 *  ����ץ�ץ����(1)������
 *
 *  ASP�����ͥ�δ���Ū��ư����ǧ���뤿��Υ���ץ�ץ���ࡥ
 *
 *  �ץ����γ���:
 *
 *  �桼�����󥿥ե�������������ĥᥤ�󥿥����ʥ�����ID: MAIN_TASK��ͥ
 *  ����: MAIN_PRIORITY�ˤȡ�3�Ĥ�����¹Ԥ���륿�����ʥ�����ID:
 *  TASK1��TASK3�����ͥ����: MID_PRIORITY�ˤǹ�������롥�ޤ�����ư��
 *  ����2�äμ����ϥ�ɥ�ʼ����ϥ�ɥ�ID: CYCHDR1�ˤ��Ѥ��롥
 *
 *  ����¹Ԥ���륿�����ϡ�task_loop����롼�פ�¹Ԥ����٤ˡ���������
 *  �¹���Ǥ��뤳�Ȥ򤢤�魯��å�������ɽ�����롥
 *
 *  �����ϥ�ɥ�ϡ����Ĥ�ͥ���١�HIGH_PRIORITY��MID_PRIORITY��
 *  LOW_PRIORITY�ˤΥ�ǥ����塼���ž�����롥�ץ����ε�ưľ��ϡ�
 *  �����ϥ�ɥ����߾��֤ˤʤäƤ��롥
 *
 *  �ᥤ�󥿥����ϡ����ꥢ��I/O�ݡ��Ȥ����ʸ�����Ϥ�Ԥ���ʸ�����Ϥ�
 *  �ԤäƤ���֤ϡ�����¹Ԥ���륿�������¹Ԥ���Ƥ���ˡ����Ϥ��줿
 *  ʸ�����б�����������¹Ԥ��롥���Ϥ��줿ʸ���Ƚ����δط��ϼ����̤ꡥ
 *  Control-C�ޤ���'Q'�����Ϥ����ȡ��ץ�����λ���롥
 *
 *  '1' : �оݥ�������TASK1���ڤ괹����ʽ������ˡ�
 *  '2' : �оݥ�������TASK2���ڤ괹���롥
 *  '3' : �оݥ�������TASK3���ڤ괹���롥
 *  'a' : �оݥ�������act_tsk�ˤ�굯ư���롥
 *  'A' : �оݥ��������Ф��뵯ư�׵��can_act�ˤ�ꥭ��󥻥뤹�롥
 *  'e' : �оݥ�������ext_tsk��ƤӽФ�������λ�����롥
 *  't' : �оݥ�������ter_tsk�ˤ�궯����λ���롥
 *  '>' : �оݥ�������ͥ���٤�HIGH_PRIORITY�ˤ��롥
 *  '=' : �оݥ�������ͥ���٤�MID_PRIORITY�ˤ��롥
 *  '<' : �оݥ�������ͥ���٤�LOW_PRIORITY�ˤ��롥
 *  'G' : �оݥ�������ͥ���٤�get_pri���ɤ߽Ф���
 *  's' : �оݥ�������slp_tsk��ƤӽФ����������Ԥ��ˤ����롥
 *  'S' : �оݥ�������tslp_tsk(10��)��ƤӽФ����������Ԥ��ˤ����롥
 *  'w' : �оݥ�������wup_tsk�ˤ�굯�����롥
 *  'W' : �оݥ��������Ф��뵯���׵��can_wup�ˤ�ꥭ��󥻥뤹�롥
 *  'l' : �оݥ�������rel_wai�ˤ�궯��Ū���Ԥ�����ˤ��롥
 *  'u' : �оݥ�������sus_tsk�ˤ�궯���Ԥ����֤ˤ��롥
 *  'm' : �оݥ������ζ����Ԥ����֤�rsm_tsk�ˤ�������롥
 *  'd' : �оݥ�������dly_tsk(10��)��ƤӽФ��������ַв��Ԥ��ˤ����롥
 *  'x' : �оݥ��������㳰�ѥ�����0x0001���㳰�������׵᤹�롥
 *  'X' : �оݥ��������㳰�ѥ�����0x0002���㳰�������׵᤹�롥
 *  'y' : �оݥ�������dis_tex��ƤӽФ������������㳰��ػߤ��롥
 *  'Y' : �оݥ�������ena_tex��ƤӽФ������������㳰����Ĥ��롥
 *  'r' : 3�Ĥ�ͥ���١�HIGH_PRIORITY��MID_PRIORITY��LOW_PRIORITY�ˤΥ�
 *        �ǥ����塼���ž�����롥
 *  'c' : �����ϥ�ɥ��ư��Ϥ����롥
 *  'C' : �����ϥ�ɥ��ư����ߤ����롥
 *  'b' : ���顼��ϥ�ɥ��5�ø�˵�ư����褦ư��Ϥ����롥
 *  'B' : ���顼��ϥ�ɥ��ư����ߤ����롥
 *  'z' : �оݥ�������CPU�㳰��ȯ��������ʥ�������λ������ˡ�
 *  'Z' : �оݥ�������CPU��å����֤�CPU�㳰��ȯ��������ʥץ�����
 *        ��λ����ˡ�
 *  'V' : get_utm����ǽɾ���ѥ����ƥ�����2���ɤࡥ
 *  'v' : ȯ�Ԥ��������ƥॳ�����ɽ������ʥǥե���ȡˡ�
 *  'q' : ȯ�Ԥ��������ƥॳ�����ɽ�����ʤ���
 */

#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "sample1.h"

/*
 *  �����ӥ�������Υ��顼�Υ�����
 */
Inline void
svc_perror(const char *file, int_t line, const char *expr, ER ercd)
{
	if (ercd < 0) {
		t_perror(LOG_ERROR, file, line, expr, ercd);
	}
}

#define	SVC_PERROR(expr)	svc_perror(__FILE__, __LINE__, #expr, (expr))

/*
 *  �¹Լ¹Ԥ���륿�����ؤΥ�å������ΰ�
 */
char_t	message[3];

/*
 *  �롼�ײ��
 */
ulong_t	task_loop;		/* ��������ǤΥ롼�ײ�� */
ulong_t	tex_loop;		/* �㳰�����롼������ǤΥ롼�ײ�� */

/*
 *  �¹Լ¹Ԥ���륿����
 */
void task(intptr_t exinf)
{
	volatile ulong_t	i;
	int_t		n = 0;
	int_t		tskno = (int_t) exinf;
	const char	*graph[] = { "|", "  +", "    *" };
	char_t		c;

	SVC_PERROR(ena_tex());
	while (1) {
		syslog(LOG_NOTICE, "task%d is running (%03d).   %s",
										tskno, ++n, graph[tskno-1]);
		for (i = 0; i < task_loop; i++);
		c = message[tskno-1];
		message[tskno-1] = 0;
		switch (c) {
		case 'e':
			syslog(LOG_INFO, "#%d#ext_tsk()", tskno);
			SVC_PERROR(ext_tsk());
			assert(0);
		case 's':
			syslog(LOG_INFO, "#%d#slp_tsk()", tskno);
			SVC_PERROR(slp_tsk());
			break;
		case 'S':
			syslog(LOG_INFO, "#%d#tslp_tsk(10000)", tskno);
			SVC_PERROR(tslp_tsk(10000));
			break;
		case 'd':
			syslog(LOG_INFO, "#%d#dly_tsk(10000)", tskno);
			SVC_PERROR(dly_tsk(10000));
			break;
		case 'y':
			syslog(LOG_INFO, "#%d#dis_tex()", tskno);
			SVC_PERROR(dis_tex());
			break;
		case 'Y':
			syslog(LOG_INFO, "#%d#ena_tex()", tskno);
			SVC_PERROR(ena_tex());
			break;
#ifdef CPUEXC1
		case 'z':
			syslog(LOG_NOTICE, "#%d#raise CPU exception", tskno);
			RAISE_CPU_EXCEPTION;
			break;
		case 'Z':
			SVC_PERROR(loc_cpu());
			syslog(LOG_NOTICE, "#%d#raise CPU exception", tskno);
			RAISE_CPU_EXCEPTION;
			SVC_PERROR(unl_cpu());
			break;
#endif /* CPUEXC1 */
		default:
			break;
		}
	}
}

/*
 *  �¹Ԥ��Ƽ¹Ԥ���륿�����ѤΥ������㳰�����롼����
 */
void tex_routine(TEXPTN texptn, intptr_t exinf)
{
	volatile ulong_t	i;
	int_t	tskno = (int_t) exinf;

	syslog(LOG_NOTICE, "task%d receives exception 0x%04x.", tskno, texptn);
	for (i = 0; i < tex_loop; i++);

	if ((texptn & 0x8000U) != 0U) {
		syslog(LOG_INFO, "#%d#ext_tsk()", tskno);
		SVC_PERROR(ext_tsk());
		assert(0);
	}
}

/*
 *  CPU�㳰�ϥ�ɥ�
 */
#ifdef CPUEXC1

void
cpuexc_handler(void *p_excinf)
{
	ID		tskid;

	syslog(LOG_NOTICE, "CPU exception handler (p_excinf = %08p).", p_excinf);
	if (sns_ctx() != true) {
		syslog(LOG_WARNING,
					"sns_ctx() is not true in CPU exception handler.");
	}
	if (sns_dpn() != true) {
		syslog(LOG_WARNING,
					"sns_dpn() is not true in CPU exception handler.");
	}
	syslog(LOG_INFO, "sns_loc = %d sns_dsp = %d sns_tex = %d",
									sns_loc(), sns_dsp(), sns_tex());
	syslog(LOG_INFO, "xsns_dpn = %d xsns_xpn = %d",
									xsns_dpn(p_excinf), xsns_xpn(p_excinf));

	if (xsns_xpn(p_excinf)) {
		syslog(LOG_NOTICE, "Sample program ends with exception.");
		SVC_PERROR(ext_ker());
		assert(0);
	}

	SVC_PERROR(iget_tid(&tskid));
	SVC_PERROR(iras_tex(tskid, 0x8000U));
}

#endif /* CPUEXC1 */

/*
 *  �����ϥ�ɥ�
 *
 *  HIGH_PRIORITY��MID_PRIORITY��LOW_PRIORITY �γ�ͥ���٤Υ�ǥ����塼
 *  ���ž�����롥
 */
void cyclic_handler(intptr_t exinf)
{
	SVC_PERROR(irot_rdq(HIGH_PRIORITY));
	SVC_PERROR(irot_rdq(MID_PRIORITY));
	SVC_PERROR(irot_rdq(LOW_PRIORITY));
}
void cyclic_280us_handler(void)
{
}

/*
 *  ���顼��ϥ�ɥ�
 *
 *  HIGH_PRIORITY��MID_PRIORITY��LOW_PRIORITY �γ�ͥ���٤Υ�ǥ����塼
 *  ���ž�����롥
 */
void alarm_handler(intptr_t exinf)
{
	SVC_PERROR(irot_rdq(HIGH_PRIORITY));
	SVC_PERROR(irot_rdq(MID_PRIORITY));
	SVC_PERROR(irot_rdq(LOW_PRIORITY));
}

/*
 *  �ᥤ�󥿥���
 */
void main_task(intptr_t exinf)
{
	ER_UINT	ercd;

	SVC_PERROR(syslog_msk_log(LOG_UPTO(LOG_INFO), LOG_UPTO(LOG_EMERG)));
	syslog(LOG_NOTICE, "Sample program starts (exinf = %d).", (int_t) exinf);

	/*
	 *  ���ꥢ��ݡ��Ȥν����
	 *
	 *  �����ƥ����������Ʊ�����ꥢ��ݡ��Ȥ�Ȥ����ʤɡ����ꥢ��
	 *  �ݡ��Ȥ������ץ�Ѥߤξ��ˤϤ�����E_OBJ���顼�ˤʤ뤬���پ��
	 *  �ʤ���
	 */
	ercd = serial_opn_por(TASK_PORTID);
	if (ercd < 0 && MERCD(ercd) != E_OBJ) {
		syslog(LOG_ERROR, "%s (%d) reported by `serial_opn_por'.",
									itron_strerror(ercd), SERCD(ercd));
	}
	SVC_PERROR(serial_ctl_por(TASK_PORTID,
							(IOCTL_CRLF | IOCTL_FCSND | IOCTL_FCRCV)));


	/*
 	 *  �ᥤ��롼��
	 */
	while (1)
	{
		break;
	}

	syslog(LOG_NOTICE, "Sample program ends.");
	SVC_PERROR(ext_ker());
	assert(0);
}
