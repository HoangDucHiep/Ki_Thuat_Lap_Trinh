#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Pos{
  int x;
  int y;
}*pos;

void input(int *n){
  FILE *f;
  if((f = fopen("input.txt", "r")) == NULL){
    printf("Error!!");
    exit(EXIT_FAILURE);
  }
  fscanf(f, "%d", n);
  pos = (struct Pos*)malloc(*n * sizeof(struct Pos));
  for(int i = 0; i < *n; i++){
    fscanf(f, "%d%d", &pos[i].x, &pos[i].y);
  }
  fclose(f);
}

void disToXAxis(int n){
  for(int i = 0; i < n; i++){
    printf("Khong cach cua diem (%d,%d) den truc hoanh la: %d\n",pos[i].x, pos[i].y, abs(pos[i].y));
  }
}

float len(struct Pos a, struct Pos b){
   return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y, 2));
}

void findMaxlen(int n){
  float max = len(pos[0], pos[1]);
  int po1 = 0, po2 = 1;
  
  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
      float temp = len(pos[i], pos[j]);
      if(max < temp){
        max = temp;
        po1 = i;
        po2 = j;
      }
    }
  }
  printf("Doan thang co do dai dai nhat la doan thang noi 2 diem (%d,%d) và (%d,%d) va co do dai: %.2f", pos[po1].x, pos[po1].y, pos[po2].x, pos[po2].y, max);
}


int main(void) {
  int n;
  input(&n);
  disToXAxis(n);
  findMaxlen(n);
}