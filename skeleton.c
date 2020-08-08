/*************** Game & watch  Zelda **********************/
/*                  By NINTENDO                          */
/*         Coding for CAANOO by Captainchris PRD        */
/*                                                     */
/*******************************************************/

#include "skeleton.h"


void skLoad(t_game *p_game,t_event *p_event)
{
  if (!p_game->p_skeleton->initialized)  { 
  if (p_game->p_skeleton->number == 2) { drawSurface(p_game->spritesheet, 135, 148, 0, 452, 45, 50); }

  if (p_game->p_skeleton->number == 3) { 
	drawSurface(p_game->spritesheet, 92, 148, 0, 364, 36, 47);
	drawSurface(p_game->spritesheet, 135, 148, 0, 448, 41, 50); }

  if (p_game->p_skeleton->number == 4) {
    	drawSurface(p_game->spritesheet, 95, 148, 0, 364, 36, 47);
	drawSurface(p_game->spritesheet, 135, 148, 0, 448, 41, 50);
	drawSurface(p_game->spritesheet, 33, 148, 0, 289, 51, 49); }

  p_game->p_skeleton->initialized = 1;

  }
}

void skeletonFunc(int skeletonTimer, t_game *p_game, t_event * p_event)
{
  
  p_game->p_skeleton->ticks += skeletonTimer;
     
  if(p_game->p_skeleton->number == 1) { moveFirstSkeleton(p_game->p_skeleton->ticks,p_game); }
  if(p_game->p_skeleton->number == 2) { moveSecondSkeleton(p_game->p_skeleton->ticks,p_game,p_event);  }   
  if(p_game->p_skeleton->number == 3) { moveThirdSkeleton(p_game->p_skeleton->ticks,p_game,p_event); }
  if(p_game->p_skeleton->number == 4) { moveFourthSkeleton(p_game->p_skeleton->ticks,p_game,p_event); } 
  
  
  if (p_game->p_skeleton->ticks >= 800) {
    p_game->p_skeleton->ticks -= 800;	/* Change value to add velocity to monster */
     
    p_game->p_skeleton->attack += 1;

    if (p_game->p_skeleton->attack >= 3) {
      p_game->p_skeleton->attackIndex++;


      if(p_game->p_link->destination == p_game->p_skeleton->position) {
	p_game->p_skeleton->attack = 1;
	skeletonAttack(p_game, p_event);
      }

      else if (p_game->p_skeleton->attackIndex < 4 &&
	       p_game->p_link->destination != p_game->p_skeleton->position)  {

	p_game->p_skeleton->attack = 1;
	skeletonAttack(p_game, p_event);

      }
      else { p_game->p_skeleton->attackIndex = 0; }
    }
  }
}


void skeletonAttack(t_game *p_game, t_event * p_event)
{
  if (p_game->p_skeleton->position == 42) { skAttackAtFirstPosition(p_game,p_event); }
  if (p_game->p_skeleton->position == 90) { skAttackAtSecondPosition(p_game,p_event);  }
  if (p_game->p_skeleton->position == 138) { skAttackAtThirdPosition(p_game,p_event);  }
  if (p_game->p_skeleton->position == 186) { skAttackAtFourthPosition(p_game,p_event); }
   
   /* Attack to the end */
  if (p_game->p_skeleton->attackIndex >= 3) {
    p_game->p_skeleton->attackIndex = 0;
   }

   
}

void skAttackAtFirstPosition(t_game *p_game,t_event *p_event)
{
  
  switch (p_game->p_skeleton->attackIndex) {
  case 1:
    drawSurface(p_game->background, 33, 149, 36, 149, 68, 50);
    drawSurface(p_game->spritesheet, 34, 150, 67, 289, 69, 49);
    playMUSSkeletonAttack(); 

    break;

  case 2:
    drawSurface(p_game->background, 35, 143, 35, 143, 68, 58);
    drawSurface(p_game->spritesheet, 38, 143, 136, 282, 60, 55);
    playMUSSkeletonAttack(); 

    break;

  case 3:
    drawSurface(p_game->background, 38, 128, 38, 128, 61, 70);
    drawSurface(p_game->spritesheet, 36, 128, 204, 270, 61, 67);
    p_game->p_skeleton->attack = 0; 
    playMUSSkeletonAttack();

    if (p_game->p_link->destination ==
	p_game->p_skeleton->position) {
      p_game->p_link->life -= 1;
      remove_heart(p_game, p_event);
    }
    
    break;
   }
  
}

void skAttackAtSecondPosition(t_game *p_game,t_event *p_event)
{
  switch (p_game->p_skeleton->attackIndex) {
  case 1:
    p_game->p_skeleton->block = 1;
    drawSurface(p_game->background, 78, 130, 78, 130, 54, 68);
    drawSurface(p_game->spritesheet, 77, 148, 67, 366, 59, 48);

     if(p_game->p_skeleton->number == 4) { 
     drawSurface(p_game->background, 41, 130, 41, 130, 35, 80);
     drawSurface(p_game->spritesheet, 33, 148, 0, 289, 51, 49); }

        playMUSSkeletonAttack();
    break;

  case 2:
    drawSurface(p_game->background, 78, 146, 78, 146, 58, 50);
    drawSurface(p_game->spritesheet, 78, 146, 137, 364, 65, 49);
    
    /* Draw Fourth Skeleton after cleaning */
     if(p_game->p_skeleton->number == 4) { 
      drawSurface(p_game->background, 41, 130, 41, 130, 35, 80);
      drawSurface(p_game->spritesheet, 33, 148, 0, 289, 51, 49); }
    playMUSSkeletonAttack();
    
    break;

  case 3:
    drawSurface(p_game->background, 79, 135, 78, 135, 62, 60);
    drawSurface(p_game->spritesheet, 83, 130, 204, 349, 49, 67);
    p_game->p_skeleton->attack = 0;
    playMUSSkeletonAttack();
    if (p_game->p_link->destination ==
	p_game->p_skeleton->position) {
      p_game->p_link->life -= 1;
      remove_heart(p_game, p_event);
    }
   
    break;
  }
}

void skAttackAtThirdPosition(t_game *p_game,t_event * p_event)
{
  switch (p_game->p_skeleton->attackIndex) {
  case 1:
    drawSurface(p_game->background, 122, 128, 122, 128, 60, 70);
    drawSurface(p_game->spritesheet, 120, 148, 67, 448, 61, 48);
    playMUSSkeletonAttack(); 
    break;

  case 2:
    drawSurface(p_game->background, 122, 128, 122, 128, 60, 70);
    drawSurface(p_game->spritesheet, 120, 139, 136, 439, 60,57);
    playMUSSkeletonAttack(); 
    break;

  case 3:
    drawSurface(p_game->background, 120, 128, 120, 128, 60, 70);
    drawSurface(p_game->spritesheet, 133, 125, 206, 426, 44,70);
    p_game->p_skeleton->attack = 0;
    playMUSSkeletonAttack(); 
    if (p_game->p_link->destination ==
	p_game->p_skeleton->position) {
      p_game->p_link->life -= 1;
      remove_heart(p_game, p_event);
    }
    	    
    break;
  }
}

void skAttackAtFourthPosition(t_game *p_game,t_event *p_event)
{
  switch (p_game->p_skeleton->attackIndex) {
  case 1:
    drawSurface(p_game->background, 176, 140, 176, 140, 64, 73);
    drawSurface(p_game->spritesheet, 179, 148, 67, 548, 73, 47);
    playMUSSkeletonAttack(); 

    break;

  case 2:
    drawSurface(p_game->background, 175, 140, 175, 140, 64, 60);
    drawSurface(p_game->spritesheet, 173, 142, 149, 541, 88,54);
    playMUSSkeletonAttack();
    break;

  case 3:
    drawSurface(p_game->background, 175, 140, 175, 140, 90, 62);
    drawSurface(p_game->spritesheet, 187, 125, 248, 524, 66, 71);
    p_game->p_skeleton->attack = 0;
    playMUSSkeletonAttack();

    if (p_game->p_link->destination ==
	p_game->p_skeleton->position) {
      p_game->p_link->life -= 1;
      remove_heart(p_game, p_event);
    }
   
    break;
  }
  
}

void moveFirstSkeleton(int skTimer,t_game *p_game)
{
  if (skTimer >= 700) {
    skTimer -= 700;	/* Change value to add velocity to monster */

    if(p_game->p_skeleton->attack == 0) {
      switch (p_game->p_link->destination) {
      case 186:
	drawSurface(p_game->background, 34, 130, 34, 130, p_game->p_skeleton->eraser, 80);
	drawSurface(p_game->spritesheet, 198, 148, 0, 550, 47, 48);
	p_game->p_skeleton->position = 186;
	    
	break;
	    
      case 138:
	drawSurface(p_game->background, 34, 130, 34, 130, p_game->p_skeleton->eraser, 80);
	drawSurface(p_game->spritesheet, 135, 148, 0, 448, 41, 50);
	p_game->p_skeleton->position = 138;
	break;
	    
      case 90:
	drawSurface(p_game->background, 34, 130, 34, 130, p_game->p_skeleton->eraser, 80);
	drawSurface(p_game->spritesheet, 86, 148, 0, 364, 36, 47);
	p_game->p_skeleton->position = 90;
	break;
	    
      case 42:
	drawSurface(p_game->background, 34, 130, 34, 130, p_game->p_skeleton->eraser, 80);
	drawSurface(p_game->spritesheet, 40, 148, 0, 289, 51, 49);
	p_game->p_skeleton->position = 42;
	break;
      }
    }
  }
}

void moveSecondSkeleton(int skTimer,t_game *p_game,t_event *p_event)
{
 
  if (skTimer >= 700) {
    skTimer -= 700;	/* Change value to add velocity to monster */
    
    if(p_game->p_skeleton->attack == 0) {
      switch (p_game->p_link->destination) {
      case 186:
        drawSurface(p_game->background, 43, 126, 43, 126, 180, 13); /* Clear Arrow */
	drawSurface(p_game->background, 192, 129, 192, 129, 75, 81);
	drawSurface(p_game->background, 34, 128, 34, 128, 145, 80);
	drawSurface(p_game->spritesheet, 135, 148, 0, 448, 41, 50);
	drawSurface(p_game->spritesheet, 194, 148, 0, 551, 46, 46);
	p_game->p_skeleton->position = 186;
	break;

	case 138:
	 drawSurface(p_game->background, 43, 126, 43, 126, 180, 13); /* Clear Arrow */
	drawSurface(p_game->background, 183, 129, 183, 129, 72, 81);   /* Clear First Skeleton */
	drawSurface(p_game->spritesheet, 190, 148, 0, 551, 46, 46);    /* Draw First Skeleton */
	drawSurface(p_game->background, 34, 128, 34, 128, 145, 80);
	drawSurface(p_game->spritesheet, 135, 148, 0, 448, 41, 50);
	p_game->p_skeleton->position = 138;
	break;
	  
      case 90:
	 drawSurface(p_game->background, 43, 126, 43, 126, 180, 13); /* Clear Arrow */
	drawSurface(p_game->background, 180, 129, 180, 129, 75, 81); 
 	drawSurface(p_game->spritesheet, 190, 148, 0, 551, 46, 46);

	drawSurface(p_game->background, 34, 128, 34, 128, 145, 80);
	drawSurface(p_game->spritesheet, 86, 148, 0, 364, 36, 47);
	p_game->p_skeleton->position = 90;
	break;
	  
      case 42:
	 drawSurface(p_game->background, 43, 126, 43, 126, 180, 13); /* Clear Arrow */
	drawSurface(p_game->background, 180, 129, 180, 129, 75, 81); 
	drawSurface(p_game->spritesheet, 190, 148, 0, 551, 46, 46);

	drawSurface(p_game->background, 34, 130, 34, 130, 143, 80);
	drawSurface(p_game->spritesheet, 40, 148, 0, 289, 51, 49);
	p_game->p_skeleton->position = 42;
	break;
      }
    }
  }
}

void moveThirdSkeleton(int skTimer,t_game *p_game,t_event *p_event)
{
  
  if (skTimer >= 700) {
    skTimer -= 700;	/* Change value to add velocity to monster */
    
    if(p_game->p_skeleton->attack == 0) {
      switch (p_game->p_link->destination) {
      case 186:
        drawSurface(p_game->background, 43, 126, 43, 126, 180, 9); /* Clear Arrow */
	drawSurface(p_game->background, 180, 129, 180, 129, 72, 81);
	drawSurface(p_game->background, 34, 130, 34, 130, 140, 80);
	drawSurface(p_game->spritesheet, 180, 148, 0, 551, 46, 46);
	drawSurface(p_game->spritesheet, 135, 148, 0, 448, 41, 50);
	drawSurface(p_game->spritesheet, 86, 148, 0, 364, 36, 47);
	p_game->p_skeleton->position = 186;
	break;

      case 138:
        drawSurface(p_game->background, 43, 126, 43, 126, 180, 9); /* Clear Arrow */
	drawSurface(p_game->background, 180, 129, 180, 129, 72, 81);   /* Clear First Skeleton */
	drawSurface(p_game->spritesheet, 180, 148, 0, 551, 46, 46);    /* Draw First Skeleton */
	drawSurface(p_game->background, 34, 130, 34, 130, 100, 80);
	drawSurface(p_game->spritesheet, 86, 148, 0, 364, 36, 47);
	drawSurface(p_game->spritesheet, 135, 148, 0, 448, 41, 50);
	p_game->p_skeleton->position = 138;
	break;
	    
      case 90:
        drawSurface(p_game->background, 43, 126, 43, 126, 180, 9); /* Clear Arrow */
	drawSurface(p_game->background, 180, 129, 180, 129, 72, 81); 
 	drawSurface(p_game->spritesheet, 180, 148, 0, 551, 46, 46);
	drawSurface(p_game->background, 34, 130, 34, 130, 100, 80);
	drawSurface(p_game->spritesheet, 92, 148, 0, 364, 36, 47);
	p_game->p_skeleton->position = 90;
	break;
	  
      case 42:
        drawSurface(p_game->background, 43, 126, 43, 126, 180, 9); /* Clear Arrow */
	drawSurface(p_game->background, 180, 129, 180, 129, 72, 81); 
	drawSurface(p_game->background, 34, 130, 34, 130, 138, 80);
	drawSurface(p_game->spritesheet, 180, 148, 0, 551, 46, 46);
	
	drawSurface(p_game->spritesheet, 135, 148, 0, 448, 41, 50);
	drawSurface(p_game->spritesheet, 40, 148, 0, 289, 51, 49);
	p_game->p_skeleton->position = 42;
	break;
      }
    }
  }
}

void moveFourthSkeleton(int skTimer,t_game *p_game,t_event *p_event)
{
  if (skTimer >= 700) {
    skTimer -= 700;	/* Change value to add velocity to monster */
    
    if(p_game->p_skeleton->attack == 0) {
      switch (p_game->p_link->destination) {
      case 186:
	drawSurface(p_game->background, 180, 129, 180, 129, 72, 81);
	drawSurface(p_game->background, 34, 130, 34, 130, 140, 80);
	drawSurface(p_game->spritesheet, 180, 148, 0, 551, 46, 46);
	drawSurface(p_game->spritesheet, 135, 148, 0, 448, 41, 50);
	drawSurface(p_game->spritesheet, 88, 148, 0, 364, 36, 47);
	drawSurface(p_game->spritesheet, 40, 148, 0, 289, 51, 49);
	p_game->p_skeleton->position = 186;
	break;

      case 138:
	drawSurface(p_game->background, 180, 129, 180, 129, 72, 81);   /* Clear First Skeleton */
	drawSurface(p_game->spritesheet, 180, 148, 0, 551, 46, 46);    /* Draw First Skeleton */
	drawSurface(p_game->background, 34, 130, 34, 130, 100, 80);
	drawSurface(p_game->spritesheet, 40, 148, 0, 289, 51, 49);
	drawSurface(p_game->spritesheet, 88, 148, 0, 364, 36, 47);
	drawSurface(p_game->spritesheet, 135, 148, 0, 448, 41, 50);
	p_game->p_skeleton->position = 138;
	break;
	    
      case 90:
	drawSurface(p_game->background, 180, 129, 180, 129, 72, 81); 
 	drawSurface(p_game->spritesheet, 180, 148, 0, 551, 46, 46);
	drawSurface(p_game->background, 80, 130, 80, 130, 58, 80);
	drawSurface(p_game->spritesheet, 93, 148, 0, 364, 36, 47);
	p_game->p_skeleton->position = 90;
	break;
	  
      case 42:
	drawSurface(p_game->background, 180, 129, 180, 129, 72, 81); 
	drawSurface(p_game->background, 34, 130, 34, 130, 140, 80);
	drawSurface(p_game->spritesheet, 100, 148, 0, 364, 36, 47);
	drawSurface(p_game->spritesheet, 180, 148, 0, 551, 46, 46);
	drawSurface(p_game->spritesheet, 135, 148, 0, 448, 41, 50);
	drawSurface(p_game->spritesheet, 40, 148, 0, 289, 51, 49);
	p_game->p_skeleton->position = 42;
	break;
      }
    }
  }
}

 
