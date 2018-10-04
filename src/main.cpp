/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <cstdlib>
#include <getopt.h>
#include "log.h"
#include "gameview.h"

//Screen dimension constants
static int SCREEN_WIDTH = 640;
static int SCREEN_HEIGHT = 480;
static int FPS = 32;

void processArgs(int argc, char **argv)
{
    int c;
    extern char *optarg;
    extern int optopt;

    while ((c = getopt(argc, argv, "w:h:f:")) != -1) {
        switch(c) {
        case 'w':
            SCREEN_WIDTH = atoi(optarg);
            break;
        case 'h':
            SCREEN_HEIGHT = atoi(optarg);
            break;
        case 'f':
            FPS = atoi(optarg);
            break;
        case '?':
            lprintf("unknown arg %c\n", optopt);
            break;
        }
    }

    lprintf("Setting window size to %dx%d.\n", SCREEN_WIDTH, SCREEN_HEIGHT);
    lprintf("Setting FPS to %d.\n", FPS);
}

void close()
{
    SDL_Quit();
    close_log();
}

int main(int argc, char** argv)
{
    start_log();
    processArgs(argc, argv);

    GameView *gameView = new GameView(SCREEN_WIDTH, SCREEN_HEIGHT);
    gameView->loop(1000 / FPS);

    delete gameView;

    close();

    return 0;
}