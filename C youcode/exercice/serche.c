#include <stdio.h>

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]); 
    int target = 6; 
    int found = 0;

   
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            found = 1;
            printf("Element %d found at index %d\n", target, i);
            break;
    }
    }
  
    if (found=0) {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
