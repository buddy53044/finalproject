#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

//borad
int Allpiece[16][16] = {0};

bool gameover = false;
int winner = 0;

//1=black is X 2=white is O
int piececolor;
// number of piece
int piecenumber = 0;
int nowX;
int nowY;

void inputdata();
void DrawThePieces();
void End();
int whowin();

int main()
{
  while (!gameover)
  {
    inputdata();
    DrawThePieces();
    End();
  }
  return 0;
}
