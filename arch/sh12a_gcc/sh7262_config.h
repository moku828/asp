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
 *	上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
 *	ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *	変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *	(1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *		権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *		スコード中に含まれていること．
 *	(2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *		用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *		者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *		の無保証規定を掲載すること．
 *	(3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *		用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *		と．
 *	  (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *		  作権表示，この利用条件および下記の無保証規定を掲載すること．
 *	  (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *		  報告すること．
 *	(4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *		害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *		また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *		由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *		免責すること．
 *	
 *	本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *	よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *	に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *	アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *	の責任を負わない．
 *	
 *	$Id: sh7211_config.h 2142 2011-06-27 07:24:40Z mit-kimai $
 */

/*
 *		プロセッサ依存モジュール（SH7262用）
 *
 *	このインクルードファイルは，target_config.h（または，そこからインク
 *	ルードされるファイル）のみからインクルードされる．他のファイルから
 *	直接インクルードしてはならない．
 */

#ifndef TOPPERS_SH7262_CONFIG_H
#define TOPPERS_SH7262_CONFIG_H

#ifndef TOPPERS_TARGET_CONFIG_H
#error  target_config.h is not included!
#endif	/*  TOPPERS_TARGET_CONFIG_H  */

/*
 * CPU例外番号に関する定義
 */
#define TMIN_EXCNO		UINT_C(4)		/*	GENERAL_ILLEGAL_INSTRUCTION_VECTOR	*/
#define TMAX_EXCNO		UINT_C(63)		/*	TRAPA_INST_VECTOR  */
#define TNUM_EXC		(TMAX_EXCNO - TMIN_EXCNO + 1U)

/*
 * 割込みハンドラ番号に関する定義
 */
#define TMIN_INHNO		UINT_C(64)
#define TMAX_INHNO		UINT_C(312)
#define TNUM_INH		(TMAX_INHNO - TMIN_INHNO + 1U)

/*
 * 割込み番号に関する定義
 */
#define TMIN_INTNO		UINT_C(64)
#define TMAX_INTNO		UINT_C(312)
#define TNUM_INT		(TMAX_INTNO - TMIN_INTNO + 1U)

/*	IRQ  */
#define TMIN_INTNO_IRQ 	64U
#define TMAX_INTNO_IRQ	71U

/*
 *	割込み要求ライン毎の優先度設定レジスタの設定情報
 */
#define IPR_INFO_TBL_DATA	\
	{IPR01_h, 12U}, /*  64 IRQ0 */ \
	{IPR01_h,  8U}, /*  65 IRQ1 */ \
	{IPR01_h,  4U}, /*  66 IRQ2 */ \
	{IPR01_h,  0U}, /*  67 IRQ3 */ \
	{IPR02_h, 12U}, /*  68 IRQ4 */ \
	{IPR02_h,  8U}, /*  69 IRQ5 */ \
	{IPR02_h,  4U}, /*  70 IRQ6 */ \
	{IPR02_h,  0U}, /*  71 IRQ7 */ \
\
	{0U, 0U},	  /*  72 */ \
	{0U, 0U},	  /*  73 */ \
	{0U, 0U},	  /*  74 */ \
	{0U, 0U},	  /*  75 */ \
	{0U, 0U},	  /*  76 */ \
	{0U, 0U},	  /*  77 */ \
	{0U, 0U},	  /*  78 */ \
	{0U, 0U},	  /*  79 */ \
\
	{IPR05_h, 12U}, /*  80 PINT0 */ \
	{IPR05_h, 12U}, /*  81 PINT1 */ \
	{IPR05_h, 12U}, /*  82 PINT2 */ \
	{IPR05_h, 12U}, /*  83 PINT3 */ \
	{IPR05_h, 12U}, /*  84 PINT4 */ \
	{IPR05_h, 12U}, /*  85 PINT5 */ \
	{IPR05_h, 12U}, /*  86 PINT6 */ \
	{IPR05_h, 12U}, /*  87 PINT7 */ \
\
	{0U, 0U},	  /*  88 */ \
	{0U, 0U},	  /*  89 */ \
	{0U, 0U},	  /*  90 */ \
	{0U, 0U},	  /*  91 */ \
	{0U, 0U},	  /*  92 */ \
	{0U, 0U},	  /*  93 */ \
	{0U, 0U},	  /*  94 */ \
	{0U, 0U},	  /*  95 */ \
	{0U, 0U},	  /*  96 */ \
	{0U, 0U},	  /*  97 */ \
	{0U, 0U},	  /*  98 */ \
	{0U, 0U},	  /*  99 */ \
	{0U, 0U},	  /* 100 */ \
	{0U, 0U},	  /* 101 */ \
	{0U, 0U},	  /* 102 */ \
	{0U, 0U},	  /* 103 */ \
	{0U, 0U},	  /* 104 */ \
	{0U, 0U},	  /* 105 */ \
	{0U, 0U},	  /* 106 */ \
	{0U, 0U},	  /* 107 */ \
\
	{IPR06_h, 12U}, /* 108 DMAC0 TEI0 */ \
	{IPR06_h, 12U}, /* 109 DMAC0 HEI0 */ \
\
	{0U, 0U},	  /* 110 */ \
	{0U, 0U},	  /* 111 */ \
\
	{IPR06_h,  8U}, /* 112 DMAC1 TEI1 */ \
	{IPR06_h,  8U}, /* 113 DMAC1 HEI1 */ \
\
	{0U, 0U},	  /* 114 */ \
	{0U, 0U},	  /* 115 */ \
\
	{IPR06_h,  4U}, /* 116 DMAC2 TEI2 */ \
	{IPR06_h,  4U}, /* 117 DMAC2 HEI2 */ \
\
	{0U, 0U},	  /* 118 */ \
	{0U, 0U},	  /* 119 */ \
\
	{IPR06_h,  0U}, /* 120 DMAC3 TEI3 */ \
	{IPR06_h,  0U}, /* 121 DMAC3 HEI3 */ \
\
	{0U, 0U},	  /* 122 */ \
	{0U, 0U},	  /* 123 */ \
\
	{IPR07_h, 12U}, /* 124 DMAC4 TEI4 */ \
	{IPR07_h, 12U}, /* 125 DMAC4 HEI4 */ \
\
	{0U, 0U},	  /* 126 */ \
	{0U, 0U},	  /* 127 */ \
\
	{IPR07_h,  8U}, /* 128 DMAC5 TEI5 */ \
	{IPR07_h,  8U}, /* 129 DMAC5 HEI5 */ \
\
	{0U, 0U},	  /* 130 */ \
	{0U, 0U},	  /* 131 */ \
\
	{IPR07_h,  4U}, /* 132 DMAC6 TEI6 */ \
	{IPR07_h,  4U}, /* 133 DMAC6 HEI6 */ \
\
	{0U, 0U},	  /* 134 */ \
	{0U, 0U},	  /* 135 */ \
\
	{IPR07_h,  0U}, /* 136 DMAC7 TEI7 */ \
	{IPR07_h,  0U}, /* 137 DMAC7 HEI7 */ \
\
	{0U, 0U},	  /* 138 */ \
	{0U, 0U},	  /* 139 */ \
\
	{IPR08_h, 12U}, /* 140 DMAC8 TEI8 */ \
	{IPR08_h, 12U}, /* 141 DMAC8 HEI8 */ \
\
	{0U, 0U},	  /* 142 */ \
	{0U, 0U},	  /* 143 */ \
\
	{IPR08_h,  8U}, /* 144 DMAC9 TEI9 */ \
	{IPR08_h,  8U}, /* 145 DMAC9 HEI9 */ \
\
	{0U, 0U},	  /* 146 */ \
	{0U, 0U},	  /* 147 */ \
\
	{IPR08_h,  4U}, /* 148 DMAC10 TEI10 */ \
	{IPR08_h,  4U}, /* 149 DMAC10 HEI10 */ \
\
	{0U, 0U},	  /* 150 */ \
	{0U, 0U},	  /* 151 */ \
\
	{IPR08_h,  0U}, /* 152 DMAC11 TEI11 */ \
	{IPR08_h,  0U}, /* 153 DMAC11 HEI11 */ \
\
	{0U, 0U},	  /* 154 */ \
	{0U, 0U},	  /* 155 */ \
\
	{IPR09_h, 12U}, /* 156 DMAC12 TEI12 */ \
	{IPR09_h, 12U}, /* 157 DMAC12 HEI12 */ \
\
	{0U, 0U},	  /* 158 */ \
	{0U, 0U},	  /* 159 */ \
\
	{IPR09_h,  8U}, /* 160 DMAC13 TEI13 */ \
	{IPR09_h,  8U}, /* 161 DMAC13 HEI13 */ \
\
	{0U, 0U},	  /* 162 */ \
	{0U, 0U},	  /* 163 */ \
\
	{IPR09_h,  4U}, /* 164 DMAC14 TEI14 */ \
	{IPR09_h,  4U}, /* 165 DMAC14 HEI14 */ \
\
	{0U, 0U},	  /* 166 */ \
	{0U, 0U},	  /* 167 */ \
\
	{IPR09_h,  0U}, /* 168 DMAC15 TEI15 */ \
	{IPR09_h,  0U}, /* 169 DMAC15 HEI15 */ \
	{IPR10_h, 12U}, /* 170 USBI */ \
	{IPR10_h,  8U}, /* 171 VIVSYNCJ */ \
	{IPR10_h,  8U}, /* 172 VBUFERR */ \
	{IPR10_h,  8U}, /* 173 VIFIELDE */ \
	{IPR10_h,  8U}, /* 174 VOLINE */ \
	{IPR10_h,  4U}, /* 175 CMI0 */ \
	{IPR10_h,  0U}, /* 176 CMI1 */ \
	{IPR11_h, 12U}, /* 177 CMI */ \
	{IPR11_h,  8U}, /* 178 ITI */ \
	{IPR11_h,  4U}, /* 179 MTU0 TGI0A */ \
	{IPR11_h,  4U}, /* 189 MTU0 TGI0B */ \
	{IPR11_h,  4U}, /* 181 MTU0 TGI0C */ \
	{IPR11_h,  4U}, /* 182 MTU0 TGI0D */ \
	{IPR11_h,  0U}, /* 183 MTU0 TGI0V */ \
	{IPR11_h,  0U}, /* 184 MTU0 TGI0E */ \
	{IPR11_h,  0U}, /* 185 MTU0 TGI0F */ \
	{IPR12_h, 12U}, /* 186 MTU1 TGI1A */ \
	{IPR12_h, 12U}, /* 187 MTU1 TGI1B */ \
	{IPR12_h,  8U}, /* 188 MTU1 TGI1V */ \
	{IPR12_h,  8U}, /* 189 MTU1 TGI1U */ \
	{IPR12_h,  4U}, /* 190 MTU2 TGI2A */ \
	{IPR12_h,  4U}, /* 191 MTU2 TGI2B */ \
	{IPR12_h,  0U}, /* 192 MTU2 TGI2V */ \
	{IPR12_h,  0U}, /* 193 MTU2 TGI2U */ \
	{IPR13_h, 12U}, /* 194 MTU3 TGI3A */ \
	{IPR13_h, 12U}, /* 195 MTU3 TGI3B */ \
	{IPR13_h, 12U}, /* 196 MTU3 TGI3C */ \
	{IPR13_h, 12U}, /* 197 MTU3 TGI3D */ \
	{IPR13_h,  8U}, /* 198 MTU3 TGI3V */ \
	{IPR13_h,  4U}, /* 199 MTU4 TGI4A */ \
	{IPR13_h,  4U}, /* 200 MTU4 TGI4B */ \
	{IPR13_h,  4U}, /* 201 MTU4 TGI4C */ \
	{IPR13_h,  4U}, /* 202 MTU4 TGI4D */ \
	{IPR13_h,  0U}, /* 203 MTU4 TGI4V */ \
	{IPR14_h, 12U}, /* 204 PWM1 */ \
	{IPR14_h,  8U}, /* 205 PWM2 */ \
	{IPR14_h,  4U}, /* 206 ADI */ \
	{IPR15_h, 12U}, /* 207 SSI0 SSIF0 */ \
	{IPR15_h, 12U}, /* 208 SSI0 SSIRXI0 */ \
	{IPR15_h, 12U}, /* 209 SSI0 SSITXI0 */ \
	{IPR15_h,  8U}, /* 210 SSI1 SSIF1 */ \
	{IPR15_h,  8U}, /* 211 SSI1 SSIRTI1 */ \
	{IPR15_h,  4U}, /* 212 SSI2 SSIF2 */ \
	{IPR15_h,  4U}, /* 213 SSI2 SSIRTI2 */ \
	{IPR15_h,  0U}, /* 214 SSI3 SSIF3 */ \
	{IPR15_h,  0U}, /* 215 SSI3 SSIRTI3 */ \
	{IPR16_h, 12U}, /* 216 SPDIFI */ \
	{IPR16_h,  8U}, /* 217 IIC30 STPI */ \
	{IPR16_h,  8U}, /* 218 IIC30 NAKI */ \
	{IPR16_h,  8U}, /* 219 IIC30 RXI  */ \
	{IPR16_h,  8U}, /* 220 IIC30 TXI  */ \
	{IPR16_h,  8U}, /* 221 IIC30 TEI  */ \
	{IPR16_h,  4U}, /* 222 IIC31 STPI */ \
	{IPR16_h,  4U}, /* 223 IIC31 NAKI */ \
	{IPR16_h,  4U}, /* 224 IIC31 RXI  */ \
	{IPR16_h,  4U}, /* 225 IIC31 TXI  */ \
	{IPR16_h,  4U}, /* 226 IIC31 TEI  */ \
	{IPR16_h,  0U}, /* 227 IIC32 STPI */ \
	{IPR16_h,  0U}, /* 228 IIC32 NAKI */ \
	{IPR16_h,  0U}, /* 229 IIC32 RXI  */ \
	{IPR16_h,  0U}, /* 230 IIC32 TXI  */ \
	{IPR16_h,  0U}, /* 231 IIC32 TEI  */ \
	{IPR17_h, 12U}, /* 232 SCIF0 BRI0 */ \
	{IPR17_h, 12U}, /* 233 SCIF0 ERI0 */ \
	{IPR17_h, 12U}, /* 234 SCIF0 RXI0 */ \
	{IPR17_h, 12U}, /* 235 SCIF0 TXI0 */ \
	{IPR17_h,  8U}, /* 236 SCIF1 BRI1 */ \
	{IPR17_h,  8U}, /* 237 SCIF1 ERI1 */ \
	{IPR17_h,  8U}, /* 238 SCIF1 RXI1 */ \
	{IPR17_h,  8U}, /* 239 SCIF1 TXI1 */ \
	{IPR17_h,  4U}, /* 240 SCIF2 BRI2 */ \
	{IPR17_h,  4U}, /* 241 SCIF2 ERI2 */ \
	{IPR17_h,  4U}, /* 242 SCIF2 RXI2 */ \
	{IPR17_h,  4U}, /* 243 SCIF2 TXI2 */ \
	{IPR17_h,  0U}, /* 244 SCIF3 BRI3 */ \
	{IPR17_h,  0U}, /* 245 SCIF3 ERI3 */ \
	{IPR17_h,  0U}, /* 246 SCIF3 RXI3 */ \
	{IPR17_h,  0U}, /* 247 SCIF3 TXI3 */ \
	{IPR18_h, 12U}, /* 248 SCIF4 BRI4 */ \
	{IPR18_h, 12U}, /* 249 SCIF4 ERI4 */ \
	{IPR18_h, 12U}, /* 250 SCIF4 RXI4 */ \
	{IPR18_h, 12U}, /* 251 SCIF4 TXI4 */ \
	{IPR18_h,  8U}, /* 252 SCIF5 BRI5 */ \
	{IPR18_h,  8U}, /* 253 SCIF5 ERI5 */ \
	{IPR18_h,  8U}, /* 254 SCIF5 RXI5 */ \
	{IPR18_h,  8U}, /* 255 SCIF5 TXI5 */ \
	{IPR18_h,  4U}, /* 256 SCIF6 BRI6 */ \
	{IPR18_h,  4U}, /* 257 SCIF6 ERI6 */ \
	{IPR18_h,  4U}, /* 258 SCIF6 RXI6 */ \
	{IPR18_h,  4U}, /* 259 SCIF6 TXI6 */ \
	{IPR18_h,  0U}, /* 260 SCIF7 BRI7 */ \
	{IPR18_h,  0U}, /* 261 SCIF7 ERI7 */ \
	{IPR18_h,  0U}, /* 262 SCIF7 RXI7 */ \
	{IPR18_h,  0U}, /* 263 SCIF7 TXI7 */ \
	{IPR19_h, 12U}, /* 264 SIOFI */ \
	{IPR19_h,  4U}, /* 265 RSPI0 SPEI0 */ \
	{IPR19_h,  4U}, /* 266 RSPI0 SPRI0 */ \
	{IPR19_h,  4U}, /* 267 RSPI0 SPTI0 */ \
	{IPR19_h,  0U}, /* 268 RSPI1 SPEI1 */ \
	{IPR19_h,  0U}, /* 269 RSPI1 SPRI1 */ \
	{IPR19_h,  0U}, /* 270 RSPI1 SPTI1 */ \
	{IPR20_h, 12U}, /* 271 CAN0 ERS0 */ \
	{IPR20_h, 12U}, /* 272 CAN0 OVR0 */ \
	{IPR20_h, 12U}, /* 273 CAN0 RM00 */ \
	{IPR20_h, 12U}, /* 274 CAN0 RM10 */ \
	{IPR20_h, 12U}, /* 275 CAN0 SLE0 */ \
	{IPR20_h,  8U}, /* 276 CAN1 ERS1 */ \
	{IPR20_h,  8U}, /* 277 CAN1 OVR1 */ \
	{IPR20_h,  8U}, /* 278 CAN1 RM01 */ \
	{IPR20_h,  8U}, /* 279 CAN1 RM11 */ \
	{IPR20_h,  8U}, /* 280 CAN1 SLE1 */ \
	{IPR20_h,  4U}, /* 281 IEB */ \
	{IPR20_h,  0U}, /* 282 CDD ISY */ \
	{IPR20_h,  0U}, /* 283 CDD IERR */ \
	{IPR20_h,  0U}, /* 284 CDD ITARG */ \
	{IPR20_h,  0U}, /* 285 CDD ISEC */ \
	{IPR20_h,  0U}, /* 286 CDD IBUF */ \
	{IPR20_h,  0U}, /* 287 CDD IREADY */ \
	{IPR21_h, 12U}, /* 288 NAND FLSTEI */ \
	{IPR21_h, 12U}, /* 289 NAND FLTENDI */ \
	{IPR21_h, 12U}, /* 290 NAND FLTREQ0I */ \
	{IPR21_h, 12U}, /* 291 NAND FLTREQ1I */ \
	{IPR21_h,  8U}, /* 292 SDHI SDHI3 */ \
	{IPR21_h,  8U}, /* 293 SDHI SDHI0 */ \
	{IPR21_h,  8U}, /* 294 SDHI SDHI1 */ \
\
	{0U, 0U},	  /* 295 */ \
\
	{IPR21_h,  4U}, /* 296 RTC ARM */ \
	{IPR21_h,  4U}, /* 297 RTC PRD */ \
	{IPR21_h,  4U}, /* 298 RTC CUP */ \
	{IPR22_h, 12U}, /* 299 SRC0 OVF0 */ \
	{IPR22_h, 12U}, /* 300 SRC0 UDF0 */ \
	{IPR22_h, 12U}, /* 301 SRC0 CEF0 */ \
	{IPR22_h, 12U}, /* 302 SRC0 ODFI0 */ \
	{IPR22_h, 12U}, /* 303 SRC0 IDEI0 */ \
	{IPR22_h,  8U}, /* 304 SRC1 OVF0 */ \
	{IPR22_h,  8U}, /* 305 SRC1 UDF0 */ \
	{IPR22_h,  8U}, /* 306 SRC1 CEF0 */ \
	{IPR22_h,  8U}, /* 307 SRC1 ODFI0 */ \
	{IPR22_h,  8U}, /* 308 SRC1 IDEI0 */ \
\
	{0U, 0U},	  /* 309 */ \
\
	{IPR22_h,  0U}, /* 310 DCU DCUEI */ \
	{IPR22_h,  0U}, /* 311 DCU OFFI */ \
	{IPR22_h,  0U}  /* 312 DCU IFEI */


#ifndef TOPPERS_MACRO_ONLY
/*
 * 割込み優先レベル設定レジスタの初期化
 * 　ペリファラルの数によって、割込み優先レベル設定レジスタの構成が
 * 　異なるため、チップ依存部で定義する。
 */
Inline void
init_ipr(void)
{
	sil_wrh_mem((uint16_t *)IPR01_h, 0x0000U);
	sil_wrh_mem((uint16_t *)IPR02_h, 0x0000U);
	sil_wrh_mem((uint16_t *)IPR05_h, 0x0000U);
	sil_wrh_mem((uint16_t *)IPR06_h, 0x0000U);
	sil_wrh_mem((uint16_t *)IPR07_h, 0x0000U);
	sil_wrh_mem((uint16_t *)IPR08_h, 0x0000U);
	sil_wrh_mem((uint16_t *)IPR09_h, 0x0000U);
	sil_wrh_mem((uint16_t *)IPR10_h, 0x0000U);
	sil_wrh_mem((uint16_t *)IPR11_h, 0x0000U);
	sil_wrh_mem((uint16_t *)IPR12_h, 0x0000U);
	sil_wrh_mem((uint16_t *)IPR13_h, 0x0000U);
	sil_wrh_mem((uint16_t *)IPR14_h, 0x0000U);
	sil_wrh_mem((uint16_t *)IPR15_h, 0x0000U);
	sil_wrh_mem((uint16_t *)IPR16_h, 0x0000U);
	sil_wrh_mem((uint16_t *)IPR17_h, 0x0000U);
	sil_wrh_mem((uint16_t *)IPR18_h, 0x0000U);
	sil_wrh_mem((uint16_t *)IPR19_h, 0x0000U);
	sil_wrh_mem((uint16_t *)IPR20_h, 0x0000U);
	sil_wrh_mem((uint16_t *)IPR21_h, 0x0000U);
	sil_wrh_mem((uint16_t *)IPR22_h, 0x0000U);
}

#endif /* TOPPERS_MACRO_ONLY */

/*
 *	プロセッサ依存モジュール（SH2A用）
 */
#include "sh12a_gcc/sh2a_config.h"

#endif /* TOPPERS_SH7262_CONFIG_H */
