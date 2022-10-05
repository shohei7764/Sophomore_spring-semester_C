#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#define L 4
#define M 4
#define N 1


/* 行列の積の計算 */
void matrix_mult( double **a, double **b, double **c, int l, int _l, int m, int _m, int n, int _n);

int main(void)
{
  FILE *fin;
  double **a, **b, **c; 
  int i, j;

  a = dmatrix(1, L, 1, M); 
  b = dmatrix(1, M, 1, N); 
  c = dmatrix(1, L, 1, N); 

  
  /* ファイルのオープン */
  if ( (fin = fopen( "A.dat", "r")) == NULL ){
    printf("ファイルが見つかりません : data_A.dat \n");
    exit(1);
  }

  //matrix_A
  for ( i = 1 ; i <= L ; i++){
    for ( j = 1 ; j <= M ; j++)
    {
      fscanf(fin, "%lf", &a[i][j]);
    }
  }
  fclose(fin);

  /* ファイルのオープン */
  if( (fin = fopen( "b.dat", "r")) == NULL ){
    printf("ファイルが見つかりません : data_b.dat \n");
    exit(1);
  }

  //matrix_B
  for ( i = 1 ; i <= M ; i++){
    for ( j = 1 ; j <= N ; j++)
    {
      fscanf(fin, "%lf", &b[i][j]);
    }
  }
  fclose(fin);

  /* matrix_mult */
  matrix_mult( a, b, c, 1, L, 1, M, 1, N);

  /* result */
  printf("Ab =\n");   
  for ( i = 1 ; i <= L ; i++)        
  {
    for ( j = 1 ; j <= N ; j++)
    printf("%lf  ", c[i][j]);
    printf("\n");
  }

  /* 行列領域の開放 */
  free_dmatrix( a, 1, L, 1, M);
  free_dmatrix( b, 1, M, 1, N);
  free_dmatrix( c, 1, L, 1, N);

  return 0;
}


void matrix_mult( double **a, double **b, double **c, int l, int _l, int m, int _m, int n, int _n)
{
  int i, j, k; 
  for ( i = l  ; i <= _l ; i++)         
  {
    for ( j = n ; j <= _n ; j++)
    {
      c[i][j]=0.0;                   
      for ( k = m ; k <= _m ; k++)     
      {
        c[i][j] += a[i][k] *  b[k][j];
      } 
    }
  }
}

