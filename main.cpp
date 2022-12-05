#include <iostream>
#include <termios.h>
#include <unistd.h>
#include "Draw.h"
#include "User.h"
#include "Game.h"
#include "Map.h"
using namespace std;

int main(){
  Draw draw;
  Game game(1);
  User user(0, 0);
  Map map;
  draw.titleDraw();
  sleep(3);
  game.play(&draw, &user, &map);
}
