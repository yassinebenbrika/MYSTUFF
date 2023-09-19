#include <stdio.h>
#include <stdbool.h>

int main() {
  int i,n, temp;
    bool permut;
printf("how many number do you want to sort :");
scanf("%d",&n);
     int N[n];
    for ( i = 0; i < n; i++) {
        printf("Enter a number: ");
        scanf("%d", &N[i]);
}
    do{
    permut=false;
 for( i=0;i<n-1;i++){
       if(N[i]>N[i+1]){
           temp=N[i];
           N[i]=N[i+1];
           N[i+1]=temp;
           permut=true;
       }
       
    }
}while(permut);



    // Output the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", N[i]);
    }
    printf("\n");

    return 0;
}
