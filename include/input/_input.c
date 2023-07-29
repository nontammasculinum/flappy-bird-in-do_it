#include "_input.h"

int _inp_is_key_pressed(struct screen screen, int key, int up) {
	if((screen.event.type != SDL_KEYDOWN && !up) || (screen.event.type != SDL_KEYUP && up)) return 0;
	switch(key) {
	case '0': return screen.event.key.keysym.sym == SDLK_0;
	case '1': return screen.event.key.keysym.sym == SDLK_1;
	case '2': return screen.event.key.keysym.sym == SDLK_2;
	case '3': return screen.event.key.keysym.sym == SDLK_3;
	case '4': return screen.event.key.keysym.sym == SDLK_4;
	case '5': return screen.event.key.keysym.sym == SDLK_5;
	case '6': return screen.event.key.keysym.sym == SDLK_6;
	case '7': return screen.event.key.keysym.sym == SDLK_7;
	case '8': return screen.event.key.keysym.sym == SDLK_8;
	case '9': return screen.event.key.keysym.sym == SDLK_9;
	case 'A': return screen.event.key.keysym.sym == SDLK_a;
	case 'B': return screen.event.key.keysym.sym == SDLK_b;
	case 'C': return screen.event.key.keysym.sym == SDLK_c;
	case 'D': return screen.event.key.keysym.sym == SDLK_d;
	case 'E': return screen.event.key.keysym.sym == SDLK_e;
	case 'F': return screen.event.key.keysym.sym == SDLK_f;
	case 'G': return screen.event.key.keysym.sym == SDLK_g;
	case 'H': return screen.event.key.keysym.sym == SDLK_h;
	case 'I': return screen.event.key.keysym.sym == SDLK_i;
	case 'J': return screen.event.key.keysym.sym == SDLK_j;
	case 'K': return screen.event.key.keysym.sym == SDLK_k;
	case 'L': return screen.event.key.keysym.sym == SDLK_l;
	case 'M': return screen.event.key.keysym.sym == SDLK_m;
	case 'N': return screen.event.key.keysym.sym == SDLK_n;
	case 'O': return screen.event.key.keysym.sym == SDLK_o;
	case 'P': return screen.event.key.keysym.sym == SDLK_p;
	case 'Q': return screen.event.key.keysym.sym == SDLK_q;
	case 'R': return screen.event.key.keysym.sym == SDLK_r;
	case 'S': return screen.event.key.keysym.sym == SDLK_s;
	case 'T': return screen.event.key.keysym.sym == SDLK_t;
	case 'U': return screen.event.key.keysym.sym == SDLK_u;
	case 'V': return screen.event.key.keysym.sym == SDLK_v;
	case 'W': return screen.event.key.keysym.sym == SDLK_w;
	case 'X': return screen.event.key.keysym.sym == SDLK_x;
	case 'Y': return screen.event.key.keysym.sym == SDLK_y;
	case 'Z': return screen.event.key.keysym.sym == SDLK_z;
	case KEY_SPACE:       return screen.event.key.keysym.sym == SDLK_SPACE;
	case KEY_SHIFT:       return screen.event.key.keysym.sym == SDLK_LSHIFT;
	case KEY_ESCAPE:      return screen.event.key.keysym.sym == SDLK_ESCAPE;
	case KEY_CTRL:        return screen.event.key.keysym.sym == SDLK_LCTRL;
	case KEY_ALT:         return screen.event.key.keysym.sym == SDLK_LALT;
	case KEY_LEFT_ARROW:  return screen.event.key.keysym.sym == SDLK_LEFT;
	case KEY_RIGHT_ARROW: return screen.event.key.keysym.sym == SDLK_RIGHT;
	case KEY_UP_ARROW:    return screen.event.key.keysym.sym == SDLK_UP;
	case KEY_DOWN_ARROW:  return screen.event.key.keysym.sym == SDLK_DOWN;
	default: return 0;
	}
}
