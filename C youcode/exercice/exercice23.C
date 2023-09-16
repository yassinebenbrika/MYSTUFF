#include <stdio.h>
void TM (int a){
      printf("the table of multiplication for %d:\n", a);     
  for ( int i = 0; i <=10; i++)
     {
       printf("%d x %d= %d\n",a,i,a*i);
     }
     

}
int main() {
    int  i,n;
    printf("enter a number : ");
    scanf("%d",&n);
    for(n=1;n<=10;n++) {
      TM(n);
    }
     

     return 0;      
    }
    
