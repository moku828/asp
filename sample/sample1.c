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
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 * 
 *  @(#) $Id: sample1.c 1797 2010-06-07 04:24:19Z ertl-hiro $
 */

/* 
 *  サンプルプログラム(1)の本体
 *
 *  ASPカーネルの基本的な動作を確認するためのサンプルプログラム．
 *
 *  プログラムの概要:
 *
 *  ユーザインタフェースを受け持つメインタスク（タスクID: MAIN_TASK，優
 *  先度: MAIN_PRIORITY）と，3つの並列実行されるタスク（タスクID:
 *  TASK1〜TASK3，初期優先度: MID_PRIORITY）で構成される．また，起動周
 *  期が2秒の周期ハンドラ（周期ハンドラID: CYCHDR1）を用いる．
 *
 *  並列実行されるタスクは，task_loop回空ループを実行する度に，タスクが
 *  実行中であることをあらわすメッセージを表示する．
 *
 *  周期ハンドラは，三つの優先度（HIGH_PRIORITY，MID_PRIORITY，
 *  LOW_PRIORITY）のレディキューを回転させる．プログラムの起動直後は，
 *  周期ハンドラは停止状態になっている．
 *
 *  メインタスクは，シリアルI/Oポートからの文字入力を行い（文字入力を
 *  待っている間は，並列実行されるタスクが実行されている），入力された
 *  文字に対応した処理を実行する．入力された文字と処理の関係は次の通り．
 *  Control-Cまたは'Q'が入力されると，プログラムを終了する．
 *
 *  '1' : 対象タスクをTASK1に切り換える（初期設定）．
 *  '2' : 対象タスクをTASK2に切り換える．
 *  '3' : 対象タスクをTASK3に切り換える．
 *  'a' : 対象タスクをact_tskにより起動する．
 *  'A' : 対象タスクに対する起動要求をcan_actによりキャンセルする．
 *  'e' : 対象タスクにext_tskを呼び出させ，終了させる．
 *  't' : 対象タスクをter_tskにより強制終了する．
 *  '>' : 対象タスクの優先度をHIGH_PRIORITYにする．
 *  '=' : 対象タスクの優先度をMID_PRIORITYにする．
 *  '<' : 対象タスクの優先度をLOW_PRIORITYにする．
 *  'G' : 対象タスクの優先度をget_priで読み出す．
 *  's' : 対象タスクにslp_tskを呼び出させ，起床待ちにさせる．
 *  'S' : 対象タスクにtslp_tsk(10秒)を呼び出させ，起床待ちにさせる．
 *  'w' : 対象タスクをwup_tskにより起床する．
 *  'W' : 対象タスクに対する起床要求をcan_wupによりキャンセルする．
 *  'l' : 対象タスクをrel_waiにより強制的に待ち解除にする．
 *  'u' : 対象タスクをsus_tskにより強制待ち状態にする．
 *  'm' : 対象タスクの強制待ち状態をrsm_tskにより解除する．
 *  'd' : 対象タスクにdly_tsk(10秒)を呼び出させ，時間経過待ちにさせる．
 *  'x' : 対象タスクに例外パターン0x0001の例外処理を要求する．
 *  'X' : 対象タスクに例外パターン0x0002の例外処理を要求する．
 *  'y' : 対象タスクにdis_texを呼び出させ，タスク例外を禁止する．
 *  'Y' : 対象タスクにena_texを呼び出させ，タスク例外を許可する．
 *  'r' : 3つの優先度（HIGH_PRIORITY，MID_PRIORITY，LOW_PRIORITY）のレ
 *        ディキューを回転させる．
 *  'c' : 周期ハンドラを動作開始させる．
 *  'C' : 周期ハンドラを動作停止させる．
 *  'b' : アラームハンドラを5秒後に起動するよう動作開始させる．
 *  'B' : アラームハンドラを動作停止させる．
 *  'z' : 対象タスクにCPU例外を発生させる（タスクを終了させる）．
 *  'Z' : 対象タスクにCPUロック状態でCPU例外を発生させる（プログラムを
 *        終了する）．
 *  'V' : get_utmで性能評価用システム時刻を2回読む．
 *  'v' : 発行したシステムコールを表示する（デフォルト）．
 *  'q' : 発行したシステムコールを表示しない．
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
 *  サービスコールのエラーのログ出力
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
	SVC_PERROR(set_flg(FLAG1, 0x4));
}

void cyclic_task(intptr_t exinf)
{
	FLGPTN flgptn;
	SYSTIM now;
	UINT s2;
	int i, j;
	int last = -1;
	while (1)
	{
		SVC_PERROR(wai_flg(FLAG2, 0x1, TWF_ANDW, &flgptn));
		SVC_PERROR(get_tim(&now));
		syslog(LOG_NOTICE, "offset:%d,now:%d,diff:%d", offset, now, now - offset);
		for (i = 0; i < lyricsln; i++)
		{
			if (lyrics[i].time > (now - offset)) break;
		}
		if (i == lyricsln) continue;
		if (i == last) continue;
		last = i;
		syslog(LOG_NOTICE, "str:%04x...", lyrics[i - 1].str[0]);
		sh_vdc3_fill();
		assert(FR_OK == f_chdir("/fonts"));
		j = 0;
		while (1)
		{
			char fontfilename[9];
			if (lyrics[i - 1].str[j] == 0x0000) break;
			fontfilename[0] = (lyrics[i - 1].str[j] >> 12) & 0x0F;
			fontfilename[1] = (lyrics[i - 1].str[j] >> 8) & 0x0F;
			fontfilename[2] = (lyrics[i - 1].str[j] >> 4) & 0x0F;
			fontfilename[3] = (lyrics[i - 1].str[j] >> 0) & 0x0F;
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
		sh_vdc3_swap();
	}
}

/*
 *  CPU例外ハンドラ
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
 *  周期ハンドラ
 */
void cyclic_handler(intptr_t exinf)
{
	SVC_PERROR(iset_flg(FLAG2, 0x1));
}

/*
 *  アラームハンドラ
 */
void alarm_handler(intptr_t exinf)
{
}

/*
 *  メインタスク
 */
void main_task(intptr_t exinf)
{
	ER_UINT	ercd;
	FLGPTN flgptn;
	int i;

	SVC_PERROR(syslog_msk_log(LOG_UPTO(LOG_INFO), LOG_UPTO(LOG_EMERG)));
	syslog(LOG_NOTICE, "Sample program starts (exinf = %d).", (int_t) exinf);

	/*
	 *  シリアルポートの初期化
	 *
	 *  システムログタスクと同じシリアルポートを使う場合など，シリアル
	 *  ポートがオープン済みの場合にはここでE_OBJエラーになるが，支障は
	 *  ない．
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
					SVC_PERROR(act_tsk(TASK3));
					break;
				}
				if (i == lyricscnt)
				{
					syslog(LOG_NOTICE, "title missing in lyrics list");
				}
				break;
			case 0x27:
				syslog(LOG_NOTICE, "time elapsed on current song");
				if (param[0] != 4) break;
				{
					SYSTIM tmpoffset;
					int elapsedtime = 0;
					elapsedtime += param[1] << 24;
					elapsedtime += param[2] << 16;
					elapsedtime += param[3] << 8;
					elapsedtime += param[4] << 0;
					syslog(LOG_NOTICE, "%d.%d(sec)", (elapsedtime / 1000), (elapsedtime % 1000));
					SVC_PERROR(get_tim(&tmpoffset));
					tmpoffset -= elapsedtime;
					syslog(LOG_NOTICE, "offset:[%d], tmpoffset:[%d]", offset, tmpoffset);
					if (tmpoffset > (offset + 300))
					{
						offset = tmpoffset;
					}
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
