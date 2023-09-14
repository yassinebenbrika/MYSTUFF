#include <stdio.h>

int main() {
    float a, b, c,d,e;

    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);

    if (a < 0 && b < 0  || 0<a && 0<b) {
        c = b;
        b = a;
        a = c;
        printf("a is %f and b is %f", a, b);
    } else if (a > 0 && b < 0  || a<0 && b>0) {
    d=a+b;
    e=a*b;
    a=d;
    b=e;
    printf("the sum of a and b is %f and the multiplication is %f ",d ,e);
    } else {
        printf("Incorrect value");
    }

    return 0;
}
