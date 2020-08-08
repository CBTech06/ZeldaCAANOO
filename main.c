/*************** Game & watch  Zelda **********************/
/*                  By NINTENDO                          */
/*         Coding for CAANOO by Captainchris PRD        */
/*                                                     */
/*******************************************************/

#include "main.h"

int main(int argc, char **argv)
{
  int quit = 0;
  int level = 1;
  int gameSelection = MENU;
  Uint32 timer = 0;
  
  TTF_Init();
 
  initScreen();
  t_event *p_event = initGame();
  t_menu *p_menu = initMenu();
  t_game *p_game = initGameW();
  
  initLevel(p_game);
  initLink(p_game);
  initGanon(p_game);
  initSkeleton(p_game);
  initGhini(p_game);
  
  Uint32 looptimer = SDL_GetTicks();

  while (!quit) {
    Uint32 newtimer = SDL_GetTicks();
    if (newtimer - timer > 30) {
      Uint32 deltaTicks = newtimer - looptimer;
      looptimer = timer = newtimer;

      event_joystate(p_event);

      if ((*p_event).buttons[6]) { quit = 1;  }

      if (p_event->buttons[8] && p_menu->selection == 1) { gameSelection = GAMEW; }
      if (p_event->buttons[8] && p_menu->selection  == 2) { gameSelection = GAMECP; }
	    

      if (p_event->buttons[9]) {
	p_game->isPaused = (p_game->isPaused +1) %2;
	drawSurface(p_game->screen2,0,0,0,0,320,240);
	showItem(p_game);
	p_event->buttons[9] = 0;
	p_game->unPaused = 1;
	           
      }
     
      if(p_game->isPaused == 0 && p_game->unPaused == 1)  {
	drawSurface(p_game->background, 0, 0, 0, 0, 320, 240);
	showDetails(p_game);
	if(p_game->p_ganon->dead == 0) {
	  if(p_game->p_skeleton->position == 42) { skAttackAtFirstPosition(p_game,p_event);}      
	  else if (p_game->p_skeleton->position == 90) { skAttackAtSecondPosition(p_game); }
	  else if (p_game->p_skeleton->position == 138) { skAttackAtThirdPosition(p_game,p_event);  }
	  else if (p_game->p_skeleton->position == 186) { skAttackAtFourthPosition(p_game,p_event); } }
	
	if(p_game->stair == LEFT_STAIRS || RIGHT_STAIRS || ALL_STAIRS ) { drawStairs(p_game);  }/* Draw Stairs */
	p_game->unPaused = 0;
	}

      if (gameSelection == MENU) {
	showMenu(p_event, p_menu);
      }

      if (gameSelection == GAMEW && p_game->p_link->life != 0) {
	if(p_game->isPaused == 0) {
	  changeRoom(p_game);
	   levelInformation(p_game);
	   
	  startGameW(p_event, p_game);

	  if (p_game->p_ganon->dead != 1) {
            if(p_game->p_ghini->status == ON) { ghiniFunc(deltaTicks,p_game); }
	    /*	    else if(p_game->level == 1) {p_game->p_skeleton->number = 1; }
	    else if(p_game->level == 3) { p_game->p_skeleton->number = 2; }
	    else if(p_game->level == 4) { p_game->p_skeleton->number = 3; }
	    else if(p_game->level == 5) { p_game->p_skeleton->number = 4; }
	    */
	    monsterFunc(deltaTicks, p_event, p_game);
	    skLoad(p_game,p_event);
	    skeletonFunc(deltaTicks, p_game, p_event);

	    if (p_game->p_ganon->throw == 1) {
	      monsterThrowArrow(deltaTicks, p_game, p_event);
	    }

	    if (p_game->p_ghini->throw == 1) { ghiniThrowArrow(deltaTicks,p_game,p_event); }
	  }

	  else if (p_game->p_ganon->dead == 1) { 
	    if(p_game->printScore == 0) {showScore(deltaTicks,p_game);  }
	  }
	}
	
      }
	    
	    
      if(gameSelection == GAMECP) {

	if(p_game->gcpIsLoaded == 0) {
	  SDL_FreeSurface(p_game->background);
	  SDL_FreeSurface(p_game->spritesheet);
	      
	  p_game->spritesheet = IMG_Load("Res/Vspritesheet.png");
	  SDL_SetAlpha(p_game->spritesheet, SDL_RLEACCEL, 0);
	  SDL_SetColorKey(p_game->spritesheet, SDL_SRCCOLORKEY,
			  SDL_MapRGB(p_game->spritesheet->format, 60, 64,
				     70));
	  p_game->background = IMG_Load("Res/VScreen1.png");
	  p_game->gcpIsLoaded = 1;
	}

	if(p_game->isPaused == 0) {
	  startGameW(p_event, p_game);
		 
	  if (p_game->p_ganon->dead != 1) {
	    monsterFunc(deltaTicks, p_event, p_game);
	    skeletonFunc(deltaTicks, p_game, p_event);
	    ghiniFunc(deltaTicks,p_game);
		   
	    if (p_game->p_ganon->throw == 1) {
	      monsterThrowArrow(deltaTicks, p_game, p_event);
	    }

	    if (p_game->p_ghini->throw == 1) {
	      ghiniThrowArrow(deltaTicks,p_game,p_event); }
	  }
	  else if (p_game->p_ganon->dead == 1) { 
	    if(p_game->printScore == 0) {showScore(deltaTicks,p_game);  }
	  }
	}
      }
	    
      /* Reset Game if GAMEOVER */
      if(gameSelection == GAMEW && p_event->buttons[8]) { resetGame(p_game); }
		

      /* Reset all var to new world */
      if(p_game->finish == 1) { 
	int room = p_game->p_level->room;
	int score = p_game->p_link->score;
	int heart = p_game->p_link->life;

	/* save items */
	int tomahawk = p_game->p_link->tomahawk;
	int map = p_game->p_link->map;
	int WOL = p_game->p_link->WOL;

	
	resetGame(p_game);
	     
	
	p_game->p_link->score = score;
	p_game->p_link->life = heart;
	p_game->p_link->tomahawk = tomahawk;
	p_game->p_link->map = map;
	p_game->p_link->WOL = WOL;
	p_game->p_link->counter = 0;
	p_game->stair = 0; 
	     
      }
	     
      if (p_event->buttons[8] && p_menu->selection == 1) { gameSelection = GAMEW; }
      SDL_Flip(SDL_GetVideoSurface());
    }
	
	
    else {
      //      SDL_Delay(30 - (newtimer - timer));
    }
  }
  freeMenu(p_menu);
  freeGame(p_event);
  freeGameW(p_game);
    
  TTF_Quit();
  Mix_CloseAudio();
  SDL_Quit();
}
