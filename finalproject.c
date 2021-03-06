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


void DrawThePieces()
{
  //draw the all pieces
  //0:no piece is _
  //1:black piece is X
  //2:white piece is O
  printf("  0 1 2 3 4 5 6 7\n");
  for (int i = 0; i < 8; i++)
  {
    printf("%d ",i);
    for (int j = 0; j < 8; j++)
    {
      if (Allpiece[j][i] == 0)
      {
        printf("_ ");
      }
      if (Allpiece[j][i] == 1)
      {
        printf("X ");
      }
      if (Allpiece[j][i] == 2)
      {
        printf("O ");
      }
    }
    printf("\n");
  }
}

void End()
{

  if (whowin() != 0)
  {
    gameover = true;
    winner = whowin();
  }
  //gameover
  if (gameover)
  {
    if (winner == 1)
    {
      printf("Black X win");
    }
    if (winner == 2)
    {
      printf("White O  win");
    }
    if (winner == 3)
    {
      printf("No one win");
    }
  }
}

void inputdata()
{ //input the position of x and y
  //0:no piece is _
  //1:black piece is X
  // 2:white piece is O

  // Allpiece[0][0] = 1;
  // Allpiece[0][1] = 1;
  // Allpiece[0][2] = 1;
  // Allpiece[0][3] = 1;
  // Allpiece[0][4] = 1;

  piececolor = (piecenumber % 2) + 1;
  piececolor == 1 ? printf("input X position:") : printf("input O position:");
  scanf("%d", &nowX);
  scanf("%d", &nowY);
  if (Allpiece[nowX][nowY] == 0 && !gameover)
  {
    Allpiece[nowX][nowY] = piececolor;
    piecenumber++;
    // if (whowin()!=0) {
    //   gameover=true;
    //   winner=whowin();
    // }
  }
}

int whowin()
{
  int n = 0;

  //deuce
  if (piecenumber >= 64)
  {
    return 3;
  }
  //horizon text//

  //left side
  for (int lx = nowX; lx >= 0; lx--)
  {
    if (Allpiece[lx][nowY] == Allpiece[nowX][nowY])
      n++;
    else
      break;
  }

  //right side
  for (int rx = nowX; rx < 11; rx++)
  {
    if (Allpiece[rx][nowY] == Allpiece[nowX][nowY])
      n++;
    else
      break;
  }
  if (n - 1 >= 5)
    return piececolor;
  else
    n = 0;

  //vertical text//

  //up side
  for (int uy = nowY; uy >= 0; uy--)
  {
    if (Allpiece[nowX][uy] == Allpiece[nowX][nowY])
      n++;
    else
      break;
  }

  //down side
  for (int uy = nowY; uy < 11; uy++)
  {
    if (Allpiece[nowX][uy] == Allpiece[nowX][nowY])
      n++;
    else
      break;
  }
  if (n - 1 >= 5)
    return piececolor;
  else
    n = 0;

  // slope=-1
  for (int i = 0; i < 5; i++)
  {
    if (Allpiece[nowX + i][nowY + i] == Allpiece[nowX][nowY])
      n++;
    else
      break;
  }
  for (int i=0; i<5; i++) {
    int x, y;
    bool border=false; //avoid array index out of bounds exception

    if (nowX-i<0) {
      x=0;
      border=true;
    } else x=nowX-i;

    if (nowY-i<0) {
      y=0;
      border=true;
    } else y=nowY-i;

    if (border)break;

    if (Allpiece[x][y]==Allpiece[nowX][nowY])n++;
    else break;
  }

  if (n - 1 >= 5)
    return piececolor;
  else
    n = 0;

  //slope=+1
  for (int i = 0; i < 5; i++)
  {
    int x, y;
    bool border = false; //avoid array index out of bounds exception

    if (nowX - i < 0)
    {
      x = 0;
      border = true;
    }
    else
      x = nowX - i;

    y = nowY + i;

    if (border)
      break;

    if (Allpiece[x][y] == Allpiece[nowX][nowY])
      n++;
    else
      break;
  }

  for (int i = 0; i < 5; i++)
  {
    int x, y;
    bool border = false; //avoid array index out of bounds exception

    x = nowX + i;

    if (nowY - i < 0)
    {
      y = 0;
      border = true;
    }
    else
      y = nowY - i;

    if (border)
      break;

    if (Allpiece[x][y] == Allpiece[nowX][nowY])
      n++;
    else
      break;
  }

  if (n - 1 >= 5)
    return piececolor;
  else
    n = 0;

  return 0;
}
