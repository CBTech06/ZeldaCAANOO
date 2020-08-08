
/*************** Game & watch  Zelda **********************/
/*                  By NINTENDO                          */
/*         Coding for CAANOO by Captainchris PRD        */
/*                                                     */
/*******************************************************/


#include "music.h"

void playMUSSkeletonAttack()
{
  skeleton = Mix_LoadMUS("Res/Beep3.ogg");
  Mix_PlayMusic(skeleton, 0);
}

void playMUSMonsterAttack()
{
  monster = Mix_LoadMUS("Res/Beep1.ogg");
  Mix_PlayMusic(monster, 0);
}

void playMUSLinkAttack()
{
  link = Mix_LoadMUS("Res/Beep2.ogg");
  Mix_PlayMusic(link, 0);
}

void playMUSGameOver()
{
  gameover = Mix_LoadMUS("Res/GameOver.ogg");
  Mix_PlayMusic(gameover, 0);
}

void playMUSMonsterDead()
{
  mstdead = Mix_LoadMUS("Res/Enemy.ogg");
  Mix_PlayMusic(mstdead, 0);
}

void playMUSScore()
{
  score =  Mix_LoadMUS("Res/Beep2.ogg");
  Mix_PlayMusic(score,0);
}
