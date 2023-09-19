#include <stdio.h>
#include <stdbool.h>

char continueChoice;
int choose;
int n;
int target;
int N[100];

void bubbleSort() {
    bool permut;
    int temp;
    do {
        permut = false;
        for (int i = 0; i < n - 1; i++) {
            if (N[i] > N[i + 1]) {
                temp = N[i];
                N[i] = N[i + 1];
                N[i + 1] = temp;
                permut = true;
            }
        }
    } while (permut);
}

int linearSearch() {
    for (int i = 0; i < n; i++) {
        if (N[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {

        printf("How many numbers do you want to sort: ");
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            printf("Enter a number: ");
            scanf("%d", &N[i]);
        }
    do {
        printf("1 - Sort the array\n");
        printf("2 - Search for an element's index\n");
        printf("Enter your choice: ");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                bubbleSort();
                printf("Sorted array: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", N[i]);
                }
                printf("\n");
                break;
            case 2:
                printf("Enter a number to search for: ");
                scanf("%d", &target);

                int index = linearSearch();

                if (index != -1) {
                    printf("Element %d found at index %d\n", target, index);
                } else {
                    printf("Element %d not found in the array\n", target);
                }
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }

        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &continueChoice);
    } while (continueChoice == 'y' || continueChoice == 'Y');

    return 0;
}
