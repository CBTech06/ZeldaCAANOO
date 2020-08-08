/*************** Game & watch  Zelda **********************/
/*                  By NINTENDO                          */
/*         Coding for CAANOO by Captainchris PRD        */
/*                                                     */
/*******************************************************/

#include "game.h"

void startGameW(t_event *p_event,t_game * p_game)
{
  if (p_game->isLoaded == 0) {
    drawSurface(p_game->background, 0, 0, 0, 0, 320, 240);
    drawSurface(p_game->spritesheet, 268, 78, 200, 153, 42, 52);	/* Show Monster */
    drawSurface(p_game->spritesheet, 180, 150, 0, 550, 65, 48);	/* Show Skeleton */
    showDetails(p_game);
    p_game->isLoaded = 1;
    p_game->stair = 0;
  }

  if (p_game->p_link->life != 0) { showLink(p_event, p_game);}
  scoreUpdate(p_game);
}


void showScore(int scoreTimer,t_game *p_game)
{
  p_game->p_link->scoreTicks += scoreTimer;
  
  //scoreUpdate(p_game);
  drawSurface(p_game->spritesheet, 180, 225, 26, 710, 28, 8);

 
  p_game->p_link->score++;
  p_game->p_link->counter++;
  sprintf(p_game->buffer,"%d", p_game->p_link->score);
  p_game->scoreTxt = TTF_RenderText_Solid(p_game->digitalFont, p_game->buffer,
					     p_game->scoreColor);

  
  drawSurface(p_game->background, 275, 210, 275, 210, 44,29);  
  SDL_BlitSurface(p_game->scoreTxt, NULL, SDL_GetVideoSurface(),
		  &p_game->p_link->scoreDst);
    
  playMUSScore();
     
  if(p_game->p_link->counter >= 40){ p_game->printScore = 1; }
 
}

void scoreUpdate(t_game *p_game)
{
   sprintf(p_game->buffer,"%d", p_game->p_ganon->score);
   p_game->scoreTxt = TTF_RenderText_Solid(p_game->digitalFont, p_game->buffer,
					     p_game->scoreColor);
  
  
  SDL_BlitSurface(p_game->scoreTxt, NULL, SDL_GetVideoSurface(),
		  &p_game->p_link->scoreDst);
}

void showItem(t_game *p_game)
{
  if(p_game->p_link->tomahawk == 1) {
    drawSurface(p_game->spritesheet,103, 83, 484, 7, 35, 36); }
  
  if(p_game->p_link->map == 1) {
    drawSurface(p_game->spritesheet,101, 140, 483, 63, 35, 36); }
  
  if (p_game->p_link->WOL == 1) {
    drawSurface(p_game->spritesheet,100, 195, 485, 112, 35, 36); }

}


void updateScore(t_game *p_game)
{
  if (p_game->p_ganon->score != 0 && p_game->p_link->attack != 1) {
    p_game->p_ganon->score -= 1;
    drawSurface(p_game->background, 275, 210, 275, 195, 60, 30);
    p_game->p_link->attack = 1;
  }
  if (p_game->p_ganon->score == 0 && p_game->p_ganon->dead != 1) {

    deadMonster(p_game);
    p_game->p_ganon->dead = 1;
  }

}

void showDetails(t_game *p_game)
{
  /* Show Heart */
  int lifeLoop;
  if(p_game->unPaused == 1) {  p_game->p_link->lifeDest = 70; }
  for (lifeLoop = 0; lifeLoop < p_game->p_link->life; lifeLoop++) {
    drawSurface(p_game->spritesheet, p_game->p_link->lifeDest,
		216, 575, 14, 17, 17);
    p_game->p_link->lifeDest += 18; 
  }

  drawSurface(p_game->spritesheet, 180, 225, 48, 831, 73, 7);
    
}

void addHeart(int heart, t_game * p_game)
{
  int heartValue;

  for (heartValue = 0; heartValue < heart; heartValue++) {
    drawSurface(p_game->spritesheet, p_game->p_link->lifeDest,
		216, 575, 15, 17, 16);
    p_game->p_link->lifeDest += 18;
  }

}

void remove_heart(t_game *p_game, t_event *p_event)
{

  switch (p_game->p_link->life) {
  case 0:
    drawSurface(p_game->background, 68, 216, 119, 216, 20, 20);
    p_event->attack = 0;
    dead_link(p_game, p_event);
    p_game->p_link->lifeDest -= 18;
    break;

  case 1:
    drawSurface(p_game->background, 88, 216, 119, 216, 20, 20);
    p_event->attack = 0;
    p_game->p_link->lifeDest -= 18;
    break;

  case 2:
    drawSurface(p_game->background, 107, 216, 119, 216, 20, 20);
    p_event->attack = 0;
    p_game->p_link->lifeDest -= 18;
    break;

  case 3:
    drawSurface(p_game->background, 125, 216, 119, 216, 20, 20);
    p_event->attack = 0;
    p_game->p_link->lifeDest -= 18;
    break;
  case 4:
    drawSurface(p_game->background, 142, 216, 119, 216, 20, 20);
    p_event->attack = 0;
    p_game->p_link->lifeDest -= 18;
    break;

  }
}

void drawStairs(t_game *p_game)
{
  levelInformation(p_game);
  if(p_game->stair != NO_STAIRS) {
       if(p_game->stair == LEFT_STAIRS || p_game->stair == ALL_STAIRS) { drawSurface(p_game->spritesheet, 15, 45, 80, 121, 46, 24); }
       
       if(p_game->stair == RIGHT_STAIRS || p_game->stair == ALL_STAIRS) { drawSurface(p_game->spritesheet, 210, 45, 136, 121, 46, 24); }

       if(p_game->stair == MIDDLE_STAIRS) { drawSurface(p_game->spritesheet, 100, 5, 544, 120, 47, 70); }
       
       }
}

void resetGame(t_game *p_game)
{
  SDL_FreeSurface(p_game->scoreTxt);
  p_game->isLoaded = 0;
  p_game->printScore = 0;
  p_game->stair = 0;
  p_game->finish = 0;
  p_game->level = 1;
  p_game->p_level->room = 1;
  p_game->isPaused = 0;
  p_game->unPaused = 0;
  p_game->p_link->dst.x = 90;
  p_game->p_link->dst.w = 30;
  p_game->p_link->lifeDest = 70;
  p_game->p_link->initialPosition = 0;
  p_game->p_link->source = 0;
  p_game->p_link->destination = 0;
  p_game->p_link->collision = 0;
  p_game->p_link->attack = 0;
  p_game->p_link->counter = 0;
  p_game->p_link->score = 0;

  p_game->p_ganon->dst.x = 0;
  p_game->p_ganon->dst.y = 0;
  p_game->p_ganon->attack = 0;
  p_game->p_ganon->score = 40;
  p_game->p_ganon->throw = 0;
  p_game->p_ganon->arrowPosition = 0;
  p_game->p_ganon->arrowTicks = 0;
  p_game->p_ganon->arrowCollision = 0;
  p_game->p_ganon->dead = 0;
  p_game->p_ganon->isMonsterDead = 0;
  p_game->p_ganon->monsterIndex = 0;
  p_game->p_ganon->ticks = 0;
  p_game->p_ganon->Xposition = 290;
  
  p_game->p_skeleton->position = 0;
  p_game->p_skeleton->ticks = 0;
  p_game->p_skeleton->attack = 0;
  p_game->p_skeleton->attackIndex = 0;
  p_game->p_skeleton->block = 0;
  p_game->p_skeleton->initialized = 0;

  p_game->p_ghini->position = 0;
  p_game->p_ghini->ticks = 0;
  p_game->p_ghini->throw = 0;
  p_game->p_ghini->arrowTicks = 0;
  p_game->p_ghini->arrowPosition = 0;

}

int detectCollision(SDL_Rect link, SDL_Rect ennemy, t_event *p_event)
{
  int left_link, left_ennemy;
  int right_link, right_ennemy;
  int bottom_link, bottom_ennemy;
  int top_link, top_ennemy;

  left_link = link.x;
  right_link = link.x + link.w;
  top_link = link.y;
  bottom_link = link.y + link.h;

  left_ennemy = ennemy.x;
  right_ennemy = ennemy.x + ennemy.w;
  top_ennemy = ennemy.y;
  bottom_ennemy = ennemy.y + ennemy.h;

  /* only if link is at the fourth position +  attack */
  if (right_link == 216 && p_event->buttons[1]) {
    right_link += 57;
  }
  
  /* Return Collision */
  if (right_link >= left_ennemy) {
    if (p_event->buttons[1]) {
      return 1;
    }
  } else {
    return 0;
  }
}
