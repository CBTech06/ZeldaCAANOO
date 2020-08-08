
/*************** Game & watch  Zelda **********************/
/*                  By NINTENDO                          */
/*         Coding for CAANOO by Captainchris PRD        */
/*                                                     */
/*******************************************************/

#ifndef SKELETON_H
#define SKELETON_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <stdlib.h>

#include "event.h"
#include "game.h"

void skeleton_Func(int skeletonTimer, t_game *p_game,t_event *p_event);
void skeletonAttack(t_game *p_game, t_event *p_event);
void addSkeleton(int skTimer,t_game *p_game,t_event *p_event);
void skAttackAtFirstPosition(t_game *p_game,t_event *p_event);
void skAttackAtSecondPosition(t_game *p_game,t_event *p_event);
void skAttackAtThirdPosition(t_game *p_game,t_event *p_event);
void skAttackAtFourthPosition(t_game *p_game, t_event *p_event);
void moveFirstSkeleton(int skTimer,t_game *p_game);
void moveSecondSkeleton(int skTimer,t_game *p_game, t_event *p_event);
void moveFourthSkeleton(int skTimer,t_game *p_game,t_event *p_event);
void skLoad(t_game *p_game,t_event *p_event);
void moveThirdSkeleton(int skTimer,t_game *p_game,t_event *p_event);

#endif
