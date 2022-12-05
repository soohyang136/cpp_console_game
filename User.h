#ifndef __USER_H__
#define __USER_H__

#include <iostream>
#include "Map.h"
using namespace std;

class User{
private:
  int x;
  int y;
public:
  User(int x, int y){
    this -> x = x;
    this -> y = y;
  }
  int move(int i, int j, Map *map){
      if(map->getOne(x + i, y + j) == '1'){
        printf("실패");
        return 0;
      }
      else if(map->getOne(x + i, y + j) == 'q'){
        printf("게임 클리어!!!");
        return 0;
      }
      else {
        map->change(x, y, '0');
        map->change(x + i, y + j, 's');
        return 1;
      }
  }
  void changeLocation(int x, int y){
    this->x=x;
    this->y=y;
  }
  int getX(){
    return x;
  }
  int getY(){
    return y;
  }
};
#endif