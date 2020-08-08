/*************** Game & watch  Zelda **********************/
/*                  By NINTENDO                          */
/*         Coding for CAANOO by Captainchris PRD        */
/*                                                     */
/*******************************************************/

#ifndef INIT_H
#define INIT_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <stdlib.h>

#include "menu.h"
#include "music.h"
#include "game.h"

SDL_Surface *initScreen(void);
SDL_Surface *screen;

t_event *initGame();
t_menu *initMenu();
t_game *initGameW();
t_level *initLevel(t_game *p_game);
t_link *initLink(t_game *p_game);
t_ganon *initGanon(t_game *p_game);
t_skeleton *initSkeleton(t_game *p_game);
t_ghini *initGhini(t_game *p_game);
void freeLevel(t_game *p_game);
void freeGameW(t_game  *p_game);
void freeMenu(t_menu *p_menu);
void freeGame(t_event *p_event);


#endif
