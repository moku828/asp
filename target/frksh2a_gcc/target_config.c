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
 *	$Id: target_config.c 2142 2011-06-27 07:24:40Z mit-kimai $
 */

/*
 *	�������åȰ�¸�⥸�塼���FRK-SH2A�ѡ�
 */

#include "kernel_impl.h"
#include <sil.h>
#include "pdic/sh/sh_scif.h"
#include "frksh2a.h"

/*
 *	�������åȰ�¸�ν����
 */
void
target_initialize(void)
{
	/*
	 *	�ץ��å���¸�ν����
	 */
	prc_initialize();

	/*
	 *	LED��³�ݡ��Ȥν����
	 */
	sil_wrh_mem((uint16_t *)PCCR2_h, sil_reh_mem((uint16_t *)PCCR2_h) & ~0x0003);
	
	/*
	 *	SCIF3��I/O�ݡ��Ȥ�����
	 */
	sil_wrh_mem((uint16_t *)PFCR1_h, (sil_reh_mem((uint16_t *)PFCR1_h) & ~0x0007) | 0x0004);
	sil_wrh_mem((uint16_t *)PFCR0_h, (sil_reh_mem((uint16_t *)PFCR0_h) & ~0x7000) | 0x4000);
	
	/*
	 *	SCIF2��I/O�ݡ��Ȥ�����
	 */
	sil_wrh_mem((uint16_t *)PFCR0_h, (sil_reh_mem((uint16_t *)PFCR0_h) & ~0x0770) | 0x0440);
	
	/*
	 * �С��ʡ������ѤΥ��ꥢ�륳��ȥ���ν����
	 */
	sh_scif_init(TARGET_PUTC_PORTID);
}

/*
 *	�������åȰ�¸�ν�λ����
 */
void
target_exit(void)
{
	/*
	 *	�ץ��å���¸�ν�λ����
	 */
	prc_exit();

	/*
	 *	��ȯ�Ķ���¸�ν�λ����
	 */
	frksh2a_exit();

	/*
	 * �����ˤ���ʤ�
	 */
	while(1);
}


/*
 *   �����ƥ�ʸ��������λ���
 */
#ifndef TOPPERS_HEW_SIMULATOR

#define TARGET_PUT_CHAR(c)	sh_scif_pol_putc(c, TARGET_PUTC_PORTID)

#else	/* TOPPERS_HEW_SIMULATOR */

extern void hew_io_sim_putc(char_t c);
#define TARGET_PUT_CHAR(c)	hew_io_sim_putc(c)

/*  ��ǽ������  */
#define GETC	0x01210000
#define PUTC	0x01220000

/*
 *   HEW��I/O���ߥ�졼�����ǽ�ƤӽФ�
 */
void hew_io_sim(uint32_t code, void *adr);

void hew_io_sim_putc(char_t c)
{
	uint8_t buf = (uint8_t)c;		/*  �Хåե�  */
	uint8_t *parmblk = &buf;		/*  �ѥ�᡼���֥�å�  */
	uint8_t **p = &parmblk;			/*  ������������Ƭ���ɥ쥹  */
	uint32_t code = PUTC;			/*  ��ǽ������  */
	
	hew_io_sim(code, p);
}

extern bool_t hew_io_sim_snd_chr(char_t c);

bool_t hew_io_sim_snd_chr(char_t c)
{
	hew_io_sim_putc(c);
	return true;
}

extern int_t hew_io_sim_rcv_chr(void);

int_t hew_io_sim_rcv_chr(void) {
	uint8_t buf;					/*  �Хåե�  */
	uint8_t *parmblk = &buf;		/*  �ѥ�᡼���֥�å�  */
	uint8_t **p = &parmblk;			/*  ������������Ƭ���ɥ쥹  */
	uint32_t code = GETC;			/*  ��ǽ������  */
	
	hew_io_sim(code, p);
	return(buf);
}

#endif /* TOPPERS_HEW_SIMULATOR */

/*
 *	�����ƥ�������٥���ϤΤ����ʸ������
 */
void
target_fput_log(char_t c)
{
	if (c == '\n') {
		TARGET_PUT_CHAR('\r');
	}
	TARGET_PUT_CHAR(c);
}
