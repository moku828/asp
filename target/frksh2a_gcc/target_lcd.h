#ifndef TOPPERS_TARGET_LCD_H
#define TOPPERS_TARGET_LCD_H

#include "frksh2a.h"
#include "pdic/sh/sh_vdc3.h"

#define INHNO_LCD_VSYNC	 VDC3_VOLINE_VECTOR /* 割込みハンドラ番号 */
#define INTNO_LCD_VSYNC	 VDC3_VOLINE_VECTOR /* 割込み番号 */
#define INTPRI_LCD		 (-4)				/* 割込み優先度 */
#define INTATR_LCD		 0U 				/* 割込み属性 */

#ifndef TOPPERS_MACRO_ONLY

extern void lcd_initialize(intptr_t exinf);
extern void lcd_vsync_handler();

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_TARGET_LCD_H */
