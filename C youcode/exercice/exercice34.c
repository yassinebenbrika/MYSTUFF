#include <stdio.h>
#include <stdbool.h>
  int n,N[n], tmp,i,j;

int main() {
    int n;
    printf("How many numbers do you want to sort: ");
    scanf("%d", &n);

  
   

    for ( i = 0; i < n; i++) {
        printf("Enter a number: ");
        scanf("%d", &N[i]);
    }

      for ( i = 1 ; i < n; i++)
   {
    tmp=N[i];
    j=i-1;
    while (tmp<N[j] && j<=0)
    {
       N[j+1]=N[j];
       j--;
   }
    N[j+1]=tmp;
   }


    printf("****Sorted array**** ");
    for (int i = 0; i < n; i++) {
        printf("\n%d ", N[i]);
    }


    return 0;
}
