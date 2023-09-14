#include <stdio.h>
#include <math.h>
int main() {
    int a, b, c, delta,x1,x2,x;
        printf("type the number a : ");
        scanf("%d",&a);
        
        printf("type the number b : ");
        scanf("%d",&b);
        
        printf("type the number c : ");
        scanf("%d",&c);
    delta=pow(b,2)-4*a*c;
    int S=sqrt(delta);
    if (delta<0)
        printf("this is unaccetaple");
    else if (delta>0){
    x1=(-b-S)/2*a;
    x2=(b-S)/2*a;
        printf("this equition have two solutions are (%d , %d )",x1, x2);
    }
    else {
   x=-b/2*a;
    printf("this equition has only one solution is %d",x);
    }

    return 0;
}
