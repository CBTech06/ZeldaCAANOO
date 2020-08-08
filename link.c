
/*************** Game & watch  Zelda **********************/
/*                  By NINTENDO                          */
/*         Coding for CAANOO by Captainchris PRD        */
/*                                                     */
/*******************************************************/


#include "link.h"


void showLink(t_event *p_event, t_game *p_game)
{

  if (p_game->p_link->initialPosition == 0) {
    p_game->p_link->destination = 90;
    drawSurface(p_game->spritesheet, p_game->p_link->destination,
		72, 50, 2, 35, 51);
    p_game->p_link->initialPosition = 1;
  }

  /* Disable Analogic Stick Repeating */
  int leftRight = SDL_JoystickGetAxis(stick, 0);


  if (p_event->axes[0] == -32768 || p_event->axes[0] == 32767) {
    p_event->joystate++;
  }

  if (p_event->axes[1] == -32768 || p_event->axes[1] == 32767) {
    p_event->joystate++;
  }

  if (leftRight == 0) {
    p_event->joystate = 0;
  }

  /*Right Direction */
  if (p_event->joystate < 2) {
    if (p_event->axes[0] >= 32767) {
      linkRightDirection(p_game);
    }
  }

  /* Left Direction */
  if (p_event->joystate < 2) {
    if (p_event->axes[0] == -32768) {
      linkLeftDirection(p_game);
    }
  }

  /* Down  Direction */
  if (p_event->joystate < 2) {
    if (p_event->axes[1] == 32767) {
      linkDownDirection(p_game);
    }
  }
    
  /* Up Direction */
  if (p_event->joystate < 2) {
    if(p_event->axes[1] == -32768) {
      if(p_game->p_ganon->dead ==1) {  linkUpstair(p_game); }
    }
  }

  linkAttack(p_event, p_game);

}

void linkLeftDirection(t_game *p_game)
{
  if (p_game->p_link->source > 0) {
    p_game->p_link->source -= 50;
  }

  if (p_game->p_link->destination > 50) {
    p_game->p_link->dst.x = p_game->p_link->destination -= 48;
  }
  drawSurface(p_game->background, 40, 72, 40, 72, 185, 55);
  drawSurface(p_game->spritesheet, p_game->p_link->destination, 72,
	      p_game->p_link->source, 0, 38, 53);
}

void linkRightDirection(t_game *p_game)
{

  if (p_game->p_link->source < 150) {
    p_game->p_link->source += 50;
  }

  if (p_game->p_link->destination < 170) {
    p_game->p_link->dst.x = p_game->p_link->destination += 48;
  }



  drawSurface(p_game->background, 40, 72, 40, 72, 185, 55);
  drawSurface(p_game->spritesheet, p_game->p_link->destination, 72,
	      p_game->p_link->source, 0, 38, 53);
}

void linkDownDirection(t_game *p_game)
{
  if (p_game->p_link->life == 1) {
    p_game->p_link->life += 4;
    addHeart(4, p_game);
  }

  if (p_game->p_link->life == 2) {
    p_game->p_link->life += 3;
    addHeart(3, p_game);
  }

  if (p_game->p_link->life == 3) {
    p_game->p_link->life += 2;
    addHeart(2, p_game);
  }

  if (p_game->p_link->life == 4) {
    p_game->p_link->life += 1;
    addHeart(1, p_game);
  }
}



void linkUpstair(t_game *p_game)
{
  
  if(p_game->p_link->dst.x == 42 && (p_game->stair == LEFT_STAIRS || p_game->stair == ALL_STAIRS) )
    {      
      drawSurface(p_game->background, 40, 72, 40, 72, 185, 55);
      drawSurface(p_game->spritesheet,30,5,289,184,52,48);     /* Draw Link */
      SDL_Delay(1000);
      p_game->finish = 1;
      p_game->p_link->roomDirection = LEFT_DIRECTION;
    }
  
  if( p_game->p_link->dst.x == 186 && (p_game->stair == RIGHT_STAIRS || p_game->stair == ALL_STAIRS))
    {
      drawSurface(p_game->background, 40, 72, 40, 72, 185, 55);
      drawSurface(p_game->spritesheet,190,5,358,184,52,48);    /* Draw Link */ 
      SDL_Delay(1000);
         
      p_game->finish = 1;
      p_game->p_link->roomDirection = RIGHT_DIRECTION;
    }
}


void linkAttack(t_event *p_event, t_game *p_game)
{
  /* Disable Multiple Attack */
  if (p_event->buttons[1]) {
    p_event->buttonstate++;
  }

  /*Attack at the first position */
  if (p_game->p_link->life != 0) {
    if (p_event->buttons[1] && p_game->p_link->destination == 42) {
      drawSurface(p_game->background, 40, 72, 40, 72, 60, 55);
      drawSurface(p_game->spritesheet, 42, 78, 0, 64, 61, 52);
      
    }

    /* Attack at the second position */
    if (p_event->buttons[1] && p_game->p_link->destination == 90) {
      drawSurface(p_game->background, 83, 72, 83, 72, 60, 55);
      drawSurface(p_game->spritesheet, 90, 78, 71, 64, 58, 50);
      
    }

    /*Attack at the third position */
    if (p_event->buttons[1]
	&& p_game->p_link->destination == 138) {
      drawSurface(p_game->background, 130, 72, 130, 72, 60, 55);
      drawSurface(p_game->spritesheet, 138, 78, 129, 64, 56, 49);
     }

    /*Attack at the fourth position */
    if (p_event->buttons[1]
	&& p_game->p_link->destination == 186) {
      drawSurface(p_game->background, 170, 72, 170, 72, 60, 56);
      drawSurface(p_game->spritesheet, 175, 79, 190, 64, 57, 49);
     
    }
  }
  
  linkReturnInitialPosition(p_event, p_game);

}

void linkReturnInitialPosition(t_event *p_event, t_game *p_game)
{
  
  if (p_game->p_link->life != 0) {
    if (p_event->attack == 0) {
      if (p_game->p_link->destination == 42) {
	drawSurface(p_game->background, 40, 72, 40, 72, 185, 55);	/* Clear Link */
	drawSurface(p_game->spritesheet, 42, 72, 0, 0, 40, 58);	/* Show link */
	p_event->attack = 1;

      }

      /* Return to  the second position */
      if (p_game->p_link->destination == 90) {
	drawSurface(p_game->background, 40, 72, 40, 72, 185,
		    55);
	drawSurface(p_game->spritesheet, 90, 72, 50, 0, 38, 54);
	p_event->attack = 1;

      }

      /*Return to the  third position */
      if (p_game->p_link->destination == 138) {
	drawSurface(p_game->background, 40, 72, 40, 72, 185,
		    55);
	drawSurface(p_game->spritesheet, 138, 72, 100, 0, 38,
		    54);
	p_event->attack = 1;
      }

      /*Return to  the fourth position */
      if (p_game->p_link->destination == 186) {
	drawSurface(p_game->background, 40, 72, 40, 72, 185,
		    56);
	drawSurface(p_game->spritesheet, 186, 73, 150, 0, 38,
		    54);

	/* Clear Sword */
	drawSurface(p_game->background, 220, 83, 220, 84, 20,
		    10);
	p_event->attack = 1;
	p_game->p_link->attack = 0;
      }
    }
  }
}


void dead_link(t_game *p_game, t_event *p_event)
{

  /* remove Monster */
  drawSurface(p_game->background, 223, 84, 223, 84, 18, 10);
  drawSurface(p_game->background, 40, 72, 40, 72, 279, 123);
  drawSurface(p_game->spritesheet, 100, 200, 6, 122, 62, 19);
  playMUSGameOver();
}

void linkNothingItem(t_game *p_game)
{
  drawSurface(p_game->background, 40, 72, 40, 72, 185, 56);
  drawSurface(p_game->background, 220, 83, 220, 84, 20, 10);	/* Clear Sword */

  p_game->p_link->destination = 90;
  drawSurface(p_game->spritesheet, p_game->p_link->destination, 73, 49, 2, 37, 52);
  SDL_Delay(3000);

  drawSurface(p_game->spritesheet, 15, 45, 80, 121, 46, 24);	/* Draw Stairs */
  drawSurface(p_game->spritesheet, 210, 45, 136, 121, 46, 24);
  p_game->stair = 1;
    
  p_game->p_ganon->dead = 1;
  drawStairs(p_game); 
}

void linkTomahawkItem(t_game *p_game)
{
  drawSurface(p_game->background, 40, 72, 40, 72, 185, 56);
  drawSurface(p_game->background, 220, 83, 220, 84, 20, 10);	/* Clear Sword */


  p_game->p_link->destination = 90;
  drawSurface(p_game->spritesheet, p_game->p_link->destination, 55, 330, 13, 33, 72);
  SDL_Delay(3000);

  drawSurface(p_game->background, 90, 55, 90, 55, 33, 72);	/* Clear Link & Tomahawk */
  p_game->p_ganon->dead = 1;
  p_game->p_link->tomahawk = 1;
  drawStairs(p_game);    
   
}

void linkMapItem(t_game *p_game)
{
  drawSurface(p_game->background, 40, 72, 40, 72, 185, 56);
  drawSurface(p_game->background, 220, 83, 220, 84, 20, 10);	/* Clear Sword */

  p_game->p_link->destination = 90;
  drawSurface(p_game->spritesheet, p_game->p_link->destination, 58, 376, 17, 40, 67);
  SDL_Delay(3000);

  drawSurface(p_game->background, 90, 55, 90, 55, 40, 67);	/* Clear Link & map */
  
  p_game->p_ganon->dead = 1;
  p_game->p_link->map = 1;
  drawStairs(p_game); 
}

void linkWOLItem(t_game *p_game)
{
  drawSurface(p_game->background, 40, 72, 40, 72, 185, 56);
  drawSurface(p_game->background, 220, 83, 220, 84, 20, 10);	/* Clear Sword */

  p_game->p_link->destination = 90;
  drawSurface(p_game->spritesheet, p_game->p_link->destination, 58, 427, 15, 37, 70);
  SDL_Delay(3000);

  drawSurface(p_game->background, 90, 55, 90, 55, 40, 67);	/* Clear Link & WOL */
    
  p_game->p_ganon->dead = 1;
  p_game->p_link->WOL = 1;
  drawStairs(p_game); 
   
}

void linkHeartItem(t_game *p_game)
{
  drawSurface(p_game->background, 40, 72, 40, 72, 185, 56);
  drawSurface(p_game->background, 220, 83, 220, 84, 20, 10);	/* Clear Sword */

  p_game->p_link->destination = 90;
  drawSurface(p_game->spritesheet, p_game->p_link->destination, 58, 286, 18, 30, 65);
  SDL_Delay(3000);
  drawSurface(p_game->background, 90, 55, 90, 55, 40, 67);	/* Clear Link & Hearts */
 
  addHeart(1, p_game);
 
  p_game->p_ganon->dead = 1;
  drawStairs(p_game);  
}
