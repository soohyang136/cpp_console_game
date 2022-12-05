#ifndef __GAME_H__
#define __GAME_H__
#include "Input.h"


#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4


class Game{
private:
  int playing;
public:
  Game(int playing){
    this->playing = playing;
  }
  void play(Draw *draw, User *user, Map *map){
    while(playing){
		  draw->mapDraw(user, map);
  		switch(keyControl()){
  			case UP:
  				playing = user->move(-1, 0, map);
  				break;
  			case DOWN:
  				playing = user->move(1, 0, map);
  				break;
  				
  			case RIGHT:
  				playing = user->move(0, 1, map);
  				break;
  				
  			case LEFT:
  				playing = user->move(0, -1, map);
  				break;		  
  		} 
	  }
  }
};

#endif