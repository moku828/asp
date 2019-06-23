/*
 *	TOPPERS Software
 *		Toyohashi Open Platform for Embedded Real-Time Systems
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
 *	$Id: prc_sil.h 2217 2011-08-09 04:23:20Z mit-kimai $
 */

/*
 *	sil.h�Υץ��å���¸����SH12A�ѡ�
 */

#ifndef TOPPERS_PRC_SIL_H
#define TOPPERS_PRC_SIL_H

#ifndef TOPPERS_MACRO_ONLY

/*
 *	NMI��������٤Ƥγ���ߤζػ�
 */
Inline uint32_t
TOPPERS_disint(void)
{
	uint32_t  TOPPERS_sr, TOPPERS_local_iipm;

	Asm("stc  sr,%0" : "=r"(TOPPERS_sr));
	/*
	 *	������TOPPERS_local_iipm����Ƥ���Τϡ�
	 *	SIL_UNL_INT��ľ���SIL_LOC_INT��¹Ԥ�������ɬ�פ�
	 *	��������nop̿��ο���LDC_NOP_SIL_SET_IIPM�ˤ����ʤ���
	 *	�Ѥ�褦�ˤ��뤿��λ��ֲԤ�
	 */
	TOPPERS_local_iipm = TOPPERS_sr & 0x000000f0U;
	Asm("ldc %0, sr" : : "r"(TOPPERS_sr | 0x000000f0U) : "memory", "t");
	return(TOPPERS_local_iipm);
}

/*
 *	�����ͥ���٥ޥ���������ɽ���ˤθ����ͤ�����
 */
Inline void
TOPPERS_set_iipm(uint32_t TOPPERS_iipm)
{
	uint32_t  TOPPERS_sr;

	Asm("stc  sr,%0" : "=r"(TOPPERS_sr));
	Asm("ldc %0, sr;"
#ifdef LDC_NOP_SIL_SET_IIPM
		LDC_NOP_SIL_SET_IIPM		/*  CPU����INTC����ã�����ޤǤ��ٱ�  */
#endif /* LDC_NOP_SIL_SET_IIPM */
		: : "r"((TOPPERS_sr & ~0x000000f0U) | TOPPERS_iipm) : "memory", "t");
}

/*
 *	������ߥ�å����֤�����
 */
#define SIL_PRE_LOC 	 uint32_t TOPPERS_iipm
#define SIL_LOC_INT()	 ((void)(TOPPERS_iipm = TOPPERS_disint()))
#define SIL_UNL_INT()	 (TOPPERS_set_iipm(TOPPERS_iipm))

/*
 *  ����ǥ������ȿž
 */
Inline uint16_t toppers_sil_rev_endian_uint16(uint16_t src)
{
	uint16_t dst;
	Asm("swap.b %1, %0" : "=r"(dst) : "r"(src) );
	return dst;
}

#define	TOPPERS_SIL_REV_ENDIAN_UINT16(data) \
		toppers_sil_rev_endian_uint16(data)

Inline uint32_t toppers_sil_rev_endian_uint32(uint32_t src)
{
	uint32_t dst;
	Asm("swap.b %1, %0 \n"		/*  0x1234��0x1243  */
		"swap.w %0, %0 \n" 		/*  0x1243��0x4312  */
		"swap.b %0, %0"			/*  0x4312��0x4321  */
		: "=r"(dst) : "r"(src) );
	return dst;
}

#define	TOPPERS_SIL_REV_ENDIAN_UINT32(data) \
		toppers_sil_rev_endian_uint32(data)


/*
 *	�쥸�������Ф��������黻
 *	
 *	������饤��ؿ��ˤ��ʤ��ǡ��ޥ���ؿ��ˤ��Ƥ���Τϡ�
 *	�����λ�����sil_rex_mem,sil_wrx_mem���������Ƥ��ʤ����ᡣ
 */

/*
 *	8�ӥåȡ��쥸������OR�黻
 *   void sil_orb_reg(uint8_t *p_reg, uint8_t bitptn);
 */
#define sil_orb_reg(p_reg, bitptn)				\
{												\
	uint8_t reg_val = sil_reb_mem(p_reg);		\
												\
	reg_val |= (uint8_t)(bitptn);				\
	sil_wrb_mem(p_reg, reg_val);				\
}

/*
 *	8�ӥåȡ��쥸������AND�黻
 *   void sil_anb_reg(uint8_t *p_reg, uint8_t bitptn);
 */
#define sil_anb_reg(p_reg, bitptn)				\
{												\
	uint8_t reg_val = sil_reb_mem(p_reg);		\
												\
	reg_val &= (uint8_t)(bitptn);				\
	sil_wrb_mem(p_reg, reg_val);				\
}

/*
 *	16�ӥåȡ��쥸������OR�黻
 *   void sil_orh_reg(uint16_t *p_reg, uint16_t bitptn);
 */
#define sil_orh_reg(p_reg, bitptn)				\
{												\
	uint16_t reg_val = sil_reh_mem(p_reg);		\
												\
	reg_val |= (uint16_t)(bitptn);				\
	sil_wrh_mem(p_reg, reg_val);				\
}


/*
 *	16�ӥåȡ��쥸������AND�黻
 *   void sil_anh_reg(uint16_t *p_reg, uint16_t bitptn);
 */
#define sil_anh_reg(p_reg, bitptn)				\
{												\
	uint16_t reg_val = sil_reh_mem(p_reg);		\
												\
	reg_val &= (uint16_t)(bitptn);				\
	sil_wrh_mem(p_reg, reg_val);				\
}


/*
 *	16�ӥåȡ��쥸�����Υӥåȡ����åȡ����ꥢ
 */
/*  void sil_seth_bit(uint16_t *p_reg, uint_t bit);  */
#define sil_seth_bit(p_reg, bit)				\
{												\
	uint16_t reg_val = sil_reh_reg(p_reg);		\
												\
	/*											\
	 *	bit��7�ʲ�������Ǥ���С�				\
	 *	bset̿���Ÿ������뤳�Ȥ����			\
	 */											\
	reg_val |= (1U << (bit));					\
	sil_wrh_reg(p_reg, reg_val);				\
}

/*  void sil_clrh_bit(uint16_t *p_reg, uint_t bit);  */
#define sil_clrh_bit(p_reg, bit)				\
{												\
	uint16_t reg_val = sil_reh_reg(p_reg);		\
												\
	/*											\
	 *	bit��7�ʲ�������Ǥ���С�				\
	 *	bclr̿���Ÿ������뤳�Ȥ����			\
	 */											\
	reg_val &= ~(1U << (bit));					\
	sil_wrh_reg(p_reg, reg_val);				\
}

#endif /* TOPPERS_MACRO_ONLY */

#endif /* TOPPERS_PRC_SIL_H */
