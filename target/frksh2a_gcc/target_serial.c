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
 *	$Id: target_serial.c 2125 2011-06-24 07:42:00Z mit-kimai $
 */

/*
 *	���ꥢ��I/O�ǥХ�����SIO�˥ɥ饤�С�FRK-SH2A�ѡ�
 *	SCIF1 �����
 */

#include <kernel.h>
#include <t_syslog.h>
#include "target_serial.h"
#include "target_syssvc.h"	/*  TNUM_SIOP  */


static const INTNO intno_sio_tx_table[TNUM_SIOP] = { 
    SCIF0_RXI_VECTOR
#if TNUM_SIOP > 1
    ,SCIF1_RXI_VECTOR
#endif /* TNUM_SIOP > 1 */   
#if TNUM_SIOP > 2
    ,SCIF2_RXI_VECTOR
#endif /* TNUM_SIOP > 2 */
#if TNUM_SIOP > 3
    ,SCIF3_RXI_VECTOR
#endif /* TNUM_SIOP > 3 */
#if TNUM_SIOP > 4
    ,SCIF4_RXI_VECTOR
#endif /* TNUM_SIOP > 4 */
#if TNUM_SIOP > 5
    ,SCIF5_RXI_VECTOR
#endif /* TNUM_SIOP > 5 */
#if TNUM_SIOP > 6
    ,SCIF6_RXI_VECTOR
#endif /* TNUM_SIOP > 6 */
#if TNUM_SIOP > 7
    ,SCIF7_RXI_VECTOR
#endif /* TNUM_SIOP > 7 */
}; 

static const INTNO intno_sio_rx_table[TNUM_SIOP] = { 
    SCIF0_TXI_VECTOR
#if TNUM_SIOP > 1
    ,SCIF1_TXI_VECTOR
#endif /* TNUM_SIOP > 1 */   
#if TNUM_SIOP > 2
    ,SCIF2_TXI_VECTOR
#endif /* TNUM_SIOP > 2 */
#if TNUM_SIOP > 3
    ,SCIF3_TXI_VECTOR
#endif /* TNUM_SIOP > 3 */
#if TNUM_SIOP > 4
    ,SCIF4_TXI_VECTOR
#endif /* TNUM_SIOP > 4 */
#if TNUM_SIOP > 5
    ,SCIF5_TXI_VECTOR
#endif /* TNUM_SIOP > 5 */
#if TNUM_SIOP > 6
    ,SCIF6_TXI_VECTOR
#endif /* TNUM_SIOP > 6 */
#if TNUM_SIOP > 7
    ,SCIF7_TXI_VECTOR
#endif /* TNUM_SIOP > 7 */
}; 

/* 
 *  ���ꥢ��I/O�ݡ���ID���������ֹ����Ф�����Υޥ��� 
 */ 
#define INDEX_SIOP(siopid)           ((uint_t)((siopid) - 1)) 
#define get_intno_sio_tx(siopid)     (intno_sio_tx_table[INDEX_SIOP(siopid)]) 
#define get_intno_sio_rx(siopid)     (intno_sio_rx_table[INDEX_SIOP(siopid)]) 

/*
 *	SIO�ɥ饤�Фν����
 */
void
sio_initialize(intptr_t exinf)
{
	sh_scif_initialize();
}

/*
 *	���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
SIOPCB *
sio_opn_por(ID siopid, intptr_t exinf)
{
	SIOPCB	*p_siopcb;
	ER		ercd;
	INTNO	intno_sio_tx, intno_sio_rx;

	/*
	 *	���ꥢ��I/O����ߤ�ޥ������롥
	 */
	intno_sio_tx = get_intno_sio_tx(siopid);
	intno_sio_rx = get_intno_sio_rx(siopid);
	ercd = dis_int(intno_sio_tx);
	assert(ercd == E_OK);
	ercd = dis_int(intno_sio_rx);
	assert(ercd == E_OK);

	/*
	 *	�ǥХ�����¸�Υ����ץ������
	 */
	p_siopcb = sh_scif_opn_por(siopid, exinf);

	/*
	 *	���ꥢ��I/O����ߤΥޥ����������롥
	 */
	ercd = ena_int(intno_sio_tx);
	assert(ercd == E_OK);
	ercd = ena_int(intno_sio_rx);
	assert(ercd == E_OK);

	return(p_siopcb);
}

/*
 *	���ꥢ��I/O�ݡ��ȤΥ�����
 */
void
sio_cls_por(SIOPCB *p_siopcb)
{
	ER		ercd;
    ID		siopid; 
	INTNO	intno_sio_tx, intno_sio_rx;

    /* 
     *  ���ꥢ��I/O�ݡ���ID�μ��� 
     */ 
    siopid = sh_scif_get_siopid(p_siopcb);

	/*
	 *	�ǥХ�����¸�Υ�����������
	 */
	sh_scif_cls_por(p_siopcb);

	/*
	 *	���ꥢ��I/O����ߤ�ޥ������롥
	 */
	intno_sio_tx = get_intno_sio_tx(siopid);
	intno_sio_rx = get_intno_sio_rx(siopid);
	ercd = dis_int(intno_sio_tx);
	assert(ercd == E_OK);
	ercd = dis_int(intno_sio_rx);
	assert(ercd == E_OK);
}

/*
 *	SIO�γ���ߥϥ�ɥ�
 */
void
sio_tx_isr(intptr_t exinf)
{
	sh_scif_tx_isr(exinf);
}


/*
 *	SIO�γ���ߥϥ�ɥ�
 */
void
sio_rx_isr(intptr_t exinf)
{
	sh_scif_rx_isr(exinf);
}

#ifndef TOPPERS_HEW_SIMULATOR
/*
 *	���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
bool_t
sio_snd_chr(SIOPCB *siopcb, char_t c)
{
	return(sh_scif_snd_chr(siopcb, c));
}

/*
 *	���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
int_t
sio_rcv_chr(SIOPCB *siopcb)
{
	return(sh_scif_rcv_chr(siopcb));
}
#endif /* TOPPERS_HEW_SIMULATOR */

/*
 *	���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
void
sio_ena_cbr(SIOPCB *siopcb, uint_t cbrtn)
{
	sh_scif_ena_cbr(siopcb, cbrtn);
}

/*
 *	���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
void
sio_dis_cbr(SIOPCB *siopcb, uint_t cbrtn)
{
	sh_scif_dis_cbr(siopcb, cbrtn);
}

/*
 *	���ꥢ��I/O�ݡ��Ȥ����������ǽ������Хå�
 */
void
sh_scif_irdy_snd(intptr_t exinf)
{
	sio_irdy_snd(exinf);
}

/*
 *	���ꥢ��I/O�ݡ��Ȥ���μ������Υ�����Хå�
 */
void
sh_scif_irdy_rcv(intptr_t exinf)
{
	sio_irdy_rcv(exinf);
}
