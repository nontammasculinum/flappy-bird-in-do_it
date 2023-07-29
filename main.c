#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "do_it.h"

//pong

void game_start(struct screen *screen);
void game_end(struct screen *screen);

int main() {
	srand(time(NULL));
	struct rigidbody 
		bird   = _rb_new(_v2_new(30, 250), 10, 15),
		pipe   = _rb_new_aabb(_v2_new(400, 250), 10, _v2_new(30, 100)),
		pipe_2 = _rb_new_aabb(_v2_new(400, 250), 10, _v2_new(30, 400));
	int bird_out_bounds,
		pipe_spawn = 1,
		pipe_handle,
		score = 0xFF000000;
	_rb_add_bounds(&bird, _v2_new(-1, 500));

	struct screen screen;
	_ren_setup(&screen, 500, 500);
	_ren_clear(&screen, 0x0);
	game_start(&screen);
	do {
		if(pipe_spawn) {
			float pos = (float)(rand() % 300 + 50);
			pipe.position = _v2_new(470, 0);
			pipe.collider.size = _v2_new(30, pos);
			pipe.velocity = _v2_new(-100, 0);
			pipe_2.position = _v2_new(470, pos + 150);
			pipe_2.collider.size = _v2_new(30, 499 - (pos + 150));
			pipe_2.velocity = _v2_new(-100, 0);
			pipe_spawn = 0;
			score += 0x0F;
		}
		_rb_default_stop_bound_handling(
				&bird, bird_out_bounds = _rb_handle(&bird, screen.deltatime));
		_rb_default_stop_bound_handling(
				&pipe, pipe_handle = _rb_handle(&pipe, screen.deltatime));
		_rb_default_stop_bound_handling(
				&pipe_2, _rb_handle(&pipe_2, screen.deltatime));
		if(pipe_handle != BOUND_IN) pipe_spawn = 1;
		if(bird_out_bounds == BOUND_IN)
			_rb_add_force(&bird, _v2_smul(_v2_new(0, 980), screen.deltatime));
		if(bird_out_bounds == BOUND_OUT_Y_MAX) {
			game_end(&screen);
			break;
		}

		if(_rb_is_colliding(bird, pipe) || _rb_is_colliding(bird, pipe_2)) {
			game_end(&screen);
			break;
		}

		if(_inp_is_key_pressed(screen, KEY_SPACE, 1))
			bird.velocity = _v2_new(0, -400);

		_ren_clear(&screen, 0xFF0011EE);
		_ren_drawrect(
				&screen,
				bird.position.x - bird.collider.radius,
				bird.position.y - bird.collider.radius,
				bird.position.x + bird.collider.radius,
				bird.position.y + bird.collider.radius,
				0xFFFFEA00
			);
		_ren_drawrect(
				&screen,
				pipe.position.x,
				pipe.position.y,
				pipe.position.x + pipe.collider.size.x,
				pipe.position.y + pipe.collider.size.y,
				0xFF00EA00
			);
		_ren_drawrect(
				&screen,
				pipe_2.position.x,
				pipe_2.position.y,
				pipe_2.position.x + pipe_2.collider.size.x,
				pipe_2.position.y + pipe_2.collider.size.y,
				0xFF00EA00
			);
		_ren_drawrect(
				&screen,
				450,
				450,
				499,
				499,
				score
			);
	} while(!_ren_handle(&screen));
	_ren_quit(&screen);
	return 0;
}

void game_start(struct screen *screen) {
	printf("press space to start\n");
	do {
		_ren_clear(screen, 0x0);
		if(_inp_is_key_pressed(*screen, KEY_SPACE, 1))
			break;
	} while(!_ren_handle(screen));
}

void game_end(struct screen *screen) {
	printf("GAME OVER\npress space to exit\n");
	do {
		_ren_clear(screen, 0x0);
		if(_inp_is_key_pressed(*screen, KEY_SPACE, 1))
			break;
	} while(!_ren_handle(screen));
}
