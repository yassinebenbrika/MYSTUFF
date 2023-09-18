#include <stdio.h>

int main() {
    int i;
    int N[3];
if (N[i]<=20)
{
   

    for (i = 0; i < 3; i++) {
        printf("Enter the data for student number %d: ", i + 1);
        scanf("%d", &N[i]);
    }}
else
printf("sorry");
 int s=0;
   for (i = 0; i < 3; i++){
   s=s+N[i];
    }
 int m=s/3;
 printf("the avrg is %d",m);
    return 0;
}
