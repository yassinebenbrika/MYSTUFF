#include <stdio.h>

int main() {
    int  i,n,check = 1;
    printf("enter a number : ");
    scanf("%d",&n);
    for ( i = 2; i <= n/2; i++)
    {
        if (n%i==0){
            check=0;
            break;
            }
        }
        if (check==1)
        {
            printf("this number is prime");
        }
        else 
        printf("this number isn't prime ");

     return 0;      
    }
    
