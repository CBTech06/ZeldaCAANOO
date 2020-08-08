/*************** Game & watch  Zelda **********************/
/*                  By NINTENDO                          */
/*         Coding for CAANOO by Captainchris PRD        */
/*                                                     */
/*******************************************************/

#include "draw.h"

void drawSurface(SDL_Surface * surface, int dst_x, int dst_y, int src_x,
		 int src_y, int src_w, int src_h)
{
  /* Source */
  SDL_Rect src;

  src.x = src_x;
  src.y = src_y;
  src.w = src_w;
  src.h = src_h;

  /* Destination */
  SDL_Rect dst;

  dst.x = dst_x;
  dst.y = dst_y;

  SDL_BlitSurface(surface, &src, SDL_GetVideoSurface(), &dst);
}
