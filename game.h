/*************** Game & watch  Zelda **********************/ 
/*                  By NINTENDO                          */ 
/*         Coding for CAANOO by Captainchris PRD        */ 
/*                                                     */ 
/*******************************************************/ 
    
#ifndef GAME_H
#define GAME_H
    
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <stdlib.h>
    
#include "event.h"
#include "main.h"

#define LEFT_DIRECTION 1
#define RIGHT_DIRECTION 2
enum { NOTHING, HEART, TOMAHAWK, WATER_OF_LIFE,MAP};
enum {  NO_STAIRS, LEFT_STAIRS, MIDDLE_STAIRS, RIGHT_STAIRS, ALL_STAIRS};
enum { OFF, ON};


typedef struct {
    int lifeDest;
    int life;
    int tomahawk;
    int map;
    int WOL;
    int source;
    int destination;
    int collision;
    int initialPosition;
    int attack;
    int score;
    int counter;
    int roomDirection;
    SDL_Rect scoreDst;
    SDL_Rect dst;
    int scoreTicks;
}t_link;

typedef struct {
  int room;
  int reward;
}t_level;

typedef struct {
    int initialPosition;
    int throw;
    int arrowPosition;
    SDL_Rect arrowDest;
    int arrowCollision;
    int arrowTicks;
    int score;
    int monsterIndex;
    int isMonsterDead;
    int dead;
    int attack;
    int monsterAttack;
    int ticks;
    int Xposition;
    SDL_Rect scoreDst;
    SDL_Rect dst;
}t_ganon;

typedef struct {
    int position;
    int ticks;
    int attack;
    int attackIndex;
    int block;
    int number;
    int eraser;
  int initialized;
}t_skeleton;

typedef struct {
  int status;
  int position;
  int arrowPosition;
  int ticks;
  int throw;
  int ifthrow;
  int arrowTicks;
  SDL_Rect arrowDest;
  int arrowCollision;
}t_ghini;

typedef struct {
    SDL_Surface *background, *spritesheet, *screen2, *scoreTxt;
    int isLoaded;
    int gcpIsLoaded;
    int isPaused;
    int unPaused;
    t_link * p_link;
    t_ganon * p_ganon;
    t_skeleton * p_skeleton;
    t_ghini   *p_ghini;
    t_level *p_level;
    TTF_Font * digitalFont;
    SDL_Color scoreColor;
    char buffer[20];
    int level;
    int stair;
    int finish;
  int reward;
    int printScore;
}t_game;

void startGameW(t_event *p_event,t_game *p_game);
void showScore(int scoreTimer,t_game *p_game);
void scoreUpdate(t_game *p_game);
void showItem(t_game *p_game);
void showDetails(t_game *p_game);
void addHeart(int heart, t_game *p_game);
void remove_heart(t_game *p_game, t_event *p_event);
void drawStairs(t_game *p_game);
void resetGame(t_game *p_game);
int detect_collision(SDL_Rect link, SDL_Rect ennemy, t_event *p_event);
void updateScore(t_game *p_game);

#endif	
