#include <kernel.h>
#include <t_syslog.h>
#include "target_lcd.h"

void lcd_initialize(intptr_t exinf)
{
	sh_vdc3_initialize();
	sh_vdc3_fill();
	sh_vdc3_swap();
}

void lcd_vsync_handler()
{
	sh_vdc3_clear_int_line();
}
