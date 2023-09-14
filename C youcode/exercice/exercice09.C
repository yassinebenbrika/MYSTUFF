#include <stdio.h>

int main() {
  int age;
  char sexe;

  printf("Enter your age: ");
  scanf("%d", &age);

  printf("Enter your sex (H or F): ");
  scanf(" %c", &sexe);  // Note the space before %c to consume any leading whitespace

  if (age >= 20 && sexe == 'H')
    printf("You are a grown man, you have to pay the tax");
  else if (age >= 18 && age < 35 && sexe == 'F')
    printf("You are a strong independent woman, you have to pay the tax");
  else
    printf("You don't have to pay the tax");

  return 0;
}



