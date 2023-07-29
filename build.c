#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *_com = \
" include/render/_ren.c include/physics/_phys.c include/input/_input.c -lSDL2 -lm ";

int main(int argc, char *argv[]) {
	//usage: ./_ <compiler> <flags>
	if(argc < 3) {
		printf("usage: %s <compiler> <flags>\n", argv[0]);
		exit(0);
	}
	char *command = malloc(strlen(argv[1]) + strlen(argv[2]) + strlen(_com) + 1);
	command[0] = '\0';
	strcat(command, argv[1]);
	strcat(command, _com);
	strcat(command, argv[2]);
	printf("%s\n", command);
	system(command);
	return 0;
}
