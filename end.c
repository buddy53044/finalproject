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