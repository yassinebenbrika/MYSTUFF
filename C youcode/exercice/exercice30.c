#include <stdio.h>
#include<math.h>
float a,b,c,x,x1,x2;
void T(){
     
    printf("Enter a number a : ");
    scanf("%f", &a);
 printf("Enter a number b : ");
    scanf("%f", &b);
 printf("Enter a number c : ");
    scanf("%f", &c);
}
void M( ){
    float delta=pow(b,2)-4*a*c;
    if (delta==0)
    {
        x=-b/(2*a);
        printf("x=%f",x);
    }
    else if (delta>0){
   x1 = (-b + sqrt(delta)) / (2 * a); // Corrected the formula
x2 = (-b - sqrt(delta)) / (2 * a); // Corrected the formula

   printf("x1=%f\nx2=%f",x1,x2);
    }
    else
 printf("undfined value .");
}

int main() {
   T();
   M();
   

    return 0;
}
