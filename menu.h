/*************** Game & watch  Zelda **********************/
/*                  By NINTENDO                          */
/*         Coding for CAANOO by Captainchris PRD        */
/*                                                     */
/*******************************************************/



#ifndef MENU_H
#define MENU_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <stdlib.h>

#include "event.h"
#include "draw.h"
#include "main.h"


enum { NOT_INITIALIZED, INITIALIZED };

typedef struct {
    SDL_Surface *img, *background, *original, *new;
    SDL_Color text;
    SDL_Rect originalFontDest, newFontDest;
    TTF_Font *font;
    int is_initialized;
    int selection;
} t_menu;

int showMenu(t_event *p_event, t_menu *p_menu);
#endif
