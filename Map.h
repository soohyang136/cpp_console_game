#ifndef __MAP_H__
#define __MAP_H__



class Map{
private:
  char map[14][56] = { 
    {"1111111111111111111111111111111111111111111111111111111"},
    {"1000001000100010000100000000001000100000100010100010001"},
    {"1000001010101011110101111101101010101110101010101000101"},
    {"1000101010001000010101000101001010101010101000111111101"},
    {"1000100010111111110101010101111000100010101111100000001"},
    {"1000111110100000000101010100000001110110101000101011111"},
    {"1000100000101111111101010111011100000010001010001010001"},
    {"1000101111101000000001010000000111011010100010100010001"},
    {"1000101000001000000101011011110000000010101010101000101"},
    {"1000101011101000000100000000010101111010101010101111101"},
    {"1000101010001000000111101111000100001010101010001000001"},
    {"10s010101111111110110010100001011110100010111110100q001"},
    {"1000100000000000001000100011110000001010100000001000001"},
    {"1111111111111111111111111111111111111111111111111111111"}
  };
public:
  char getOne(int i, int j){
    return map[i][j];
  }
  void change(int i, int j, char a){
    this -> map[i][j] = a;
  }
};

#endif