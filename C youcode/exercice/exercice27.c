#include <stdio.h>
int a;
void TM(){
      int check = 1;
       for (int i = 2; i <= a/2; i++)
     {
        if (a%i==0){
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

}
int main() {
    printf("enter a number : ");
    scanf("%d",&a);
    TM(a);
     return 0;      
    }
    
