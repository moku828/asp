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
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ��������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ��������Ȥ����դ��뤳�ȡ�
 *      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ��������Ȥ�
 *      ���դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ��������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
 * 
 *  @(#) $Id: sample1.c 1797 2010-06-07 04:24:19Z ertl-hiro $
 */

/* 
 *  ����ץ�ץ������(1)������
 *
 *  ASP�����ͥ�δ���Ū��ư����ǧ���뤿��Υ���ץ�ץ�����ࡥ
 *
 *  �ץ������γ���:
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
 *  LOW_PRIORITY�ˤΥ�ǥ����塼���ž�����롥�ץ������ε�ưľ��ϡ�
 *  �����ϥ�ɥ����߾��֤ˤʤäƤ��롥
 *
 *  �ᥤ�󥿥����ϡ����ꥢ��I/O�ݡ��Ȥ����ʸ�����Ϥ�Ԥ���ʸ�����Ϥ�
 *  �ԤäƤ���֤ϡ�����¹Ԥ���륿�������¹Ԥ���Ƥ���ˡ����Ϥ��줿
 *  ʸ�����б�����������¹Ԥ��롥���Ϥ��줿ʸ���Ƚ����δط��ϼ����̤ꡥ
 *  Control-C�ޤ���'Q'�����Ϥ����ȡ��ץ�������λ���롥
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
 *  'Z' : �оݥ�������CPU���å����֤�CPU�㳰��ȯ��������ʥץ�������
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
#include "pdic/sh/sh_vdc3.h"
#include "kernel_cfg.h"
#include "target_syssvc.h"
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
 *  �����ӥ�������Υ��顼�Υ�������
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
#define B2S(p, i) (((unsigned short)*((unsigned char*)p + i * 2 + 0) << 0) + ((unsigned short)*((unsigned char*)p + i * 2 + 1) << 8))
#define IS_NUL(c) (0x0000 == c)
#define IS_LF(c) (0x000A == c)
#define IS_DOT(c) (0x002E == c)
#define IS_NUM(c) ((0x0030 <= c) && (0x0039 >= c))
#define IS_COL(c) (0x003A == c)
#define IS_AT(c) (0x0040 == c)
#define IS_LTBR(c) (0x005B == c)
#define IS_RTBR(c) (0x005D == c)
#define IS_BOM(c) (0xFEFF == c)
#define IS_AAPHDR1(c) (0xFF == c)
#define IS_AAPHDR2(c) (0x55 == c)
SYSTIM offset;

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
		titlelen = (((*p == 0x20) ? 0 : (*p - 0x30)) * 10) + (*(p + 1) - 0x30);
		p += 3;
		memcpy(lyricslst[i].title, p, titlelen);
		lyricslst[i].title[titlelen] = 0;
		p += titlelen + 1;
		if (*p == 0) break;
	}
	lyricscnt = i + 1;
	SVC_PERROR(set_flg(FLAG1, 0x2));
}

void lyricsfileload_task(intptr_t exinf)
{
	UINT s2;
	int i, n, l;
	SYSTIM start, end;
	syslog(LOG_NOTICE, "lyricsfileload_task");
	if (lyricsno == -1)
	{
		lyricsln = 0;
		return;
	}
	SVC_PERROR(get_tim(&start));
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
				(B2S(p, 2) - 0x0030) * 10 * 60 * 1000
				+ (B2S(p, 3) - 0x0030) * 60 * 1000
				+ (B2S(p, 5) - 0x0030) * 10 * 1000
				+ (B2S(p, 6) - 0x0030) * 1000
				+ (B2S(p, 8) - 0x0030) * 100;
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
		lyricsln = n;
	}
	SVC_PERROR(get_tim(&end));
	syslog(LOG_NOTICE, "start:%d,end:%d,diff:%d", start, end, end - start);
}

void cyclic_task(intptr_t exinf)
{
	FLGPTN flgptn;
	SYSTIM now;
	UINT s2;
	int i, j;
	int last = -1;
	sh_vdc3_fill();
	while (1)
	{
		SVC_PERROR(wai_flg(FLAG2, 0x1, TWF_ANDW, &flgptn));
		SVC_PERROR(get_tim(&now));
		syslog(LOG_NOTICE, "offset:%d,now:%d,diff:%d", offset, now, now - offset);
		if (lyricsln == 0)
		{
			sh_vdc3_fill();
			sh_vdc3_swap();
			continue;
		}
		if (lyrics[0].time > (now - offset))
		{
			i = 0;
		}
		else
		{
			for (i = 1; i < lyricsln; i++)
			{
				if ((lyrics[i].time > (now - offset)) && (lyrics[i - 1].time <= (now - offset))) break;
			}
		}
		if (i == last) continue;
		last = i;
		syslog(LOG_NOTICE, "str:%04x...", lyrics[i].str[0]);
		sh_vdc3_swap();
		sh_vdc3_fill();
		assert(FR_OK == f_chdir("/fonts"));
		j = 0;
		while (1)
		{
			char fontfilename[9];
			if (lyrics[i].str[j] == 0x0000) break;
			fontfilename[0] = (lyrics[i].str[j] >> 12) & 0x0F;
			fontfilename[1] = (lyrics[i].str[j] >> 8) & 0x0F;
			fontfilename[2] = (lyrics[i].str[j] >> 4) & 0x0F;
			fontfilename[3] = (lyrics[i].str[j] >> 0) & 0x0F;
			fontfilename[0] = (fontfilename[0] > 9) ? (fontfilename[0] - 10 + 0x41) : (fontfilename[0] + 0x30);
			fontfilename[1] = (fontfilename[1] > 9) ? (fontfilename[1] - 10 + 0x41) : (fontfilename[1] + 0x30);
			fontfilename[2] = (fontfilename[2] > 9) ? (fontfilename[2] - 10 + 0x41) : (fontfilename[2] + 0x30);
			fontfilename[3] = (fontfilename[3] > 9) ? (fontfilename[3] - 10 + 0x41) : (fontfilename[3] + 0x30);
			fontfilename[4] = 0x2E;
			fontfilename[5] = 0x62;
			fontfilename[6] = 0x6D;
			fontfilename[7] = 0x70;
			fontfilename[8] = 0;
			assert(FR_OK == f_open(&File[0], fontfilename, 1));
			memset(Buff, 0, 32768);
			assert(FR_OK == f_read(&File[0], Buff, 32768, &s2));
			assert(FR_OK == f_close(&File[0]));
			if (j < 16)
				sh_vdc3_drawbmp(j * 24 + 4, 4, 24, 24, Buff + 1078);
			else if (j < 32)
				sh_vdc3_drawbmp((j - 16) * 24 + 4, (24 + 4) * 1 + 4, 24, 24, Buff + 1078);
			else if (j < 48)
				sh_vdc3_drawbmp((j - 32) * 24 + 4, (24 + 4) * 2 + 4, 24, 24, Buff + 1078);
			j++;
		}
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
 */
void cyclic_handler(intptr_t exinf)
{
	SVC_PERROR(iset_flg(FLAG2, 0x1));
}

#define	PFCR1	*((volatile short *)0xFFFE38AC)
#define	PFIOR0	*((volatile short *)0xFFFE38B2)
#define	PFDR0	*((volatile short *)0xFFFE38B6)

unsigned char count[128];
unsigned char idx;
unsigned char len;

void cyclic_280us_initialize(void)
{
	volatile unsigned long i;
	idx = 0;
	len = 0;
	for (i = 0; i < sizeof(count)/sizeof(count[0]); i++)
	{
		count[i] = 0;
	}
	PFCR1 &= ~0x0700;
	PFIOR0 &= ~0x0040;
}

void cyclic_280us_handler(void)
{
	if (len != 0)
	{
		return;
	}
	
	if (PFDR0 & 0x0040)
	{
		if (idx == 0)
		{
			count[0] = 0x80;
		}
		else
		{
			if ((count[idx] & 0x80) == 0x00)
			{
				idx++;
				count[idx] = 0x81;
			}
			else
			{
				count[idx]++;
				if ((count[idx] & ~0x80) > 32)
				{
					len = idx;
					idx = 0;
					SVC_PERROR(iset_flg(FLAG3, 0x1));
				}
			}
		}
	}
	else
	{
		if (idx == 0)
		{
			idx++;
			count[idx] = 0x01;
		}
		else
		{
			if ((count[idx] & 0x80) == 0x80)
			{
				idx++;
				count[idx] = 0x01;
			}
			else
			{
				count[idx]++;
			}
		}
	}
}

/*
 *  ���顼��ϥ�ɥ�
 */
void alarm_handler(intptr_t exinf)
{
}

#define	PCCR2	*((volatile short *)0xFFFE384A)
#define	PCIOR0	*((volatile short *)0xFFFE3852)
#define	PCDR0	*((volatile short *)0xFFFE3856)

void irrcv_task(intptr_t exinf)
{
	volatile unsigned long i;
	int visiblle = 1;

	FLGPTN flgptn;
	PCCR2 &= ~0x0003;
	PCIOR0 |= 0x0100;

	while (1)
	{
		SVC_PERROR(wai_flg(FLAG3, 0x1, TWF_ANDW, &flgptn));
		syslog(LOG_NOTICE, "irrcv");
		if (len != 0)
		{
			if (len == 2+(32*2)+1+1)
			{
				unsigned char power[2+(32*2)+1+1] = {
					0x20, 0x90,
					0x02, 0x82, 0x02, 0x82, 0x02, 0x82, 0x02, 0x82, 0x02, 0x82, 0x02, 0x82, 0x02, 0x82, 0x02, 0x82,
					0x02, 0x86, 0x02, 0x86, 0x02, 0x86, 0x02, 0x86, 0x02, 0x86, 0x02, 0x86, 0x02, 0x86, 0x02, 0x86,
					0x02, 0x82, 0x02, 0x86, 0x02, 0x86, 0x02, 0x82, 0x02, 0x82, 0x02, 0x82, 0x02, 0x86, 0x02, 0x82,
					0x02, 0x86, 0x02, 0x82, 0x02, 0x82, 0x02, 0x86, 0x02, 0x86, 0x02, 0x86, 0x02, 0x82, 0x02, 0x86,
					0x02, 0xA1,
				};
				for (i = 0; i < sizeof(power)/sizeof(power[0]); i++)
				{
					if ((count[i+1] < (power[i] - 1)) || (count[i+1] > (power[i] + 1)))
					{
						break;
					}
				}
				if (i == (sizeof(power)/sizeof(power[0])))
				{
					if (!visiblle)
					{
						visiblle = 1;
						sh_vdc3_visible(1);
						PCDR0 &= ~0x0100;
					}
					else
					{
						visiblle = 0;
						sh_vdc3_visible(0);
						PCDR0 |= 0x0100;
					}
				}
				else
				{
					i = 0;
				}
			}
			len = 0;
		}
	}
}

/*
 *  �ᥤ�󥿥���
 */
void main_task(intptr_t exinf)
{
	ER_UINT	ercd;
	FLGPTN flgptn;
	int i;

	SVC_PERROR(syslog_msk_log(LOG_UPTO(LOG_NOTICE), LOG_UPTO(LOG_NOTICE)));
	syslog(LOG_NOTICE, "Sample program starts (exinf = %d).", (int_t) exinf);

	/*
	 *  ���ꥢ��ݡ��Ȥν����
	 *
	 *  �����ƥ������������Ʊ�����ꥢ��ݡ��Ȥ�Ȥ����ʤɡ����ꥢ��
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
	SVC_PERROR(serial_opn_por(IPODRX_PORTID));
	SVC_PERROR(serial_ctl_por(IPODRX_PORTID, 0));

	assert(FR_OK == f_mount(&FatFs[0], "", 0));
	SVC_PERROR(act_tsk(TASK1));
	SVC_PERROR(act_tsk(TASK2));
	SVC_PERROR(wai_flg(FLAG1, 0x3, TWF_ANDW, &flgptn));
	SVC_PERROR(act_tsk(TASK4));
	SVC_PERROR(act_tsk(TASK5));

	while (1)
	{
		char_t	c;
		unsigned char sz, md, cmd[2], param[253], chksum;
		unsigned short sum;
		sum = 0;
		SVC_PERROR(serial_rea_dat(IPODRX_PORTID, &c, 1));
		if (!IS_AAPHDR1(c)) continue;
		SVC_PERROR(serial_rea_dat(IPODRX_PORTID, &c, 1));
		if (!IS_AAPHDR2(c)) continue;
		SVC_PERROR(serial_rea_dat(IPODRX_PORTID, &c, 1));
		sz = c;
		sum += sz;
		if (sz < 4) continue;
		SVC_PERROR(serial_rea_dat(IPODRX_PORTID, &c, 1));
		md = c;
		sum += md;
		if (md > 4) continue;
		SVC_PERROR(serial_rea_dat(IPODRX_PORTID, &c, 1));
		cmd[0] = c;
		sum += cmd[0];
		SVC_PERROR(serial_rea_dat(IPODRX_PORTID, &c, 1));
		cmd[1] = c;
		sum += cmd[1];
		for (i = 0; i < sz - 3; i++)
		{
			SVC_PERROR(serial_rea_dat(IPODRX_PORTID, &c, 1));
			param[i] = c;
			sum += param[i];
		}
		SVC_PERROR(serial_rea_dat(IPODRX_PORTID, &c, 1));
		chksum = c;
		if (chksum != (0x100 - (sum & 0x0FF))) continue;
		switch (md)
		{
		case 4:
			if (cmd[0] != 0x00) break;
			switch (cmd[1])
			{
			case 0x1D:
				syslog(LOG_NOTICE, "Track length in milliseconds, elapsed time in milliseconds, status=0x0 stop, 0x01 playing, 0x02 paused");
				if (param[8] != 0x01)
				{
					syslog(LOG_NOTICE, "%s", (param[8] == 0x00) ? "0x0 stop" : "0x02 paused");
					SVC_PERROR(stp_cyc(CYCHDR1));
				}
				else
				{
					syslog(LOG_NOTICE, "0x01 playing");
					SVC_PERROR(sta_cyc(CYCHDR1));
				}
				break;
			case 0x21:
				syslog(LOG_NOTICE, "title returned as a null terminated string");
				syslog(LOG_NOTICE, "%s", param);
				for (i = 0; i < lyricscnt; i++)
				{
					if (strcmp(param, lyricslst[i].title) != 0) continue;
					syslog(LOG_NOTICE, "%s:%s", lyricslst[i].filename, lyricslst[i].title);
					lyricsno = i;
					break;
				}
				if (i == lyricscnt)
				{
					syslog(LOG_NOTICE, "title missing in lyrics list");
					lyricsno = -1;
				}
				SVC_PERROR(act_tsk(TASK3));
				break;
			case 0x27:
				syslog(LOG_NOTICE, "time elapsed on current song");
				if (param[0] != 4) break;
				{
					int elapsedtime = 0;
					elapsedtime += param[1] << 24;
					elapsedtime += param[2] << 16;
					elapsedtime += param[3] << 8;
					elapsedtime += param[4] << 0;
					syslog(LOG_NOTICE, "%d.%d(sec)", (elapsedtime / 1000), (elapsedtime % 1000));
					SVC_PERROR(get_tim(&offset));
					offset -= elapsedtime;
					syslog(LOG_NOTICE, "offset:[%d]", offset);
				}
				break;
			}
			break;
		default:
			syslog(LOG_NOTICE, "not supported mode");
		}
		dly_tsk(100);
	}
}
