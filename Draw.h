#ifndef __DRAW_H__
#define __DRAW_H__
#include <iostream>
#include "User.h"

using namespace std;
class Draw{
public:
  void titleDraw(){
    printf("\n\n\n\n");
    printf("        #####    ###    ###    #    ####   ##### \n");
    printf("        #       #      #      # #   #   #  #     \n");
    printf("        ####    ####   #     #####  ####   ####  \n");
    printf("        #           #  #     #   #  #      #     \n");
    printf("        #####   ####    ###  #   #  #      ##### \n");
  }
  void mapDraw(User *user, Map *map){
    system("clear");
    printf("\n\n\n\n");
    for(int i = 0;i < 14; i++){
      for(int j =0; j < 56; j++){
        char temp = map -> getOne(i, j);
        if(temp == '0'){ 
  				printf(" "); 
  			} else if(temp == '1') {
  				printf("#"); 
  			} else if(temp == 's') {
          user->changeLocation(i, j);
  				printf("@");
  			} else if(temp == 'q') {
  				printf("O");  
  			}
      }
      printf("\n");
    }
  }
};

#endif