#include <stdio.h>

int main() {
    float F, N; // Use float for F and N
    printf("Enter how much do you need: ");
    scanf("%f", &N); // Use %f for reading a float

    if (N < 10 && N > 0) {
        F = N * 0.30;
        printf("The price is %.2f", F); // Use %.2f to print two decimal places
    } else if (N < 20 && N >= 10) {
        F = 10 * 0.30 + (N - 10) * 0.25;
        printf("The price is %.2f", F);
    } else {
        F = 10 * 0.30 + 10 * 0.25 + (N - 30) * 0.20;
        printf("The price is %.2f", F);
    }
    
    return 0;
}
