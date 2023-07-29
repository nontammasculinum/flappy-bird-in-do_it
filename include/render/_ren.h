#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#ifndef _RENH
#define _RENH


struct screen {
	SDL_Event    event;
	SDL_Window   *window;
	SDL_Renderer *renderer;
	SDL_Texture  *texture;
	Uint32       *pixels;
	int           size[2];
	float         deltatime;
};

int _ren_setup(struct screen *screen, int width, int height);
int _ren_clear(struct screen *screen, Uint32 color);
int _ren_handle(struct screen *screen);
int _ren_quit(struct screen *screen);
int _ren_drawpx(struct screen *screen, int x, int y, Uint32 color);
int _ren_drawrect(struct screen *screen, int x1, int y1, int x2, int y2, Uint32 color);
int _ren_drawsprite(struct screen *screen, int _x, int _y, int xsz, int ysz, Uint32 *color);

#endif
