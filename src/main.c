/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "log.h"
#include "jp.h"

//Screen dimension constants
static int SCREEN_WIDTH = 640;
static int SCREEN_HEIGHT = 480;

void initSDL()
{
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		lprintf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
    else {
		lprintf("Initialized SDL.\n");
    }
}

void initWindow(SDL_Window *window)
{
    window = SDL_CreateWindow( "JetPack", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

    if( window == NULL )
    {
        lprintf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
		lprintf("Initialized Window.\n");
    }
}

void processArgs(int argc, char **argv)
{
    int c;
    extern char *optarg;
    extern int optind, optopt, opterr;

    int default_size = 1;

    while ((c = getopt(argc, argv, "w:h:")) != -1) {
        switch(c) {
        case 'w':
            SCREEN_WIDTH = atoi(optarg);
            default_size = 0;
            break;
        case 'h':
            SCREEN_HEIGHT = atoi(optarg);
            default_size = 0;
            break;
        case '?':
            printf("unknown arg %c\n", optopt);
            break;
        }
    }

    if (default_size) {
        lprintf("Setting window size to default 800x600.\n");
    }
}

void cleanup(SDL_Window *window)
{
	SDL_DestroyWindow(window);
	SDL_Quit();

    close_log();
}

int main(int argc, char** argv)
{
    start_log();
    processArgs(argc, argv);

    initSDL();

	SDL_Window* window = NULL;
    initWindow(window);

    jp_loop(window);
    cleanup(window);

	return 0;
}