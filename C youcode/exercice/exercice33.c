#include <stdio.h>
#include <math.h> 

int main() {
    int N, num, digit, sum = 0;
    
    printf("Enter a number to check if it is an Armstrong number: ");
    scanf("%d", &N);

    num = N; 
    
    while (N > 0) {
       
        digit = N % 10; 
        sum =sum+pow(digit, 3); 
        N /= 10; 
    }

    
    if (num == sum) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }

    return 0;
}
