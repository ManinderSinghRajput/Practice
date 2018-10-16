#include <stdio.h>
#include <pthread.h>


//Declaring this globally as they need to be used by thread callbak function matMult

int M = 4, P = 3, N = 4;
int A[4][3] = {{2,-3,1},{1,0,4},{5,2,-1},{0,3,6}};
int B[3][4] = {{5,1,-1,0},{-4,6,2,7},{5,1,0,3}};
int C[4][4] = {0};

void* matMult(void *row) 
{ 
  int i, j, k, *row_no = (int*)row;
  for (int k = 0; k < P; k++)  
    for (int j = 0; j < N; j++)  
      C[*row_no][j] += A[*row_no][k] * B[k][j]; 
} 
 
int main()
{

  int i, j;

  //declaring four threads that is equal to no of rows
  pthread_t threads[M]; 

  //Each thread will call back matMult callback function defined above 
  int row_no[4] = {0,1,2,3};
  for (i = 0; i < M; i++) 
  { 
    pthread_create(&threads[i], NULL, matMult, (void*)(&(row_no[i]))); 
  } 

  // As mentioned in question parent will wait for all threads before displaying the result 
  for (i = 0; i < M; i++)  
    pthread_join(threads[i], NULL);
 
  printf("Product of the matrices:\n");
 
  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++)
      printf("%d\t", C[i][j]);
 
    printf("\n");
  }
 
  return 0;
}
