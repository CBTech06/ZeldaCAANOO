/*************** Game & watch  Zelda **********************/
/*                  By NINTENDO                          */
/*         Coding for CAANOO by Captainchris PRD        */
/*                                                     */
/*******************************************************/

#include "enemy.h"


void monsterFunc(int monsterTimer, t_event *p_event, t_game *p_game)
{
  //enemyEnergyUpdate(p_game);
    
 
  
  p_game->p_ganon->attack = 0;
  
  p_game->p_ganon->ticks += monsterTimer;
  if (p_game->p_ganon->ticks >= 1000) {
    p_game->p_ganon->ticks -= 800;	/* Change value to add velocity to monster */
    p_game->p_ganon->monsterIndex++;
    monsterPosition(p_game, p_event);
    
    if (p_game->p_ganon->isMonsterDead == 0) {}
  }
  
  p_game->p_link->collision =
    detectCollision(p_game->p_link->dst, p_game->p_ganon->dst,
		    p_event);
  if (p_game->p_link->collision == 1) {
    updateScore(p_game);
    
  }
}

void enemyEnergyUpdate(t_game *p_game)
{
 

  sprintf(p_game->buffer, "%d", p_game->p_ganon->score);
  p_game->scoreTxt = TTF_RenderText_Solid(p_game->digitalFont, p_game->buffer, p_game->scoreColor); 
  
  if(p_game->scoreTxt) {
      
    SDL_BlitSurface(p_game->scoreTxt, NULL, SDL_GetVideoSurface(),
		    &p_game->p_ganon->scoreDst);
    //  SDL_FreeSurface(p_game->scoreTxt);
  }
  
  
}

void monsterPosition(t_game *p_game, t_event * p_event)
{
  int level[100] = { 1, 1, 2, 3, 4, 3, 4, 3, 4, 5, 2,
		     1, 2, 3, 4, 3, 4, 3, 4, 5, 4, 3,
		     4, 5, 3, 2, 1, 2, 3, 2, 3, 4, 3,
		     2, 1, 2, 3, 4, 5, 4, 1, 2, 1, 2,
		     3, 2, 1, 2, 3, 2, 3, 4, 5, 3, 4,
		     3, 4, 3, 5, 3, 4, 3, 2, 1, 2, 3,
		     4, 3, 2, 4, 3, 2, 1, 2, 3, 4, 3,
		     4, 5, 4, 3, 4, 5, 4, 3, 2, 1, 2,
		     3, 4, 3, 2, 1, 2, 3, 4, 5, 3, 4, 5
  };

  if (p_game->p_ganon->dead != 1) {
    switch (level[p_game->p_ganon->monsterIndex]) {
    case 1:
      drawSurface(p_game->background, 230, 75, 230, 75, 95, 60);	/* Clear monster */
      drawSurface(p_game->spritesheet, 270, 78, 200, 153, 42, 52);	/* Show Monster */
      p_game->p_ganon->Xposition = p_game->p_ganon->dst.x = 290;

      break;

    case 2:
      drawSurface(p_game->background, 230, 75, 230, 75, 95, 60);
      drawSurface(p_game->spritesheet, 270, 78, 150, 155, 42, 52);
      p_game->p_ganon->Xposition = p_game->p_ganon->dst.x = 290;
      break;

    case 3:
      drawSurface(p_game->background, 230, 75, 230, 75, 95, 60);
      drawSurface(p_game->spritesheet, 240, 78, 106, 153, 38, 53);
      p_game->p_ganon->Xposition = p_game->p_ganon->dst.x = 270;
      break;

    case 4:
      drawSurface(p_game->background, 230, 75, 230, 75, 95, 60);
      drawSurface(p_game->spritesheet, 230, 78, 54, 153, 50, 53);
      p_game->p_ganon->Xposition = p_game->p_ganon->dst.x = 270;
      playMUSMonsterAttack();

      p_game->p_link->collision =
	detectCollision(p_game->p_link->dst,
			p_game->p_ganon->dst, p_event);

      if (p_game->p_link->collision == 1) {
	updateScore(p_game);
	p_game->p_link->attack = 1;

	if (p_game->p_link->life >= 0
	    && p_game->p_ganon->attack != 1) {
	  p_game->p_link->life -= 1;
	  remove_heart(p_game, p_event);
	  p_game->p_ganon->attack = 1;

	}
      }
      break;

    case 5:
      drawSurface(p_game->background, 230, 75, 230, 75, 95, 60);	/* clear monster */
      drawSurface(p_game->spritesheet, 230, 78, 2, 153, 50, 53);
      p_game->p_ganon->Xposition = p_game->p_ganon->dst.x = 270;
      playMUSMonsterAttack();

      p_game->p_link->collision =
	detectCollision(p_game->p_link->dst,
			p_game->p_ganon->dst, p_event);

      if (p_game->p_link->collision == 1) {
	updateScore(p_game);
      }
      p_game->p_ganon->throw = 1;
      break;

    }
  }
}

void deadMonster(t_game *p_game)
{
  
  
    
  drawSurface(p_game->background, 224, 103, 220, 103, 40, 33);	/* Clear Monster */
  drawSurface(p_game->background, 228, 75, 230, 75, 95, 60);	/* And Arrow */
  drawSurface(p_game->background, 30, 135, 30, 135, 225, 68);	/* clear Skeleton */

  switch (p_game->reward) {
  case NOTHING:
    drawSurface(p_game->spritesheet, 270, 78, 6, 215, 48, 45);
    drawSurface(p_game->background,   0, 75, 0, 75, 44, 118);
    SDL_Delay(1000);
    drawSurface(p_game->background, 253, 73, 253, 73, 67, 50);	/* Clear Monster */
    drawSurface(p_game->spritesheet, 270, 134, 124, 227, 49, 40);
    drawSurface(p_game->background, 180, 225, 180, 225, 74, 9);	/* Remove energy Monster */
    playMUSMonsterDead();
	
    linkNothingItem(p_game);
    break;

  case HEART:
    drawSurface(p_game->spritesheet, 270, 72, 62, 209, 48, 59);
    drawSurface(p_game->spritesheet, 270, 20, 575, 15, 17, 16);
    drawSurface(p_game->background,   0, 75, 0, 75, 44, 118);
    SDL_Delay(1000);
    drawSurface(p_game->background, 262, 4, 262, 4, 56, 128);
    drawSurface(p_game->spritesheet, 267, 136, 124, 227, 49, 40);
    drawSurface(p_game->background, 180, 225, 180, 225, 74, 9);	/* Remove energy Monster */
    playMUSMonsterDead();

    linkHeartItem(p_game);
    break;

  case TOMAHAWK:
    drawSurface(p_game->spritesheet, 270, 72, 62, 209, 48, 59);
    drawSurface(p_game->spritesheet, 270, 20, 533, 61, 22, 27);	/* Tomahawk */
    drawSurface(p_game->background,   0, 75, 0, 75, 44, 118);
    SDL_Delay(1000);
    drawSurface(p_game->background, 262, 4, 262, 4, 56, 128);
    drawSurface(p_game->spritesheet, 267, 136, 124, 227, 49, 40);
    drawSurface(p_game->background, 180, 225, 180, 225, 74, 9);	/* Remove energy Monster */
    playMUSMonsterDead();

    linkTomahawkItem(p_game);
    break;

  case WATER_OF_LIFE:
    drawSurface(p_game->spritesheet, 270, 72, 62, 209, 48, 59);
    drawSurface(p_game->spritesheet, 270, 20, 533, 36, 21, 20);	/* Water of life  */
    drawSurface(p_game->background,   0, 75, 0, 75, 44, 118);
    SDL_Delay(1000);
    drawSurface(p_game->background, 262, 4, 262, 4, 56, 128);
    drawSurface(p_game->spritesheet, 267, 136, 124, 227, 49, 40);
    drawSurface(p_game->background, 180, 225, 180, 225, 74, 9);	/* Remove energy Monster */
    playMUSMonsterDead();

    linkWOLItem(p_game);
    break;

  case MAP:
    drawSurface(p_game->spritesheet, 270, 72, 62, 209, 48, 59);
    drawSurface(p_game->spritesheet, 270, 20, 533, 8, 25, 24);	/* Map */
    SDL_Delay(1000);
    drawSurface(p_game->background, 262, 4, 262, 4, 56, 128);
    drawSurface(p_game->spritesheet, 267, 136, 124, 227, 49, 40);
    drawSurface(p_game->background, 180, 225, 180, 225, 74, 9);	/* Remove energy Monster */
    playMUSMonsterDead();

    linkMapItem(p_game);
    break;
  }




}

void monsterThrowArrow(int arrowTimer, t_game *p_game,
		       t_event *p_event)
{
  
  p_game->p_ganon->arrowTicks += arrowTimer;

  if (p_game->p_link->dst.x != 186
      && p_game->p_ganon->arrowPosition < 1) {
    drawSurface(p_game->spritesheet, 188, 100, 572, 53, 16, 9);
  }
    
  if (p_game->p_ganon->arrowTicks >= 900) {
    p_game->p_ganon->arrowPosition++;
    p_game->p_ganon->arrowTicks -= 300;
	

    if (p_game->p_link->dst.x == 42) {
      arrowToFourthPosition(p_game, p_event);
    }
    if (p_game->p_link->dst.x == 90) {
      arrowToThirdPosition(p_game, p_event);
    }
    if (p_game->p_link->dst.x == 138) {
      arrowToSecondPosition(p_game, p_event);
    }
    if (p_game->p_link->dst.x == 186) {
      arrowToFirstPosition(p_game, p_event);
    }
  }
}

void arrowToFirstPosition(t_game *p_game, t_event *p_event)
{
  switch (p_game->p_ganon->arrowPosition) {
  case 1:
    p_game->p_ganon->arrowDest.x = 186;

    p_game->p_ganon->arrowCollision =
      detectCollision(p_game->p_link->dst,
		      p_game->p_ganon->arrowDest, p_event);

    if (p_game->p_ganon->arrowCollision == 1) {
      p_game->p_link->life -= 1;
      remove_heart(p_game, p_event);
    } else {
      drawSurface(p_game->spritesheet, 218, 130, 578, 36, 12, 13);
    }
    p_game->p_ganon->arrowPosition = 0;
    p_game->p_ganon->throw = 0;
    break;
  }
}

void arrowToSecondPosition(t_game * p_game, t_event *p_event)
{
  switch (p_game->p_ganon->arrowPosition) {
  case 1:
    p_game->p_ganon->arrowDest.x = 186;	/* Collision with arrow */

    p_game->p_ganon->arrowCollision =
      detectCollision(p_game->p_link->dst,
		      p_game->p_ganon->arrowDest, p_event);
    if (p_game->p_ganon->arrowCollision == 1) {
      p_game->p_link->life -= 1;
      remove_heart(p_game, p_event);
    }
    break;

  case 2:
    drawSurface(p_game->background, 188, 100, 188, 100, 40, 30);	/* Clear arrow */
    p_game->p_ganon->arrowDest.x = 138;

    p_game->p_ganon->arrowCollision =
      detectCollision(p_game->p_link->dst,
		      p_game->p_ganon->arrowDest, p_event);

    if (p_game->p_ganon->arrowCollision == 1) {
      p_game->p_link->life -= 1;
      remove_heart(p_game, p_event);
    } else {
      drawSurface(p_game->spritesheet, 168, 130, 575, 71, 14, 12);
    }
    p_game->p_ganon->arrowPosition = 0;
    p_game->p_ganon->throw = 0;
    break;
  }

}

void arrowToThirdPosition(t_game *p_game, t_event *p_event)
{
  switch (p_game->p_ganon->arrowPosition) {
  case 1:
    p_game->p_ganon->arrowDest.x = 186;	/* Collision with arrow */

    p_game->p_ganon->arrowCollision =
      detectCollision(p_game->p_link->dst,
		      p_game->p_ganon->arrowDest, p_event);
    if (p_game->p_ganon->arrowCollision == 1) {
      p_game->p_link->life -= 1;
      remove_heart(p_game, p_event);
    }
    break;

  case 2:
    drawSurface(p_game->background, 188, 100, 188, 100, 40, 30);	/* Clear arrow */
    drawSurface(p_game->spritesheet, 138, 100, 574, 55, 16, 9);
    p_game->p_ganon->arrowDest.x = 138;

    p_game->p_ganon->arrowCollision =
      detectCollision(p_game->p_link->dst,
		      p_game->p_ganon->arrowDest, p_event);

    if (p_game->p_ganon->arrowCollision == 1) {
      p_game->p_link->life -= 1;
      remove_heart(p_game, p_event);

    }
    break;

  case 3:
    drawSurface(p_game->background, 138, 100, 138, 100, 40, 30);	/* Clear arrow */
    p_game->p_ganon->arrowDest.x = 90;

    p_game->p_ganon->arrowCollision =
      detectCollision(p_game->p_link->dst,
		      p_game->p_ganon->arrowDest, p_event);

    if (p_game->p_ganon->arrowCollision == 1) {
      p_game->p_link->life -= 1;
      remove_heart(p_game, p_event);
    } else {
      drawSurface(p_game->spritesheet, 120, 130, 577, 36, 12, 11);
    }
    p_game->p_ganon->arrowPosition = 0;
    p_game->p_ganon->throw = 0;
    break;
  }
}

void arrowToFourthPosition(t_game *p_game, t_event * p_event)
{
  switch (p_game->p_ganon->arrowPosition) {
  case 1:
    p_game->p_ganon->arrowDest.x = 186;	/* Collision with arrow */

    p_game->p_ganon->arrowCollision =
      detectCollision(p_game->p_link->dst,
		      p_game->p_ganon->arrowDest, p_event);
    if (p_game->p_ganon->arrowCollision == 1) {
      p_game->p_link->life -= 1;
      remove_heart(p_game, p_event);
    }
    break;

  case 2:
    drawSurface(p_game->background, 188, 100, 188, 100, 40, 30);	/* Clear arrow */
    drawSurface(p_game->spritesheet, 138, 100, 572, 53, 16, 9);
    p_game->p_ganon->arrowDest.x = 138;

    p_game->p_ganon->arrowCollision =
      detectCollision(p_game->p_link->dst,
		      p_game->p_ganon->arrowDest, p_event);

    if (p_game->p_ganon->arrowCollision == 1) {
      p_game->p_link->life -= 1;
      remove_heart(p_game, p_event);
    }
    break;

  case 3:
    drawSurface(p_game->background, 138, 100, 138, 100, 40, 30);	/* Clear arrow */
    drawSurface(p_game->spritesheet, 90, 100, 572, 53, 16, 9);
    p_game->p_ganon->arrowDest.x = 90;

    p_game->p_ganon->arrowCollision =
      detectCollision(p_game->p_link->dst,
		      p_game->p_ganon->arrowDest, p_event);

    if (p_game->p_ganon->arrowCollision == 1) {
      p_game->p_link->life -= 1;
      remove_heart(p_game, p_event);
    }
    break;

  case 4:
    drawSurface(p_game->background, 90, 100, 90, 100, 40, 30);	/* Clear arrow */
    p_game->p_ganon->arrowDest.x = 42;

    p_game->p_ganon->arrowCollision =
      detectCollision(p_game->p_link->dst,
		      p_game->p_ganon->arrowDest, p_event);

    if (p_game->p_ganon->arrowCollision == 1) {
      p_game->p_link->life -= 1;
      remove_heart(p_game, p_event);
    } else {
      drawSurface(p_game->spritesheet, 83, 130, 575, 73, 14, 9);
    }
    p_game->p_ganon->arrowPosition = 0;
    p_game->p_ganon->throw = 0;
    break;



  }
}


void ghiniFunc(int ghiniTimer,t_game *p_game)
{
 
  p_game->p_ghini->ticks += ghiniTimer;
  
  if(p_game->p_ghini->position == 0) { 
    drawSurface(p_game->spritesheet,3,150,288,119,32,36);
  }
  
  if (p_game->p_ghini->ticks >= 2000) {
  p_game->p_ghini->ticks -= 1500;	/* Change value to add velocity to monster */
    
    p_game->p_ghini->position++;
    
    ghiniChangePosition(p_game);
  }
  
}

void ghiniChangePosition(t_game *p_game)
{
  
  
         
 
  switch(p_game->p_ghini->position)
    {
    case 0:
      
      drawSurface(p_game->spritesheet,3,150,288,119,32,36);
      break;
      
    case 1:
      drawSurface(p_game->background,3,150,3,150,32,36);
      drawSurface(p_game->spritesheet,3,114,330,119,32,36);
      break;
      
    case 2: 
       p_game->p_ghini->ifthrow = rand() % 2;
      
      drawSurface(p_game->background,3,114,3,114,32,36);
      if(p_game->p_ghini->ifthrow == 0) {drawSurface(p_game->spritesheet,3,85,437,119,26,38); }
      if(p_game->p_ghini->ifthrow == 1) { drawSurface(p_game->spritesheet,3,85,382,117,37,42);}
      break;
    
    case 3:
      if(p_game->p_ghini->ifthrow == 1) { p_game->p_ghini->throw = 1; }
      drawSurface(p_game->background,3,85,3,82,37,42);
      p_game->p_ghini->position = 0;
      break;
    }

}

void ghiniThrowArrow(int ghiniArrowTimer,t_game *p_game,t_event *p_event)
{
  p_game->p_ghini->arrowTicks += ghiniArrowTimer;
   
  

  if (p_game->p_ghini->arrowTicks >= 700) {
    p_game->p_ghini->arrowPosition++;
    p_game->p_ghini->arrowTicks -= 300;	/* Change value to add velocity to monster */
   	
    if (p_game->p_link->dst.x == 42) {
      ghiniArrowToFourthPosition (p_game,p_event);
    }
    if (p_game->p_link->dst.x == 90) {
      ghiniArrowToThirdPosition(p_game, p_event);
    }
    if (p_game->p_link->dst.x == 138) {
      ghiniArrowToSecondPosition(p_game, p_event);
    }
    if (p_game->p_link->dst.x == 186) {
      ghiniArrowToFirstPosition(p_game, p_event);
    }
  }
}

void ghiniArrowToFourthPosition(t_game *p_game,t_event *p_event)
{
  switch(p_game->p_ghini->arrowPosition) {
  case 1:
    p_game->p_ghini->arrowDest.x = 42;

    p_game->p_ghini->arrowCollision = detectCollision(p_game->p_link->dst,
						      p_game->p_ghini->arrowDest, p_event);

    if (p_game->p_ghini->arrowCollision == 0) {
      p_game->p_link->life -= 1;
      remove_heart(p_game, p_event);
    } else {
      drawSurface(p_game->spritesheet, 35, 130, 578, 104, 13, 8);
    }
    p_game->p_ghini->arrowPosition = 0;
    p_game->p_ghini->throw = 0;
    break;
	
  }
}

void ghiniArrowToThirdPosition(t_game *p_game, t_event *p_event)
{
   
  switch (p_game->p_ghini->arrowPosition) {
  case 1:
     
    drawSurface(p_game->spritesheet, 48, 100, 576, 89, 18, 9);
    p_game->p_ghini->arrowDest.x = 48;
    p_game->p_ghini->arrowCollision =
      detectCollision(p_game->p_link->dst,
		      p_game->p_ghini->arrowDest, p_event);
    break;

  case 2:
    drawSurface(p_game->background,48, 100, 90, 100, 17, 9);
    p_game->p_ghini->arrowDest.x = 90;

    p_game->p_ghini->arrowCollision = detectCollision(p_game->p_link->dst,
						      p_game->p_ghini->arrowDest, p_event);

    if (p_game->p_ghini->arrowCollision == 0) {
      p_game->p_link->life -= 1;
      remove_heart(p_game, p_event);
    } else {
      drawSurface(p_game->spritesheet, 75, 130, 578, 103, 13, 9);
    }
    p_game->p_ghini->arrowPosition = 0;
    p_game->p_ghini->throw = 0;
    break;
	
  }
}

void ghiniArrowToSecondPosition(t_game *p_game,t_event *p_event)
{
  switch (p_game->p_ghini->arrowPosition) {
  case 1:
    drawSurface(p_game->spritesheet, 48, 100, 576, 89, 18, 9);
    p_game->p_ghini->arrowDest.x = 48;
    p_game->p_ghini->arrowCollision =
      detectCollision(p_game->p_link->dst,
		      p_game->p_ghini->arrowDest, p_event);

	
    break;
	
  case 2:
    drawSurface(p_game->background, 48, 100, 48, 100, 17, 9);
    drawSurface(p_game->spritesheet, 90, 100, 576, 89, 18, 9);
    p_game->p_ghini->arrowDest.x = 90;
    p_game->p_ghini->arrowCollision =
      detectCollision(p_game->p_link->dst,
		      p_game->p_ghini->arrowDest, p_event);
	
    break;
   

  case 3:
    drawSurface(p_game->background,90, 100, 90, 100, 17, 9);
    p_game->p_ghini->arrowDest.x = 138;

    p_game->p_ghini->arrowCollision = detectCollision(p_game->p_link->dst,
						      p_game->p_ghini->arrowDest, p_event);

    if (p_game->p_ghini->arrowCollision == 0) {
      p_game->p_link->life -= 1;
      remove_heart(p_game, p_event);
    } else {
      drawSurface(p_game->spritesheet, 120, 130, 575, 34, 12, 13);
    }
    p_game->p_ghini->arrowPosition = 0;
    p_game->p_ghini->throw = 0;
    break;
  }
}

void  ghiniArrowToFirstPosition(t_game *p_game,t_event *p_event)
{
  switch (p_game->p_ghini->arrowPosition) {
  case 1:
    drawSurface(p_game->spritesheet, 48, 100, 576, 89, 18, 9);
    p_game->p_ghini->arrowDest.x = 48;
    p_game->p_ghini->arrowCollision =
      detectCollision(p_game->p_link->dst,
		      p_game->p_ghini->arrowDest, p_event);

    break;
	
  case 2:
    drawSurface(p_game->background, 48, 100, 48, 100, 17, 9);
    drawSurface(p_game->spritesheet, 90, 100, 576, 89, 18, 9);
    p_game->p_ghini->arrowDest.x = 90;
    p_game->p_ghini->arrowCollision =
      detectCollision(p_game->p_link->dst,
		      p_game->p_ghini->arrowDest, p_event);
	
    break;
  
  case 3:
    drawSurface(p_game->background,90, 100, 90, 100, 17, 9);
    drawSurface(p_game->spritesheet, 138, 100, 576, 89, 17, 9);
    p_game->p_ghini->arrowDest.x = 138;
    p_game->p_ghini->arrowCollision =
      detectCollision(p_game->p_link->dst,
		      p_game->p_ghini->arrowDest, p_event);
	
    break;

  case 4:
    drawSurface(p_game->background,138, 100, 90, 100, 17, 9);
    p_game->p_ghini->arrowDest.x = 186;

    p_game->p_ghini->arrowCollision = detectCollision(p_game->p_link->dst,
						      p_game->p_ghini->arrowDest, p_event);

    if (p_game->p_ghini->arrowCollision == 0) {
      p_game->p_link->life -= 1;
      remove_heart(p_game, p_event);
    } else {
      drawSurface(p_game->spritesheet, 165, 130, 573, 73, 16, 9);
    }
    p_game->p_ghini->arrowPosition = 0;
    p_game->p_ghini->throw = 0;
    break;
  }
}
