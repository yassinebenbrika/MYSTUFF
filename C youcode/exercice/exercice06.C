#include <stdio.h>

int main() {
    int F, N; // Use float for F and N
    printf("Enter your age: ");
    scanf("%d", &N); // Use %f for reading a float

    if (N <=7 && N >= 6) 
      printf("tu es pussin ");
    else if (N <=9 && N >= 8)
      printf("tu es pupille ");
    else if (N <=11 && N >= 10)
      printf("tu es minime ");
      else
      printf("tu es cadet ");
    return 0;
}
