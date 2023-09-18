#include <stdio.h>
#include <stdbool.h> 
int main()
{
    int choice, balance = 0, withdraw, deposit;
    char continueChoice;
    int password = 1234; 
    int enteredPassword;
    printf("Welcome to Barid Bank ATM\n");
    printf("Please enter the initial password: ");
    scanf("%d", &password);
    do
    {
        printf("\nMenu:\n");
        printf("1. Balance Inquiry\n");
        printf("2. Withdrawal\n");
        printf("3. Deposit\n");
        printf("4. Change Password\n");
        printf("5. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Your balance is %d\n", balance);
            break;
        case 2:
            printf("How much do you want to withdraw?\n");
            scanf("%d", &withdraw);
            if (withdraw <= balance)
            {
                balance -= withdraw;
                printf("Withdrawal successful. Your balance is: %d\n", balance);
            }
            else
            {
                printf("Insufficient balance.\n");
            }
            break;
        case 3:
            // Implement deposit logic
            printf("How much do you want to deposit?\n");
            scanf("%d", &deposit);
            balance += deposit;
            printf("Deposit successful. Updated balance: %d\n", balance);
            break;
        case 4:
            printf("Enter the current password: ");
            scanf("%d", &enteredPassword);
            if (enteredPassword == password)
            {
                printf("Enter the new password: ");
                scanf("%d", &password);
                printf("Password changed successfully.\n");
            }
            else
            {
                printf("Incorrect password. Password change failed.\n");
            }
            break;
        case 5:
            printf("Thank you for using XYZ Bank ATM. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
        if (choice != 5)
        {
            printf("Do you want to continue (y/n)? ");
            scanf(" %c", &continueChoice);
        }
    } while (choice != 5 && (continueChoice == 'y' || continueChoice == 'Y'));
    return 0;
}


