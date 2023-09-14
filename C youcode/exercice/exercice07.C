#include <stdio.h>

int main() {
    float N1, N2, N3, Avrg;
    
    printf("Enter the first note :  ");
    scanf("%f", &N1);

    printf("Enter the second note :  ");
    scanf("%f", &N2);
    
    printf("Enter the third note :  ");
    scanf("%f", &N3);
   
    if (N1 >= 0 && N1 <= 20 && N2 >= 0 && N2 <= 20 && N3 >= 0 && N3 <= 20) {
        Avrg = (N1 + N2 + N3) / 3;
        
        if (Avrg < 10 && Avrg >= 0)
            printf("Vous avez échoué ");
        else if (Avrg < 14 && Avrg >= 12)
            printf("Ton mention est bien ");
        else if (Avrg < 12 && Avrg >= 10)
            printf("Ton mention est passable ");
        else if (Avrg >= 16 && Avrg <= 20)
            printf("Ton mention est très bien ");
        else
            printf("incorrect values");
    } else {
        printf("Incorrect values");
    }
    
    return 0;
}
