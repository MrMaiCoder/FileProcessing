#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** makeMatrix(int** a, int** matrix, int i, int new_i, int n);

double compute_det(int **a, int n) {
  int changeSign = 1;
  double sum = 0;

  if (n==1){
    return a[0][0];
  }else{
    int** new_matrix = (int**)malloc(sizeof(int *) * n-1);
    for (int i=0; i < n; i++){
      new_matrix[i] = (int *)malloc(sizeof(int) * n-1);
    }
    for (int column=0; column < n; column++){
      int new_col = 0;
      new_matrix = makeMatrix(a, new_matrix, column, new_col, n); 
      
    sum+=(changeSign * a[column][0] * compute_det(new_matrix, n-1));
    changeSign*=(-1);
    }
  }
  return sum;
}

int** makeMatrix(int** a, int** matrix, int column, int new_col, int n){
  for (int row=0; row < n; row++){
    if (column != row){
      for (int new_row=1; new_row < n; new_row++){
        matrix[new_col][new_row-1] = a[row][new_row];
      }
      new_col++;
    }
  }

  return matrix;
}



/*
TEST: ./det < det.in
OUTPUT:
-105.00000
*/
int main(void) {
  int n;

  scanf("%d", &n);

  int** matrix = (int **)malloc(sizeof(int*) * n);
  for (int i=0; i < n; i++){
      matrix[i] = (int *)malloc(sizeof(int) * n);
  }

  for (int i=0; i < n; i++){
    for (int j=0; j < n; j++){
      scanf("%d", &matrix[i][j]);
    }
  }

  printf("%f \n",compute_det(matrix, n));



}
