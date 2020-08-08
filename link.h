
/*************** Game & watch  Zelda **********************/
/*                  By NINTENDO                          */
/*         Coding for CAANOO by Captainchris PRD        */
/*                                                     */
/*******************************************************/

#ifndef LINK_H
#define LINK_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <stdlib.h>

#include "game.h"

void showLink(t_event * p_event, t_game *p_game);
void linkLeftDirection(t_game *p_game);
void linkRightDirection(t_game *p_game);
void linkDownDirection(t_game *p_game);
void linkUpstair(t_game *p_game);
void linkAttack(t_event *p_event, t_game *p_game);
void linkReturnInitialPosition(t_event *p_event, t_game *p_game);
void dead_link(t_game *p_game, t_event *p_event);
void linkNothingItem(t_game *p_game);
void linkTomahawkItem(t_game *p_game);
void linkMapItem(t_game *p_game);
void linkHeartItem(t_game *p_game);
void linkWOLItem(t_game *p_game);

#endif
