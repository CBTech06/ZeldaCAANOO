/*************** Game & watch  Zelda **********************/
/*                  By NINTENDO                          */
/*         Coding for CAANOO by Captainchris PRD        */
/*                                                     */
/*******************************************************/

#ifndef MUSIC_H
#define MUSIC_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <stdlib.h>

Mix_Music *skeleton;
Mix_Music *monster;
Mix_Music *link;
Mix_Music *gameover;
Mix_Music *mstdead;
Mix_Music *score;

void playMUSkeletonAttack();
void playMUSMonsterAttack();
void playMUSLinkAttack();
void playMUSGameOver();
void playMUSMonsterDead();



#endif
