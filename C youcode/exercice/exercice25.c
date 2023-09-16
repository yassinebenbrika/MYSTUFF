#include <stdio.h>
#include <math.h>
void TM (int a){
       if (a%4==0 && a%100!=0 )
          printf("this year has 366 days ");
       else
        printf("this year has 365 days ");
      
               }
int main() {
    int  i,n;
    printf("enter a year : ");
    scanf("%d",&n);
    
      TM(n);
    
     

     return 0;      
    }
    
