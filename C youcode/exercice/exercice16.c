#include <stdio.h>
#include <math.h>

int main() {
  int N,i;
  float f;
  
  printf("Enter a number: ");
  scanf("%d", &N);

 while(i<=N) {
      f=f+pow(i,2);
      
      i++;
  }
  printf("%f",f);
  
  return 0;
}
