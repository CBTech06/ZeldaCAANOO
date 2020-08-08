/*************** Game & watch  Zelda **********************/
/*                  By NINTENDO                          */
/*         Coding for CAANOO by Captainchris PRD        */
/*                                                     */
/*******************************************************/

#include "menu.h"


int showMenu(t_event *p_event, t_menu *p_menu)
{

  if (p_menu->is_initialized == NOT_INITIALIZED) {
    drawSurface(p_menu->background, 0, 0, 0, 0, 320, 240);
    drawSurface(p_menu->img, 70, 130, 453, 0, 21, 14);
    p_menu->selection = 1;
    p_menu->is_initialized = INITIALIZED;

  }

  /* Show item */
  SDL_BlitSurface(p_menu->original, NULL, SDL_GetVideoSurface(),&p_menu->originalFontDest);
  SDL_BlitSurface(p_menu->new, NULL, SDL_GetVideoSurface(), &p_menu->newFontDest);

  /* Disable Analogic Stick Repeating */
  int value = SDL_JoystickGetAxis(stick, 1);

  /* If CAANOO axe value is -32768*/
  if (p_event->axes[1] == -32768 || p_event->axes[1] == 32767) {
    p_event->joystate++;
  }

  if (value == 0) { p_event->joystate = 0; }

  /* Up Direction */
  if (p_event->joystate < 2) {
    /* If CAANOO axe value is -32768*/
    if (p_event->axes[1] == -32768) {
	  
      SDL_BlitSurface(p_menu->background, NULL,
		      SDL_GetVideoSurface(), NULL);
      drawSurface(p_menu->img, 70, 130, 453, 0, 21, 14);
      p_menu->selection = 1;
    }
  }

  /* Down Direction */
  if (p_event->joystate < 2) {
    if (p_event->axes[1] == 32767) {
      drawSurface(p_menu->background, 0, 0, 0, 0, 320, 240);
      drawSurface(p_menu->img, 70, 150, 453, 0, 21, 14);
      p_menu->selection = 2;
    }
  }

}
