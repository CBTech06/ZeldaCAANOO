/*************** Game & watch  Zelda **********************/
/*                  By NINTENDO                          */
/*         Coding for CAANOO by Captainchris PRD        */
/*                                                     */
/*******************************************************/

#ifndef DRAW_H
#define DRAW_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <stdlib.h>

/* prototype */
void drawSurface(SDL_Surface * surface, int dst_x, int dst_y, int src_x,
		 int src_y, int src_w, int src_h);


#endif
