#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tools.h"

#define M 5 
#define N 5 


/* フロベニウスノルム */
double fnorm( double **a, int m, int _m, int n, int _n);


int main(void)
{
  FILE *fin;
  int i, j;
  double **a;
  
  a = dmatrix(1, M, 1, N);
  
  /* ファイルのオープン */
  if ( (fin = fopen( "A2.dat", "r")) == NULL ){
    printf("ファイルが見つかりません : data_a.dat \n");
    exit(1);
  }

  //行列A2の定義
  for ( i = 1 ; i <= M ; i++)
  {
    for ( j = 1 ; j <= N ; j++)
    {
      fscanf(fin, "%lf", &a[i][j]);
    }
  }
  fclose(fin);

  printf("行列A2のフロベニウスノルムは%f\n", fnorm( a, 1, M, 1, N) );

  free_dmatrix( a, 1, M, 1, N);

  return 0;
}

/* フロベニウスノルムの計算 */
double fnorm( double **a, int m, int _m, int n, int _n)
{
  int i, j;
  double tmp;
  double s=0.0;

  for( i = m; i <= _m; i++)
  for ( j = n; j <= _n; j++)
    {
      tmp = pow(a[i][j], 2.0);
      s += tmp;
    }

  return sqrt(s);
}


