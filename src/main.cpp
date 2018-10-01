/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "log.h"
#include "window.h"
#include "image.h"

//Screen dimension constants
static int SCREEN_WIDTH = 640;
static int SCREEN_HEIGHT = 480;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

void processArgs(int argc, char **argv)
{
    int c;
    extern char *optarg;
    extern int optopt;

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

void close()
{
    SDL_Quit();
    close_log();
}

int main( int argc, char** argv )
{
    start_log();
    processArgs(argc, argv);

    Window *window = new Window("JetPack", SCREEN_WIDTH, SCREEN_HEIGHT);
    
    
    Image *img = new Image("hello_world.bmp");
    SDL_Rect srcrect = {200, 200, 300, 300};
    SDL_Rect dstrect = {10, 10, 0, 0};
    SDL_BlitSurface(img->surface, &srcrect, window->screenSurface, &dstrect);
    SDL_UpdateWindowSurface(window->window);
    SDL_Delay(2000);
    
    delete window;
    delete img;

    close();

    return 0;
}