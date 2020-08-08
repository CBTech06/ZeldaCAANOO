/*************** Game & watch  Zelda **********************/
/*                  By NINTENDO                          */
/*         Coding for CAANOO by Captainchris PRD        */
/*                                                     */
/*******************************************************/

#ifndef MAIN_H
#define MAIN_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <stdlib.h>

#include "event.h"
#include "menu.h"
#include "game.h"


enum { MENU, GAMEW, GAMECP };

SDL_Joystick *stick;

#endif
