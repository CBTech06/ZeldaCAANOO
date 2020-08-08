/*************** Game & watch  Zelda **********************/
/*                  By NINTENDO                          */
/*         Coding for CAANOO by Captainchris PRD        */
/*                                                     */
/*******************************************************/

#ifndef EVENT_H
#define EVENT_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <stdlib.h>

typedef struct {
    int *buttons;
    int *axes;
    int joystate;
    int buttonstate;
    int attack;
} t_event;

void event_joystate(t_event *p_event);



SDL_Event event_State;



#endif
