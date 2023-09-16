#include <stdio.h>

float r; // Declare 'r' as a global variable
const float pi = 3.14;

// Calculate surface area
float surface() {
    return pi * r * r;
}

// Calculate diameter
float diameter() {
    return 2 * r;
}

// Calculate perimeter (circumference)
float perimeter() {
    return 2 * pi * r;
}

int main() {
    printf("Enter the radius: ");
    scanf("%f", &r);

    float Surface = surface();
    float Diameter = diameter();
    float Perimeter = perimeter();

    printf("The surface area is %f\n", Surface);
    printf("The diameter is %f\n", Diameter);
    printf("The perimeter is %f\n", Perimeter);

    return 0;
}
