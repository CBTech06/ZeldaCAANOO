/*************** Game & watch  Zelda **********************/
/*                  By NINTENDO                          */
/*         Coding for CAANOO by Captainchris PRD        */
/*                                                     */
/*******************************************************/

#ifndef ENEMY_H
#define ENEMY_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <stdlib.h>

#include "event.h"
#include "game.h"

void monsterFunc(int monsterTimer, t_event * p_event, t_game * p_game);
void enemyEnergyUpdate(t_game *p_game);
void monsterPosition(t_game *p_game, t_event * p_event);
void deadMonster(t_game *p_game);
void monsterThrowArrow(int arrowTimer, t_game *p_game,t_event *p_event);
void arrowToFirstPosition(t_game *p_game, t_event *p_event);
void arrowToSecondPosition(t_game *p_game, t_event *p_event);
void arrowToThirdPosition(t_game *p_game, t_event *p_event);
void arrowToFourthPosition(t_game *p_game, t_event *p_event);

void ghiniFunc(int ghiniTimer,t_game *p_game);
void ghiniChangePosition(t_game *p_game);
void ghiniThrowArrow(int ghiniArrowTimer,t_game *p_game, t_event *p_event);
void ghiniArrowToFourthPosition(t_game *p_game,t_event *p_event);
void ghiniArrowToThirdPosition(t_game *p_game, t_event *p_event);
void ghiniArrowToSecondPosition(t_game *p_game,t_event *p_event);
void ghiniArrowToFirstPosition(t_game *p_game,t_event *p_event);

#endif
