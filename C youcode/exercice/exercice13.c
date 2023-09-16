#include <stdio.h>

int main() {
  int N,i,sum;
   printf("enter a number : ");
   scanf("%d",&N);
    for(i=0;i<=10;i++){
        sum=N+i;
        printf(" %d ",sum);
    }
    return 0;
}
