#ifndef DRAW
#define DRAW

#include "window.h"
#include <SDL2/SDL_image.h>
    
    
typedef struct {
    SDL_Rect position;
    SDL_Texture *texture;
} Entity;

typedef struct {
    SDL_Rect position;
    SDL_Texture *texture;
} Missile;



void prepareCanvas(Win *app);
void presentCanvas(Win *app);
SDL_Texture *loadTexture(Win *app, char *img_path);
void drawEntity(Win *app, Entity *entity);
void missile(Win *app, Missile *missile);



#endif /* !DRAW */