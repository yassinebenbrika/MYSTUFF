#include <stdio.h>

int main() {
  int N;
  float sum = 0;
  
  printf("Enter a number: ");
  scanf("%d", &N);

  for (int i = 1; i <= N; i++) {
    sum += 1.0 / i;
  }

  printf("s = %f", sum);
  
  return 0;
}
