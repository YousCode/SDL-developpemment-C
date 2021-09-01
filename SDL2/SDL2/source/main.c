#include <stdio.h>
#include <stdlib.h>
#include "window.h"
#include "input.h"
#include "draw.h"
#include "init.h"
#include "fonction.c"



int main()
{
    Win *app = malloc(sizeof(Win));
    Entity *player = malloc(sizeof(Entity));
    Missile *obstacle = malloc(sizeof(Missile));
    Entity *gameover = malloc(sizeof(Entity));


    if (initSDL(app) < 0){
        return -1;
    }
    const int MAX = 500, MIN = 100; 

 
    player->position.x = 100;
    player->position.y = 100;
    player->position.w = 100;
    player->position.h = 100;
    player->texture = loadTexture(app, "ressource/zlatan.png");

    gameover->position.x = 0;
    gameover->position.y = 0;
    gameover->position.w = WINDOW_WIDTH;
    gameover->position.h = WINDOW_HEIGHT;
    gameover->texture = loadTexture(app, "ressource/gameover.jpg");

    obstacle->position.x = 950;
    obstacle->position.y = (rand() % (MAX - MIN + 1)) + MIN;
    obstacle->position.w = 50;
    obstacle->position.h = 50;
    obstacle->texture = loadTexture(app, "ressource/ldc.png");

    int perdu = 0;

    while (input_handler(player) == 0)
    {   

        prepareCanvas(app);
        if(perdu == 0)
        {

            drawEntity(app, player);
            missile(app, obstacle);
       
            obstacle->position.x -= 15;

        if(obstacle->position.x <= -50 )
        {
            obstacle->position.x = 800;
            obstacle->position.y = (rand() % (MAX - MIN + 1)) + MIN;

        }
           if (collapse(obstacle, player) == 1)
        {
           
            perdu = 1;
            
        }

        }else
        {
             drawEntity(app,gameover);
        }
       
     
        presentCanvas(app);
        SDL_Delay(20);
    } 
    return 0;
}