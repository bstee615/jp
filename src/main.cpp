/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <cstdlib>
#include <getopt.h>
#include "log.h"
#include "gamemanager.h"

//Screen dimension constants
static int SCREEN_WIDTH = 640;
static int SCREEN_HEIGHT = 480;

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
            lprintf("unknown arg %c\n", optopt);
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

    GameManager *manager = new GameManager(SCREEN_WIDTH, SCREEN_HEIGHT);
    manager->loadImage("hello_world.bmp");
    manager->loop();

    delete manager;

    close();

    return 0;
}