
#include<stdio.h>

void print_sudoku(int sudoku[9][9])
{
  printf("The Sudoku contains:\n");
  for (int j=0; j<9; j++)
  {
    for (int i=0; i<9;i++)
    {
      printf("%d  ",sudoku[j][i]);
    }
    printf("\n");
  }
}

 // checks if spot at x,y is a valid move
int check_sudoku(int sudoku[9][9],int y,int x,int val){
  int xLim,yLim;//set up bounds for the box
  yLim = (y<3)? 3 : ((y<6)?6:9);
  xLim = (x<3)? 3 : ((x<6)?6:9);
  for (int i = yLim - 3;i < yLim;i++){//checks box
    for(int j = xLim - 3; j < xLim; j++)
      if(sudoku[i][j] == val) return 0;
  }
  for (int j = 0;j < 9;j++)// check col
    if(sudoku[y][j] == val) return 0;
  for (int i = 0;i < 9;i++)//check row
    if(sudoku[i][x] == val) return 0;
  return 1;  
}

int recursive_helper(int sudoku[9][9],int y ,int x, int depth){
  //printf("depth = %d x = %d y = %d val = %d \n",depth,x,y,sudoku[y][x]);//best debugger
  if(depth > 81) return 1;//B.C - it is impossible to be at depth 82 without completing
  if(sudoku[y][x] != 0) // move forward if spot is not 0
    return recursive_helper(sudoku,(x==8)?y+1:y,(x==8)?0:x+1,depth+1);
  for(int i=9;i>=0;i--){
    if(i == 0){//exausted all moves in the spot, backtrack to last stack
      sudoku[y][x] = 0;//revert block
      return 0;
    }
    else if(check_sudoku(sudoku,y,x,i)){
      sudoku[y][x] = i;
      if(recursive_helper(sudoku,(x==8)?y+1:y,(x==8)?0:x+1,depth+1)) return 1;
    }
  }
  return 0;
}



//pass in any 9 by 9 matrix that represents the Sudoku Puzzle.
//if succeeded, the solved matrix will replace the argument
//if failed, the argument will not be mutated. 
void solve_sudoku(int sudoku[9][9]){
  for(int i = 0;i<9;i++){//checks if the starting matrix is valid
    for(int j =0;j<9;j++){
      if (sudoku[i][j] != 0){
        int temp = sudoku[i][j];
        sudoku[i][j]=0;
        if( !check_sudoku(sudoku,i,j,temp) ){
          sudoku[i][j] = temp;
          return;
        }
        sudoku[i][j] = temp; }
      }
    }
  recursive_helper(sudoku,0,0,0);// if matrix is valid, attempt to solve
}


int main(){
   int Sudoku[9][9]={
         {5, 3, 0, 0, 7, 0, 0, 0, 0},
		     {6, 0, 0, 1, 9, 5, 0, 0, 0},
		     {0, 9, 8, 0, 0, 0, 0, 6, 0},
		     {8, 0, 0, 0, 6, 0, 0, 0, 3},
		     {4, 0, 0, 8, 0, 3, 0, 0, 1},
		     {7, 0, 0, 0, 2, 0, 0, 0, 6},
		     {0, 6, 0, 0, 0, 0, 2, 8, 0},
		     {0, 0, 0, 4, 1, 9, 0, 0, 5},
		     {0, 0, 0, 0, 8, 0, 0, 7, 9}};
         
   //very hard
   /*
    int Sudoku[9][9] = {
      {8,0,0,0,0,0,0,0,0},
      {0,0,3,6,0,0,0,0,0},
      {0,7,0,0,9,0,2,0,0},
      {0,5,0,0,0,7,0,0,0},
      {0,0,0,0,4,5,7,0,0},
      {0,0,0,1,0,0,0,3,0},
      {0,0,1,0,0,0,0,6,8},
      {0,0,8,5,0,0,0,1,0},
      {0,9,0,0,0,0,4,0,0}
    };
    */
    
   //not possible
   /*
    int Sudoku[9][9]={
      {1,2,3,4,5,6,7,8,9},
      {0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0},
      {0,0,0,1,1,0,0,0,0},
      {0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,6},
      {3,7,9,0,0,0,0,0,4},
      {0,0,0,0,0,0,0,2,1}
    };*/


  printf("Input puzzle is:\n");
  print_sudoku(Sudoku);
  
  solve_sudoku(Sudoku);
  
  printf("Solution is:\n");
  print_sudoku(Sudoku);
  
}