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
      if (Allpiece[i][j] == 0)
      {
        printf("_ ");
      }
      if (Allpiece[i][j] == 1)
      {
        printf("X ");
      }
      if (Allpiece[i][j] == 2)
      {
        printf("O ");
      }
    }
    printf("\n");
  }
}
