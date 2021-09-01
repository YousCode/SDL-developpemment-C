#include "input.h"
#include <stdio.h>

int input_handler(Entity *entity){
     SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case  SDL_QUIT :
        return -1;
     case SDL_KEYDOWN:
     printf("Keys is down\n");
     switch (event.key.keysym.sym)
     {
     case SDLK_UP:
          entity->pos_y -= 4;
         break;
     case SDLK_DOWN:
          entity->pos_y += 4;
          break;
     
     }
       break;
     case SDL_KEYUP:  
     printf("Keys is up\n");
     break;
        
        default:
        break;
    }
    return 0;
}
