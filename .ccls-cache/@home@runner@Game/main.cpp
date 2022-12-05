#include <iostream>
#include <termios.h>
#include <unistd.h>
using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

int x, y;
int playing = 1;

char map[14][56] = { 
	{"1111111111111111111111111111111111111111111111111111111"},
	{"1000001000100010000100000000001000100000100010100010001"},
	{"1000001010101011110101111101101010101110101010101000101"},
	{"1000101010001000010101000101001010101010101000111111101"},
	{"1000100010111111110101010101111000100010101111100000001"},
	{"1000111111100000000101010100000001110110101000101011111"},
	{"1000100000101111111101010111011100000010001010001010001"},
	{"1000101111101000000001010000000111011010100010100010001"},
	{"1000101000001000000101011011110000000010101010101000111"},
	{"1000101011101000000100000000010101111010101010101111111"},
	{"100010101k001000000111101111000100001010101010001000001"},
	{"10s010101111111110110010100001011110100010111110100q001"},
	{"1000100000l000l0001000100011110000001010100000001000001"},
	{"1111111111111111111111111111111111111111111111111111111"}
};

void mapDraw(){
  printf("\n\n\n\n");
  for(int i = 0;i < 14; i++){
    for(int j =0; j < 56; j++){
      char temp = map[i][j];
      if(temp == '0'){ 
				printf(" "); 
			} else if(temp == '1') {
				printf("#"); 
			} else if(temp == 's') {
        x = i;
        y = j;
				printf("@");
			} else if(temp == 'q') {
				printf("O");  
			}
    }
    cout << "\n";
  }
}

int getch(void)

{

    struct termios oldt, newt;

    int ch;

    tcgetattr( STDIN_FILENO, &oldt );

    newt = oldt;

    newt.c_lflag &= ~( ICANON | ECHO );

    tcsetattr( STDIN_FILENO, TCSANOW, &newt );

    ch = getchar();

    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );

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
    } else if(temp == ' '){ // �����̽���(����)�� ���� ��ư
        return SUBMIT;
    }
}

void move(int x, int y, int i, int j){
  if(map[x + i][y + j]){
    printf("실패");
    playing = 0;
  }
  else{
    map[x][y] = ' ';
    map[x+i][y+j] = 's';
  }
}

int main() {
  
  printf("\n\n\n\n");
  printf("        #####    ###    ###    #    ####   ##### \n");
  printf("        #       #      #      # #   #   #  #     \n");
  printf("        ####    ####   #     #####  ####   ####  \n");
  printf("        #           #  #     #   #  #      #     \n");
  printf("        #####   ####    ###  #   #  #      ##### \n");
  while(playing){
		mapDraw();
		switch(keyControl()){
			case UP:
				move(x, y, 0, -1); // ����x, ����y, x�������� �̵��� ĭ, y�������� �̵��� ĭ  
				break;
				
			case DOWN:
				move(x, y, 0, 1); // x��ġ�� �״��, y��ġ�� +1 (�Ʒ���) 
				break;
				
			case RIGHT:
				move(x, y, 1, 0); // x��ġ�� +1, y�� �״��(������) 
				break;
				
			case LEFT:
				move(x, y, -1, 0); // x��ġ�� -1, y�� �״��(����) 
				break;
				
			case SUBMIT:
				playing = 0; // 0�� �Ǹ� �ݺ� ����  
		} 
	}
}
