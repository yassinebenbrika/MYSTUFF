#include <stdio.h>
#include <math.h>

int main() {
  int N,i;
  float f;
  do{
       printf("Enter a number: ");
       scanf("%d", &N);
  }while(N<=0);
  for(i=1;i<=N;i++){
      if(N%i==0)
        printf("this number %d is a divition\n",i);
   
  }
  return 0;
}
