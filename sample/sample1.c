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
#include <string.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "pdic/sh/xprintf.h"
#include "pdic/sh/ff.h"
#include "pdic/sh/diskio.h"
#include "kernel_cfg.h"
#include "sample1.h"


/*---------------------------------------------------------*/
/* Work Area                                               */
/*---------------------------------------------------------*/

FATFS FatFs[FF_VOLUMES];	/* File system object */
FIL File[2];				/* File objects */
DIR Dir;					/* Directory object */

DWORD AccSize;				/* Working variables (fs command) */
WORD AccFiles, AccDirs;

FILINFO Finfo;				/* Working variables (fs/fl command) */

char Line[256];				/* Console input buffer */
BYTE Buff[32768];			/* Disk I/O working buffer */

volatile UINT Timer;		/* Performance timer (1kHz) */



/*---------------------------------------------------------*/
/* User Provided Timer Function for FatFs module           */
/*---------------------------------------------------------*/
/* This is a real time clock service to be called from     */
/* FatFs module. Any valid time must be returned even if   */
/* the system does not support a real time clock.          */
/* This is not required in read-only configuration.        */

#if !FF_FS_NORTC
DWORD get_fattime (void)
{
	/* Return a fixed value 2010/4/26 0:00:00 */
	return	  ((DWORD)(2010 - 1980) << 25)	/* Y */
			| ((DWORD)4  << 21)				/* M */
			| ((DWORD)26 << 16)				/* D */
			| ((DWORD)0  << 11)				/* H */
			| ((DWORD)0  << 5)				/* M */
			| ((DWORD)0  >> 1);				/* S */
}
#endif



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

typedef struct {
	char filename[9];
	char title[100];
} LYRICSTBL;
LYRICSTBL lyricslst[64];
int lyricscnt;
int lyricsno;
typedef struct {
	unsigned long time;
	unsigned short str[62];
} LYRICS;
LYRICS lyrics[256];
int lyricsln;
#define B2S(p, i) ((*(p + i * 2 + 0) << 0) + (*(p + i * 2 + 1) << 8))
#define IS_NUL(c) (0x0000 == c)
#define IS_LF(c) (0x000A == c)
#define IS_DOT(c) (0x002E == c)
#define IS_NUM(c) ((0x0030 <= c) && (0x0039 >= c))
#define IS_COL(c) (0x003A == c)
#define IS_AT(c) (0x0040 == c)
#define IS_LTBR(c) (0x005B == c)
#define IS_RTBR(c) (0x005D == c)
#define IS_BOM(c) (0xFEFF == c)

void initcommseq_task(intptr_t exinf)
{
	syslog(LOG_NOTICE, "initcommseq_task");
	SVC_PERROR(set_flg(FLAG1, 0x1));
}

void lyricslstload_task(intptr_t exinf)
{
	UINT s2;
	char* p;
	int i, titlelen;
	syslog(LOG_NOTICE, "lyricslstload_task");
	assert(FR_OK == f_chdir("/lyrics"));
	assert(FR_OK == f_open(&File[0], "list.txt", 1));
	memset(Buff, 0, 32768);
	assert(FR_OK == f_read(&File[0], Buff, 32768, &s2));
	assert(FR_OK == f_close(&File[0]));
	p = Buff;
	lyricslst[0].filename[0] = 0;
	for (i = 0; i < sizeof(lyricslst) / sizeof(lyricslst[0]); i++)
	{
		if (lyricslst[i].filename[0] != 0) continue;
		memcpy(lyricslst[i].filename, p, 8);
		lyricslst[i].filename[8] = 0;
		p += 9;
		titlelen = ((*p - 0x30) * 10) + (*(p + 1) - 0x30);
		p += 3;
		memcpy(lyricslst[i].title, p, titlelen);
		lyricslst[i].title[titlelen] = 0;
		p += titlelen + 1;
		if (*p == 0) break;
	}
	lyricscnt = i;
	SVC_PERROR(set_flg(FLAG1, 0x2));
}

void lyricsfontfileload_task(intptr_t exinf)
{
	UINT s2;
	int i, n, l;
	syslog(LOG_NOTICE, "lyricsfontfileload_task");
	assert(lyricsno < lyricscnt);
	assert(lyricslst[lyricsno].filename[0] != 0);
	assert(FR_OK == f_chdir("/lyrics"));
	assert(FR_OK == f_open(&File[0], lyricslst[lyricsno].filename, 1));
	memset(Buff, 0, 32768);
	assert(FR_OK == f_read(&File[0], Buff, 32768, &s2));
	assert(FR_OK == f_close(&File[0]));
	memset(lyrics, 0, sizeof(lyrics));
	lyricsln = 0;
	assert(IS_BOM(B2S(Buff, 0)));
	for (i = 2, n = 0, l = 0; i < 32768; i += 2)
	{
		char* p;
		p = Buff + i;
		if (IS_NUL(B2S(p, 0))) break;
		if (
			IS_LTBR(B2S(p, 0))
			&& IS_AT(B2S(p, 1))
			&& IS_NUM(B2S(p, 2)) && IS_NUM(B2S(p, 3))
			&& IS_COL(B2S(p, 4))
			&& IS_NUM(B2S(p, 5)) && IS_NUM(B2S(p, 6))
			&& IS_DOT(B2S(p, 7))
			&& IS_NUM(B2S(p, 8)) && IS_NUM(B2S(p, 9)) && IS_NUM(B2S(p, 10))
			&& IS_RTBR(B2S(p, 11))
		)
		{
			if (n > 0)
			{
				lyrics[n - 1].str[l] = 0x0000;
			}
			l = 0;
			lyrics[n].time =
				(B2S(p, 2) - 0x0030) * 10 * 60 * 10
				+ (B2S(p, 3) - 0x0030) * 60 * 10
				+ (B2S(p, 5) - 0x0030) * 10 * 10
				+ (B2S(p, 6) - 0x0030) * 10
				+ (B2S(p, 8) - 0x0030);
			n++;
			i += 22;
		}
		else
		{
			if (
				(n > 0)
				&& !IS_LF(B2S(p, 0))
			)
			{
				lyrics[n - 1].str[l] = B2S(p, 0);
				l++;
			}
		}
	}
	if (n > 0)
	{
		lyricsln = n - 1;
	}
	SVC_PERROR(set_flg(FLAG1, 0x4));
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
	FLGPTN flgptn;
	int i, j;

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

	assert(FR_OK == f_mount(&FatFs[0], "", 0));
	SVC_PERROR(act_tsk(TASK1));
	SVC_PERROR(act_tsk(TASK2));
	SVC_PERROR(wai_flg(FLAG1, 0x3, TWF_ANDW, &flgptn));

	for (i = 0; i < lyricscnt; i++)
	{
		syslog(LOG_NOTICE, "%s:%s", lyricslst[i].filename, lyricslst[i].title);
	}

	for (i = 0; i < lyricscnt; i++)
	{
		syslog(LOG_NOTICE, "%s:%s", lyricslst[i].filename, lyricslst[i].title);
		lyricsno = i;
		SVC_PERROR(act_tsk(TASK3));
		SVC_PERROR(wai_flg(FLAG1, 0x4, TWF_ANDW, &flgptn));

		for (j = 0; j < lyricsln; j++)
		{
			syslog(LOG_NOTICE, "[%d]%d,%04x...", j, lyrics[j].time, lyrics[j].str[0]);
			dly_tsk(10);
		}
		dly_tsk(3000);
	}

	while (1)
	{
		dly_tsk(100);
	}
}
