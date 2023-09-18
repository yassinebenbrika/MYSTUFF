#include <stdio.h>
#include <stdbool.h>

int main() {
    int i, N[5], temp;
    bool permut;

    
    for (i = 0; i < 5; i++) {
        printf("Enter a number: ");
        scanf("%d", &N[i]);
    }

    do {
        permut = false;
        for (i = 0; i < 5 - 1; i++) {
            if (N[i] > N[i + 1]) {
                temp = N[i];
                N[i] = N[i + 1];
                N[i + 1] = temp;
                permut = true;
            }
        }
    } while (permut);

    // Output the sorted array
    printf("Sorted array: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", N[i]);
    }
    printf("\n");

    return 0;
}
