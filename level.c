
/*************** Game & watch  Zelda **********************/
/*                  By NINTENDO                          */
/*         Coding for CAANOO by Captainchris PRD        */
/*                                                     */
/*******************************************************/


#include "level.h"

void levelInformation(t_game *p_game)
{
  if(p_game->level == 1) {
    switch (p_game->p_level->room)
      {
      case 1:
	p_game->p_skeleton->number = 1;
	p_game->reward = HEART;
	if(p_game->p_ganon->dead == 1){ p_game->stair = ALL_STAIRS; }
	break;
	
      case 2:
	p_game->p_skeleton->number = 2;
	p_game->reward = TOMAHAWK;
	if(p_game->p_ganon->dead == 1){	p_game->stair = LEFT_STAIRS; }
	break;
	
      case 3:
	p_game->p_skeleton->number = 2;
	p_game->p_ghini->status = ON;
	p_game->reward = MAP;
	if(p_game->p_ganon->dead == 1){	p_game->stair = LEFT_STAIRS; }
	break;
	
      case 4:
	p_game->p_skeleton->number = 2;
	p_game->reward = WATER_OF_LIFE;
	if(p_game->p_ganon->dead == 1){	p_game->stair = MIDDLE_STAIRS; }
	break;
      
      }
  }

}

void changeRoom(t_game *p_game)
{
  if(p_game->level == 1) {
    switch(p_game->p_level->room) {
    case 1:
      if(p_game->p_link->roomDirection == LEFT_DIRECTION) { p_game->p_level->room = 3; }
      if(p_game->p_link->roomDirection == RIGHT_DIRECTION) { p_game->p_level->room = 2; }
      break;

    case 2:
      if(p_game->p_link->roomDirection == LEFT_DIRECTION) { p_game->p_level->room = 3; }
      break;

    case 3:
     if(p_game->p_link->roomDirection == LEFT_DIRECTION) { p_game->p_level->room = 4; }
     break;

  
    }
  }	
   
}
