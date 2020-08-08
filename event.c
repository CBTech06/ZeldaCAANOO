/*************** Game & watch  Zelda **********************/
/*                  By NINTENDO                          */
/*         Coding for CAANOO by Captainchris PRD        */
/*                                                     */
/*******************************************************/

#include "event.h"

void event_joystate(t_event * p_event)
{
  memset(&event_State, 0, sizeof(SDL_Event));

  SDL_PollEvent(&event_State);

  switch (event_State.jbutton.type) {
  case SDL_JOYAXISMOTION:
    p_event->axes[event_State.jaxis.axis] = event_State.jaxis.value;
    break;

  case SDL_JOYBUTTONDOWN:
    p_event->buttons[event_State.jbutton.button] = 1;
    p_event->attack = 1;
    break;

  case SDL_JOYBUTTONUP:
    p_event->buttons[event_State.jbutton.button] = 0;
    p_event->buttonstate = 0;
    p_event->attack = 0;
    break;
  }
}
