#include "input.h"

int input_handler(Entity *entity) {
    SDL_Event event;
    int max_y = 460;
   int min_y = 0;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT :
        return -1;
    case SDL_KEYDOWN :
        printf("key is down\n");
        switch (event.key.keysym.sym)
        {
            case SDLK_ESCAPE: /* Appui sur la touche Echap, on arrête le programme */
    return -1;
        break;
        case SDLK_UP:
          if(entity->position.y>min_y){
        entity->position.y -=  20;
        }
        
            break;
        case SDLK_DOWN:
        if(entity->position.y<max_y){
        entity->position.y += 20;
        }
            break;
        }
        break;
    case SDL_KEYUP :
        printf("key is up\n");
        break;
    default:
        break;
    }
    return 0;

}