#include "_ren.h"

int _ren_setup(struct screen *screen, int width, int height) {
	SDL_Init(SDL_INIT_VIDEO);
	screen->window = SDL_CreateWindow("SDL2 Pixel Drawing", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    screen->renderer = SDL_CreateRenderer(screen->window, -1, 0);
    screen->texture = SDL_CreateTexture(screen->renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, width, height);
    screen->pixels = malloc(width * height * sizeof(Uint32));
	screen->size[0] = width;
	screen->size[1] = height;
	screen->deltatime = 0;
}

int _ren_clear(struct screen *screen, Uint32 color) {
	memset(screen->pixels, color, screen->size[0] * screen->size[1] * sizeof(Uint32));
}

int _ren_handle(struct screen *screen) {
	static int old = 0, new = 0;
	old = new;
	new = SDL_GetTicks();
	screen->deltatime = (float)(new-old) / 1000.0;
	SDL_UpdateTexture(screen->texture, NULL, screen->pixels, screen->size[0] * sizeof(Uint32));
	SDL_PollEvent(&(screen->event));
	switch (screen->event.type) {
		case SDL_QUIT:
			return 1;
	}
	SDL_RenderClear(screen->renderer);
	SDL_RenderCopy(screen->renderer, screen->texture, NULL, NULL);
	SDL_RenderPresent(screen->renderer);
}

int _ren_quit(struct screen *screen) {
	free(screen->pixels);
	SDL_DestroyTexture(screen->texture);
	SDL_DestroyRenderer(screen->renderer);
	SDL_DestroyWindow(screen->window);
	SDL_Quit();
}

int _ren_drawpx(struct screen *screen, int x, int y, Uint32 color) {
	screen->pixels[x + y * screen->size[0]] = color;
}

int _ren_drawrect(struct screen *screen, int x1, int y1, int x2, int y2, Uint32 color) {
	for(int y = y1; y < y2; y++)
		for(int x = x1; x < x2; x++)
			_ren_drawpx(screen, x, y, color);
}

int _ren_drawsprite(struct screen *screen, int _x, int _y, int xsz, int ysz, Uint32 *color) {
	for(int y = 0; y < ysz; y++)
		for(int x = 0; x < xsz; x++)
			_ren_drawpx(screen, _x + x, _y + x, color[x + y * xsz]);
}
