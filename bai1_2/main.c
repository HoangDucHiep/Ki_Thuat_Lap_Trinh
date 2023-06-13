#include <stdio.h>
#include <stdlib.h>

void input(int *m, int *n, float ***p) {
  FILE *f;
  if ((f = fopen("input.txt", "r")) == NULL) {
    printf("Loi");
    exit(EXIT_FAILURE);
  }
  fscanf(f, "%d%d", m, n);
  (*p) = (float **)malloc(*m * sizeof(float));
  for (int i = 0; i < *m; i++) {
    (*p)[i] = (float *)malloc(*n * sizeof(float));
    for (int j = 0; j < *n; j++) {
      fscanf(f, "%f", &(*p)[i][j]);
    }
  }
  fclose(f);
}

float negMean(float **p, int m, int n) {
  float sum = 0;
  float count = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (p[i][j] < 0) {
        sum += p[i][j];
        count++;
      }
    }
  }
  return count > 0 ? sum / count : 0;
}

// c
float* max(float **p, int m, int n) {
  float *num = (float*)calloc(3, sizeof(float));
  int count = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (p[i][j] < 0) {
        count++;
        num[0] = p[i][j];
        num[1] = i;
        num[2] = j;
        break;
      }
    }
  }
  if (count == 0)
    return num;

  for (int i = num[1]; i < m; i++) {
    for(int j = 0; j < n; j++){
      if(p[i][j] < 0 && p[i][j] > num[0]){
        num[0] = p[i][j];
        num[1] = i;
        num[2] = j;
      }
    }
  }
  return num;
}


  int main(void) {
    int m, n;
    float **p = NULL;
    input(&m, &n, &p);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        printf("%.1f ", p[i][j]);
      }
      printf("\n");
    }
    float mean = negMean(p, m, n);
    if (mean != 0)
      printf("TBC cac phan tu am: %.2f", mean);
    else
      printf("Khong co so am");

    float *Max = max(p,m,n);
    if(Max[0] != 0){
      printf("Gia tri am lon nhat la %.1f tai vi tri (%.0f,%.0f)", Max[0], Max[1], Max[2]);
    }
  }