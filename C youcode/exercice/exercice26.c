#include <stdio.h>
#include <math.h>

void TM(int a) {
    if (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0))
        printf("This year has 366 days.\n");
    else
        printf("This year has 365 days.\n");
}

int main() {
    int n;
    char choose;
    
    do {
        printf("Enter a year: ");
        scanf("%d", &n);

        TM(n);

        printf("Do you want to continue (y/n): ");
        scanf(" %c", &choose); // Notice the space before %c to consume the newline character.

    } while (choose == 'y' || choose == 'Y');

    return 0;
}
