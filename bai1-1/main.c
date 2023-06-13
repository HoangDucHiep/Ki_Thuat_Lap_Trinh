#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void input(int *n, int *m, int **p,  int **q){
  FILE *f = fopen("input.txt", "r");
  fscanf(f, "%d%d", n, m);
  *p = (int *)calloc(*n , sizeof(int));
  *q = (int *)calloc(*m , sizeof(int));
  int *i;
  
  for(i = *p; i < *p + *n; i++){
    fscanf(f, "%d", i);
  }
  for(i = *q; i < *q + *m; i++){
    fscanf(f, "%d", i);
  }
    fclose(f);
}

int* heSo(int n, int m, int *p,  int *q){
  int longLen = n > m ? n : m;
  int shortLen = n < m ? n : m;
  int *heso = (int *)malloc(sizeof(int) * longLen);
  int i = 0;
  for(i = 0; i < shortLen; i++){
    (heso)[i] = p[i] - q[i];
  }
  if(longLen == n){
    (heso)[i] = p[i] - 0;
    if(i < longLen) i++;
  }else {
    (heso)[i] = 0 - q[i];
    if(i < longLen) i++;
  }
  return heso;

}

  
float tinhGTham(int n, int *p, int d){
  int ketQua = 0;
  for(int i = 0; i < n; i++){
    ketQua += p[i]*pow(d,i);
  }
  return (float)ketQua;
}



int main(void) {
  int n, m;
  int *p;
  int *q;
  input(&n, &m, &p, &q);
  int d1, d2;
  printf("Nhap d1, d2: ");
  scanf("%d%d", &d1, &d2);
  //b
  printf("S = %.2f", tinhGTham(n, p, d1) / tinhGTham(m, q, d2));
  int len = n > m ? n : m;
  int *hs = heSo(n, m, p, q);
  printf("\nHe so jj day: ");
  for(int i = 0; i < len; i++){
    printf("%d ", hs[i]);
  }
}