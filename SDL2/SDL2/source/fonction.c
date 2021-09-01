#include <stdio.h>
#include <stdlib.h>
#include "window.h"
#include "input.h"
#include "draw.h"
#include "init.h"

#include <SDL2/SDL.h>


int collapse(Missile *position , Entity *position2)
{
    int result ;
    result = SDL_HasIntersection(&position->position , &position2->position);
    
    return result;
}
 
     
 


	
