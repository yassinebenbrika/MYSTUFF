#include <stdio.h>
#include <math.h>

int main() {
  int N,i,j;
  float f;
  
  printf("Enter a number: ");
  scanf("%d", &N);
  f=0;
  j=1;
 for (i=0;i<=N;i++){
     f=f+pow(j,2);
     j=j+2;
 }
  printf("%1.f",f);
  
  return 0;
}
