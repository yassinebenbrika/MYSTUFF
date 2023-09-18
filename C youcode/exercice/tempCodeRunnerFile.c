#include <stdio.h>
#include<stdbool.h>
int i,n,N[5],temp;
bool permut;
int main(){
     for ( i = 0; i < 5; i++)
     {
        printf("Enter a number  : ");
    scanf("%d", &N[i]);
 for(i=0;i<=n-1;i++){
    permut=0;   
    for ( i = 0; i <=n-2; i++)
    {
      N[i]=temp;
      temp=N[i+1];
 permut=1;
    }
    
 }
     }


     
}

    
