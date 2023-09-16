#include <stdio.h>
int a;
int NBR;
void TM(){
  int d=a;
  NBR=0;
  if (d==0){
    NBR==1;
    printf("this number has %d",NBR);

  }
  else {
    do{
       d= d /10;
       NBR++;
    }while (d!=0);
    
  }
}
int main() {
    printf("enter a number : ");
    scanf("%d",&a);
    TM();
    printf("this number has %d number.",NBR);
     return 0;      
    }
    
