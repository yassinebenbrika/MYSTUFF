#include <stdio.h>

int main() {
    float a, b;

    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);

    if (a < b)
        printf("The max is %.1f\n",b);
    else if (b < a)
        printf("The max is %.1f",a);
    else
        printf("Both numbers are equal\n");

    return 0;
}

