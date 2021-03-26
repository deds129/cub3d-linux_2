#include "./includes/cub.h"

void            pixel_put(t_win *wnd, int x, int y, int color)
{
	char    *dst;

	dst = wnd->addr + (y * wnd->line_l + x * (wnd->bpp / 8));
	*(unsigned int*)dst = color;
}