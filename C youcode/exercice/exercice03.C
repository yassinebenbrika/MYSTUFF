#include <stdio.h>

int main() {
    float a;

    printf("Enter number: ");
    scanf("%f",&a);
    if (a <0)
    printf("the number %.1f is negative",a);
    else if (0<a)
    printf("the number %.1f is positive ",a);
    else 
    printf("the number %.1f is null",a);
    
    return 0;
}

