#ifndef __INPUT_H__
#define __INPUT_H__

#include <iostream>
#include <limits>
#include <termios.h>
#include <unistd.h> // read 함수
using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

int getch(void)  
{  
  int ch;  
  struct termios buf;  
  struct termios save;  
  
   tcgetattr(0, &save);  
   buf = save;  
   buf.c_lflag &= ~(ICANON|ECHO);  
   buf.c_cc[VMIN] = 1;  
   buf.c_cc[VTIME] = 0;  
   tcsetattr(0, TCSAFLUSH, &buf);  
   ch = getchar();  
   tcsetattr(0, TCSAFLUSH, &save);  
   return ch;  
} 

int keyControl(){
    char temp = getch();

    if(temp == 'w' || temp == 'W'){
        return UP;
    } else if(temp == 'a' || temp == 'A'){
        return LEFT;
    } else if(temp == 's' || temp == 'S'){
        return DOWN;
    } else if(temp == 'd' || temp == 'D'){
        return RIGHT;
    } else if(temp == ' '){ 
        return SUBMIT;
    }
}
#endif