#include <SDL2/SDL.h>
#include "../render/_ren.h"

enum _special_keys {
	KEY_SPACE,
	KEY_SHIFT,
	KEY_ESCAPE,
	KEY_CTRL,
	KEY_ALT,
	KEY_LEFT_ARROW,
	KEY_RIGHT_ARROW,
	KEY_UP_ARROW,
	KEY_DOWN_ARROW,
};

int _inp_is_key_pressed(struct screen screen, int key, int up);
