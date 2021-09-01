#include "init.h"


int initSDL(Win *app)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Je ne peux pas initialiser SDL: %s\n",SDL_GetError());
        return -1;
    }
    
    app->window = SDL_CreateWindow(WINDOW_NAME, 
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 920, 560, 0);

    if (!app->window)
    {
        printf("Je n'ai pas réussir à l'ouvrir %d x %d Fenêtre : %s\n", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_GetError());
        return -1;
    }

    app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_ACCELERATED);
    if(!app->renderer){
            printf("Je n'ai pas réussi a creer le rendu: %s\n", SDL_GetError());
        return -1;
    }
    return 0;
}
