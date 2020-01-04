/*
 *  TOPPERS/ASP/FMP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile/Flexible MultiProcessor Kernel
 * 
 *  Copyright (C) 2003-2005 by 
 *                     GJ Business Division RICOH COMPANY,LTD. JAPAN
 *  Copyright (C) 2015-2017 by TOPPERS PROJECT Educational Working Group.
 * 
 *  �嵭����Ԥϡ�Free Software Foundation �ˤ�äƸ�ɽ����Ƥ��� 
 *  GNU General Public License �� Version 2 �˵��Ҥ���Ƥ����狼����
 *  ����(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ��������ܥ��եȥ���
 *  ������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ������ۡʰʲ���
 *  ���ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ�����������Ѳ�ǽ�ʥХ��ʥꥳ���ɡʥ�������֥륪��
 *      �������ȥե������饤�֥��ʤɡˤη������Ѥ�����ˤϡ�����
 *      ��ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ����
 *      �������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ�������������Բ�ǽ�ʥХ��ʥꥳ���ɤη��ޤ��ϵ������
 *      �߹�����������Ѥ�����ˤϡ����Τ����줫�ξ������������ȡ�
 *    (a) ���Ѥ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭������
 *        ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) ���Ѥη��֤��̤�������ˡ�ˤ�äơ��嵭����Ԥ���𤹤�
 *        ���ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥϡ�
 *  �ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����ޤ�ơ������ʤ��ݾڤ�Ԥ�
 *  �ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū����������
 *  ���ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
 * 
 *  @(#) $Id: stdio.h,v 1.7 2017/03/01 19:05:00 roi Exp $
 */
/*
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	@(#)stdio.h	5.3 (Berkeley) 3/15/86
 */

/*
 * NB: to fit things in six character monocase externals, the
 * stdio code uses the prefix `__ms' for embedded stdio objects, typically
 * followed by a three-character attempt at a mnemonic.
 */
#ifndef _STDIO_H_
#ifdef __cplusplus
extern "C" {
#endif
#define	_STDIO_H_

#define __need___va_list
#include <stdarg.h>

#define	_SMALL_STDIO_

#include <target_stddef.h>

typedef struct __msFILE {
  int	_flags;				/* flags, below; this FILE is free if 0 */
  int	_file;				/* fileno, if Unix descriptor, else -1 */
  int  (* _func_in)(void*);	/* pointer to a character input function */
							/* pointer to a character input string function */
  int  (* _func_ins)(void*, unsigned int, char *);
  void (* _func_out)(void*, int);	/* pointer to a character output function */
							/* pointer to a character output string function */
  int  (* _func_outs)(void*, unsigned int, char *);
							/* pointer to a character output flush function */
  int  (* _func_flush)(struct __msFILE *);
  void * _dev;				/* pointer to local device structure */
} FILE;

#define	__SLBF	0x0001		/* line buffered */
#define	__SNBF	0x0002		/* unbuffered */
#define	__SRD	0x0004		/* OK to read */
#define	__SWR	0x0008		/* OK to write */
	/* RD and WR are never simultaneously asserted */
#define	__SRW	0x0010		/* open for reading & writing */
#define	__SEOF	0x0020		/* found EOF */
#define	__SERR	0x0040		/* found error */
#define	__SMBF	0x0080		/* _buf is from malloc */
#define	__SAPP	0x0100		/* fdopen()ed in append mode - so must  write to end */
#define	__SSTR	0x0200		/* this is an sprintf/snprintf string */
#define	__SOPT	0x0400		/* do fseek() optimisation */
#define	__SNPT	0x0800		/* do not do fseek() optimisation */
#define	__SOFF	0x1000		/* set iff _offset is in fact correct */
#define	__SMOD	0x2000		/* true => fgetline modified _p text */

/*
 * The following three definitions are for ANSI C, which took them
 * from System V, which stupidly took internal interface macros and
 * made them official arguments to setvbuf(), without renaming them.
 * Hence, these ugly _IOxxx names are *supposed* to appear in user code.
 *
 * Although these happen to match their counterparts above, the
 * implementation does not rely on that (so these could be renumbered).
 */
#define	_IOFBF	0		/* setvbuf should set fully buffered */
#define	_IOLBF	1		/* setvbuf should set line buffered */
#define	_IONBF	2		/* setvbuf should set unbuffered */

#ifndef NULL
#define	NULL	0
#endif

#define	BUFSIZ	1024
#define	EOF	(-1)

extern FILE _iob[];
#define  stdin   (&_iob[0])	/* FILE input */
#define  stdout  (&_iob[1])	/* FILE output */
#define  stderr  (&_iob[2])	/* FILE error input output */

/*
 * Functions defined in ANSI C standard.
 */

#ifdef __GNUC__
#define __VALIST __gnuc_va_list
#else
#define __VALIST char*
#endif

int	fgetc(FILE *);
int fgets(char *, int, FILE *);
int fputc(int, FILE *);
int fputs(const char *, FILE *);
int	putchar(int);
int	puts(const char *);
int	printf(const char *, ...);
int	sprintf(char *, const char *, ...);
int snprintf(char *, size_t, const char *, ...);
int scanf(const char *, ...);
int sscanf(char *, const char *, ...);
int fflush(FILE *);
FILE *fopen(const char *, const char *);
int fclose(FILE *);
size_t fread(void *, size_t, size_t, FILE *);
size_t fwrite(const void *, size_t, size_t, FILE *);
int fseek(FILE *, long, int);
long ftell(FILE *);
int	fprintf(FILE *, const char *, ...);

#define	feof(p)     (((p)->_flags & __SEOF) != 0)
#define	ferror(p)   (((p)->_flags & __SERR) != 0)
#define	clearerr(p) ((void)((p)->_flags &= ~(__SERR|__SEOF)))
#define putc(c,fp)  fputc(c,fp)
#define getchar()   fgetc(stdin)
#define getc(fp)    fgetc(fp)

/*
 * NOT SUPPORT stdio functions
 */
#define gets(s)                         puts("NOT SUPPORT gets !\n")
#define ungetc(c, st)                   puts("NOT SUPPORT ungetc !\n")
#define vprintf(format, ap)             puts("NOT SUPPORT vprintf !\n")
#define vfprintf(st, format, ap)        puts("NOT SUPPORT vfprintf !\n")
#define vsprintf(s, format, ap)         puts("NOT SUPPORT vsprintf !\n")
#if !defined(__cplusplus) && defined(__GNUC__)
#define fscanf(st, format, ...)         puts("NOT SUPPORT fscanf !\n")
#endif

extern void _setup_stdio(signed int *pport);
extern FILE *_get_stdio(int no);

#ifdef __cplusplus
}
#endif
#endif /* _STDIO_H_ */
