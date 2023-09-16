#include <stdio.h>

int main() {
    int n, i, u0, U1, U2;
   do{ 
    printf("Enter the value of n: ");
    scanf("%d", &n);
   }while(n<2);
    u0 = 0;
    U1 = 1;
    
    for (i = 0; i <= n; i++) {
        U2 = u0 + U1;
        u0 = U1;
        U1 = U2;
        printf("U%d = %d \n", i, U2);
    }
    
    return 0;
}
