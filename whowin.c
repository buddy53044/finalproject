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