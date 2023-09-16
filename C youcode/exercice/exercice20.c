#include <stdio.h>
#include <math.h>

int main() {
    int n, i, U, ui;
    
    printf("Enter the value of n: ");
    scanf("%d", &n);

    ui = 6;
    
    for (i = 0; i <= n; i++) {
        U = 4 * ui + 10;
        ui = U;
        printf("U%d = %d \n", i, ui);
    }
    
    return 0;
}
