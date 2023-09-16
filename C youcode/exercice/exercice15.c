#include <stdio.h>
#include <math.h>

int main() {
  int N;
  float sum = 0;
  
  printf("Enter a number: ");
  scanf("%d", &N);

  for (int i = 1; i <= N; i++) {
    sum += pow(10, i);
  }

  printf("s = %1.f", sum);
  
  return 0;
}

