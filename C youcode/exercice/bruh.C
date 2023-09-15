#include <stdio.h>
#include <string.h>

int main() {
    int year, answer;
    char choice[20];

    printf("Enter the year: ");
    scanf("%d", &year);

    printf("Enter your choice: ");
    scanf("%s", choice);
    

    if (strcmp(choice, "months") == 0) {
        answer = year * 12;
        printf("%d months\n", answer);
    } else if (strcmp(choice, "days") == 0) {
        answer = year * 1;
        printf("%d days\n", answer);
    } else if (strcmp(choice, "hours") == 0) {
        answer = year * 365 * 24;
        printf("%d hours\n", answer);
    } else if (strcmp(choice, "minutes") == 0) {
        answer = year * 365 * 24 * 60;
        printf("%d minutes\n", answer);
    } else if (strcmp(choice, "seconds") == 0) {
        answer = year * 365 * 24 * 60 * 60;
        printf("%d seconds\n", answer);
    } else {
        printf("This option is not available.\n");
    }

    return 0;
}
