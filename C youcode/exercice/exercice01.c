#include<stdio.h>
int main (){

  float A,B;
     printf("enter the A :");
     scanf("%f",&A);
     printf("enter the B :");
     scanf("%f",&B);
  if ( B!=0)
     printf("the divition tha numbers A and B is %.1f ",A/B);
  else 
     printf("tis divition is undefined ");

  return 0;
}