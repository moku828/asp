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
 *
 *  HIGH_PRIORITY，MID_PRIORITY，LOW_PRIORITY の各優先度のレディキュー
 *  を回転させる．
 */
void cyclic_handler(intptr_t exinf)
{
	SVC_PERROR(irot_rdq(HIGH_PRIORITY));
	SVC_PERROR(irot_rdq(MID_PRIORITY));
	SVC_PERROR(irot_rdq(LOW_PRIORITY));
}

/*
 *  アラームハンドラ
 *
 *  HIGH_PRIORITY，MID_PRIORITY，LOW_PRIORITY の各優先度のレディキュー
 *  を回転させる．
 */
void alarm_handler(intptr_t exinf)
{
	SVC_PERROR(irot_rdq(HIGH_PRIORITY));
	SVC_PERROR(irot_rdq(MID_PRIORITY));
	SVC_PERROR(irot_rdq(LOW_PRIORITY));
}

/*
 *  メインタスク
 */
void main_task(intptr_t exinf)
{
	ER_UINT	ercd;
	FLGPTN flgptn;
	int i, j;

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
