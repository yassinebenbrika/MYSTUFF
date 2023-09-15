#include <stdio.h>

int main() {
    char character;

    printf("Enter a letter: ");
    scanf("%c", &character);

    if ((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z')) {
        if (character >= 'A' && character <= 'Z') {
            printf("The letter %c is uppercase.\n", character);
        } else {
            printf("The letter %c is lowercase.\n", character);
        }
    } else {
        printf("It's not a letter.\n");
    }

    return 0;
}
