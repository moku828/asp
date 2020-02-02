#define	PGCR7			*((volatile short *)0xFFFE38C0)
#define	PGCR5			*((volatile short *)0xFFFE38C4)
#define	PGCR4			*((volatile short *)0xFFFE38C6)
#define	PGCR3			*((volatile short *)0xFFFE38C8)
#define	PGCR2			*((volatile short *)0xFFFE38CA)
#define	PGCR1			*((volatile short *)0xFFFE38CC)
#define	PGCR0			*((volatile short *)0xFFFE38CE)
#define	PGIOR1			*((volatile short *)0xFFFE38D0)
#define	PGDR1			*((volatile short *)0xFFFE38D4)
#define	STBCR7			*((volatile char  *)0xFFFE0418)
#define	SGMODE			*((volatile long  *)0xFFFF3800)
#define	SGINTCNT		*((volatile long  *)0xFFFF3804)
#define	SYNCNT			*((volatile long  *)0xFFFF3808)
#define	PANEL_CLKSEL	*((volatile long  *)0xFFFF380C)
#define	SYN_SIZE		*((volatile long  *)0xFFFF3900)
#define	PANEL_VSYNC_TIM	*((volatile long  *)0xFFFF3904)
#define	PANEL_HSYNC_TIM	*((volatile long  *)0xFFFF3908)
#define	GRA_VSYNC_TIM	*((volatile long  *)0xFFFF3910)
#define	GRCMEN2			*((volatile long  *)0xFFFF3000)
#define	GRCBUSCNT2		*((volatile long  *)0xFFFF3004)
#define	GROPSADR2		*((volatile long  *)0xFFFF3308)
#define	GROPSWH2		*((volatile long  *)0xFFFF330C)
#define	GROPSOFST2		*((volatile long  *)0xFFFF3310)
#define	GROPDPHV2		*((volatile long  *)0xFFFF3314)

int plane;

void sh_vdc3_initialize()
{
	PGCR7 = (PGCR7 & ~0x0007) | 0x0001;
	PGCR5 &= ~0x0007;
	PGCR4 = (PGCR4 & ~0x0700) | 0x1011;
	PGCR3 = 0x1111;
	PGCR2 = 0x1111;
	PGCR1 = 0x1111;
	PGCR0 = 0x1110;
	PGIOR1 |= 0x0014;
	PGDR1 &= ~0x0014;
	STBCR7 &= ~0x10;
	SGMODE = 0x00000001;
	SGINTCNT = 0x06010000;
	SYNCNT = (SYNCNT & ~0x010C000C) | 0x0000000C;
	PANEL_CLKSEL &= ~0x00001000;
	PANEL_CLKSEL = (PANEL_CLKSEL & ~0x0000203F) | 0x00002008;
	PANEL_CLKSEL |= 0x00001000;
	SYN_SIZE = 0x006F01FB;
	PANEL_VSYNC_TIM = 0x00000001;
	PANEL_HSYNC_TIM = 0x00000001;
	GRA_VSYNC_TIM = 0x00000000;
	GRCMEN2 = 0x00000002;
	GRCBUSCNT2 = 0x00000000;
	GROPSADR2 = 0x1C03C000;
	GROPSWH2 = 0x00600190;
	GROPSOFST2 = 0x00000320;
	GROPDPHV2 = 0x000E005B;
	plane = 0;
	GRCMEN2 |= 0x80000000;
}

void sh_vdc3_clear_int_line()
{
	SGINTCNT &= ~0x00000001;
}

void sh_vdc3_visible(int visible)
{
	if (visible)
	{
		GRCMEN2 |= 0x00000002;
		GRCMEN2 |= 0x80000000;
	}
	else
	{
		GRCMEN2 &= ~0x00000002;
		GRCMEN2 |= 0x80000000;
	}
}

void sh_vdc3_swap()
{
	volatile unsigned long x, y;
	volatile unsigned short *fg;
	volatile unsigned short *bg;
	if (plane)
	{
		fg = (unsigned short *)0x1C03C000;
		bg = (unsigned short *)0x1C050000;
		plane = 0;
	}
	else
	{
		fg = (unsigned short *)0x1C050000;
		bg = (unsigned short *)0x1C03C000;
		plane = 1;
	}
	GROPSADR2 = (long)fg;
	GRCMEN2 |= 0x80000000;
	for (y = 0; y < 96; y++)
	{
		for (x = 0; x < 400; x++)
		{
			*bg = *fg;
			bg++;
			fg++;
		}
	}
}

void sh_vdc3_fill()
{
	volatile unsigned long x, y;
	volatile unsigned short *p;
	if (plane)	p = (unsigned short *)0x1C03C000;
	else		p = (unsigned short *)0x1C050000;
	for (y = 0; y < 96; y++)
	{
		for (x = 0; x < 400; x++)
		{
			*p = 0x0000;
			p++;
		}
	}
}

#define B8B5(b8) (b8 >> 3)
#define B8B6(b8) (b8 >> 2)
#define GRAY2RGB565(gray) ((B8B5(gray) << 11) | (B8B6(gray) << 5) | B8B5(gray))
void sh_vdc3_drawbmp(int x1, int y1, int w1, int h1, unsigned char* bmp1)
{
	volatile unsigned long x, y;
	volatile unsigned short *p;
	volatile unsigned char *bmp;
	if (plane)	p = (unsigned short *)0x1C03C000;
	else		p = (unsigned short *)0x1C050000;
	p += y1 * 400;
	bmp = bmp1;
	bmp += w1 * (h1 - 1);
	for (y = 0; y < h1; y++)
	{
		p += x1;
		for (x = 0; x < w1; x++)
		{
			*p = GRAY2RGB565(*bmp);
			p++;
			bmp++;
		}
		p += (400 - (x1 + w1));
		bmp -= w1 * 2;
	}
}
