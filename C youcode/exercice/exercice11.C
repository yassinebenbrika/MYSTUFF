#include <stdio.h>
int main (){
    int i,m,n; 
    printf("enter a number : ")
    scanf("%d",&n);
    for (i = 0; i <= 10; i++) {
      m=n*i
      printf("%d*%d=%d",n,i,m);
    }

    return 0;
}
