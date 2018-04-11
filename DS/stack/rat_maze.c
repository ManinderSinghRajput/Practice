#include<stdio.h>


typedef enum {false, true} bool;

void print_rat_maze_solution(int sol[8][8])
{
  int i, j;
  for(i=0;i<8;i++)
  {
    for(j=0;j<8;j++)
      if(sol[i][j] == 1)
        printf("{%d,%d} ",i,j);
  }
  printf("\n");
  return;
}

bool is_safe(int maze[8][8], int x, int y)
{
  if( x >= 0 && x < 8 && y >= 0 && y < 8 && maze[x][y] == 1)
    return true;
  
  return false;
}

bool rat_maze_solution_util(int puzzle[8][8], int x, int y, int sol[8][8])
{
  if(x == 7 && y == 7)
  {
    sol[x][y] = 1;
    return true;
  }

  if(is_safe(puzzle, x , y) == true)
  {
    sol[x][y]=1;
    if(rat_maze_solution_util(puzzle, x+1, y, sol) == true)
      return true;

    if(rat_maze_solution_util(puzzle, x, y+1, sol) == true)
      return true;
   
    sol[x][y]=0;
    return false;
  }

  return false;
}

bool rat_maze_solution(int puzzle[8][8])
{
  
  int sol[8][8] = {0};

  if(rat_maze_solution_util(puzzle, 0, 0, sol) == false)
  {
    printf("Solution does not exist.\n");
    return false;
  }
  
  print_rat_maze_solution(sol);
  return true;
}

int main()
{

  int rat_maze_puzzle[8][8]={ {1,0,0,0,1,1,1,1},{1,1,0,1,1,0,1,0},{1,1,1,1,1,0,1,1},{1,0,0,0,1,1,1,1},{1,0,1,1,1,0,1,1},{1,1,1,0,1,0,0,1},{0,1,0,0,1,0,1,1},{1,1,1,1,1,1,1,1} }; 


  rat_maze_solution(rat_maze_puzzle);
  return 0;
}



