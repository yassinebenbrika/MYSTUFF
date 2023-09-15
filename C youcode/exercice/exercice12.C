#include <stdio.h>
#include <stdbool.h>
void bruh (int n) {
    int i,est_premier=0;
    for(i=2;i<n/2;i++){
        if (n%i==0){
            est_premier=0;
            break;
        }
        if (est_premier=0){
            printf("this number is a premier");
        }
        else{
             printf("this number is a not  premier");
        }
    }
}
int main (){
 int n;
 printf(" enter a number to check if the number is a premier or not : ") ;
  scanf("%d",&n);
 bruh(n);
    return 0;
}