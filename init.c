/*************** Game & watch  Zelda **********************/
/*                  By NINTENDO                          */
/*         Coding for CAANOO by Captainchris PRD        */
/*                                                     */
/*******************************************************/

#include "init.h"

SDL_Surface *initScreen(void)
{

  SDL_Init(SDL_INIT_EVERYTHING);

  if (NULL == (screen = SDL_SetVideoMode(320, 240, 16, SDL_HWSURFACE))) {
    fprintf(stderr, "Initialization Error: %s", SDL_GetError());
  }

  SDL_ShowCursor(SDL_DISABLE);


}

t_event *initGame()
{  
  t_event *p_event = malloc(sizeof(t_event));

  if(p_event) {
    p_event->buttons = (int *) calloc(40, sizeof(int));
    p_event->axes = (int *) calloc(10, sizeof(int));
    
    stick = SDL_JoystickOpen(0);

    if (-1 == Mix_OpenAudio(44100, AUDIO_S16, 2, 1024)) {
      fprintf(stderr, "Error Music Initialisation");
    }
  }
    
  return(p_event);
}

t_menu *initMenu()
{
  t_menu *p_menu = malloc(sizeof(t_menu));
    
  if(p_menu) {
    p_menu->img = IMG_Load("Res/spritesheet.png");

    SDL_SetAlpha(p_menu->img, SDL_RLEACCEL, 0);
    SDL_SetColorKey(p_menu->img, SDL_SRCCOLORKEY,
		    SDL_MapRGB(p_menu->img->format, 211, 211, 203));

    p_menu->background = IMG_Load("Res/Menu.png");
    p_menu->font = TTF_OpenFont("Res/wendy.ttf", 11);

    p_menu->text.r = 59;
    p_menu->text.b = 59;
    p_menu->text.g = 59;

    p_menu->original =
      TTF_RenderText_Solid(p_menu->font, "Version Game & Watch",
			   p_menu->text);
    p_menu->new =
      TTF_RenderText_Solid(p_menu->font, "Version Captainchris",
			   p_menu->text);

    p_menu->originalFontDest.x = 100;
    p_menu->originalFontDest.y = 130;

    p_menu->newFontDest.x = 100;
    p_menu->newFontDest.y = 150;

    p_menu->is_initialized = 0;
    p_menu->selection = 0;
   
  }

  return p_menu;
}

t_game * initGameW()
{
  t_game *p_game = malloc(sizeof(t_game));
   
  if(p_game) { 
    p_game->background = IMG_Load("Res/Screen1.png"); 
    p_game->screen2 = IMG_Load("Res/Screen2.png"); 
    p_game->spritesheet = IMG_Load("Res/spritesheet.png"); 
    p_game->scoreTxt = NULL;
    SDL_SetAlpha(p_game->spritesheet, SDL_RLEACCEL, 0);
    SDL_SetColorKey(p_game->spritesheet, SDL_SRCCOLORKEY,
		    SDL_MapRGB(p_game->spritesheet->format, 211, 211,203));
        
    p_game->isLoaded = 0;
    p_game->gcpIsLoaded = 0;
    p_game->digitalFont = TTF_OpenFont("Res/digital.ttf", 30);
    p_game->scoreColor.r = 120;
    p_game->scoreColor.b = 120;
    p_game->scoreColor.g = 120;
    p_game->printScore = 0;
    p_game->stair = 0;
    p_game->finish = 0;
    p_game->level = 5;
    p_game->reward = 0;
    p_game->isPaused = 0;
    p_game->unPaused = 0;
  }
  return p_game;
}

t_level *initLevel(t_game *p_game)
{
  p_game->p_level = malloc(sizeof(t_level));
    
  if (p_game->p_level) {
    p_game->p_level->room = 1;
    p_game->p_level->reward = 0;
   }
			  
  return p_game->p_level;
  
  
}

t_link *initLink(t_game *p_game)
{
  p_game->p_link = malloc(sizeof(t_link));
    
  if (p_game->p_link) {
    p_game->p_link->dst.x = 90;
    p_game->p_link->dst.w = 30;
    p_game->p_link->lifeDest = 70;
    p_game->p_link->life = 3;
    p_game->p_link->initialPosition = 0;
    p_game->p_link->source = 0;
    p_game->p_link->destination = 0;
    p_game->p_link->collision = 0;
    p_game->p_link->attack = 0;
    p_game->p_link->tomahawk = 0;
    p_game->p_link->map = 0;
    p_game->p_link->WOL = 0;
    p_game->p_link->score = 0;  
    p_game->p_link->counter = 0;
    p_game->p_link->scoreDst.x = 275;
    p_game->p_link->scoreDst.y = 210;
    p_game->p_link->scoreTicks = 0;
    p_game->p_link->roomDirection = 0;
  }
			  
  return p_game->p_link;
  
  
}

t_ganon *initGanon(t_game *p_game)
{
  p_game->p_ganon = malloc(sizeof(t_ganon)); 
  
  if(p_game->p_ganon) {
    p_game->p_ganon->scoreDst.x = 275;
    p_game->p_ganon->scoreDst.y = 210;
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
  }
  
  return p_game->p_ganon;
}

t_skeleton *initSkeleton(t_game *p_game)
{
  p_game->p_skeleton = malloc(sizeof(t_skeleton));

  if(p_game->p_skeleton) {
    p_game->p_skeleton->position = 0;
    p_game->p_skeleton->ticks = 0;
    p_game->p_skeleton->attack = 0;
    p_game->p_skeleton->attackIndex = 0;
    p_game->p_skeleton->block = 0;
    p_game->p_skeleton->number = 1;
    p_game->p_skeleton->eraser = 220;
    p_game->p_skeleton->initialized = 0;
  }

  return p_game->p_skeleton;
}

t_ghini *initGhini(t_game *p_game)
{
  p_game->p_ghini = malloc(sizeof(t_ghini));

  if(p_game->p_ghini) {
    p_game->p_ghini->status = 0;
    p_game->p_ghini->position = 0;
    p_game->p_ghini->ticks = 0;
    p_game->p_ghini->throw = 0;
    p_game->p_ghini->ifthrow = 0;
    p_game->p_ghini->arrowTicks = 0;
    p_game->p_ghini->arrowPosition = 0;
  }
  
  return p_game->p_ghini;
}


void freeGameW(t_game *p_game)
{
  SDL_FreeSurface(p_game->spritesheet);
  SDL_FreeSurface(p_game->background);
  SDL_FreeSurface(p_game->scoreTxt);
  SDL_FreeSurface(p_game->screen2);
  TTF_CloseFont(p_game->digitalFont);
  free(p_game->p_ghini);
  free (p_game->p_skeleton);
  free (p_game->p_ganon);
  free (p_game->p_link);
  free (p_game->p_level);
  free (p_game);
    
}

void freeMenu(t_menu * p_menu)
{
  SDL_FreeSurface(p_menu->img);
  SDL_FreeSurface(p_menu->background);
  SDL_FreeSurface(p_menu->original);
  SDL_FreeSurface(p_menu->new);
  TTF_CloseFont(p_menu->font);
      
  free(p_menu);
}



void freeGame(t_event *p_event)
{
  free(p_event->buttons);
  free(p_event->axes);
  SDL_JoystickClose(stick);

  Mix_FreeMusic(skeleton);
  Mix_FreeMusic(monster);
  Mix_FreeMusic(link);
  Mix_FreeMusic(gameover);
  Mix_FreeMusic(mstdead);
  Mix_FreeMusic(score);
    
}

