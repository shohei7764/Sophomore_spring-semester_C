double *dvector(int i, int j) /* a[i]～a[j]の領域を確保 */
{
    double *a;
    
    if ( (a = (double *)malloc( ((j-i+1)*sizeof(double))) ) == NULL )
    {
        printf("メモリが確保できません(from dvector) \n");
        exit(1);
    }
    
    return(a-i);
}

void free_dvector(double *a, int i)
{
    free( (void *)(a + i) );  /* (void *)型へのキャストが必要 */
}

double **dmatrix(int nr1, int nr2, int nl1, int nl2)
{
  int i, nrow, ncol; 
  double **a; 

  nrow = nr2 - nr1 + 1 ; /* 行の数 */
  ncol = nl2 - nl1 + 1 ; /* 列の数 */

  /* 行の確保 */
  if ( ( a = (double **)malloc( nrow*sizeof(double *) ) ) == NULL ) 
  {
    printf("メモリが確保できません(行列a)\n");
    exit(1);
  }
  a = a - nr1; /* 行をずらす */

  /* 列の確保 */
  for( i=nr1; i<=nr2; i++) a[i] = (double *)malloc(ncol*sizeof(double)); 
  for( i=nr1; i<=nr2; i++) a[i] = a[i]-nl1;             /* 列をずらす */
  
  return(a);
}

void free_dmatrix(double **a, int nr1, int nr2, int nl1, int nl2)
{
  int i;

  /* メモリの解放  */
  for ( i = nr1 ; i <= nr2 ; i++) free((void *)(a[i]+nl1));
  free((void *)(a+nr1));
}


