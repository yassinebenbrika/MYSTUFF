#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for an item (product) in the pharmacy
struct Item {
    int id;
    char name[50];
    float price;
    int quantity;
};

// Function to generate a unique ID (placeholder implementation)
int generateUniqueID() {
    static int idCounter = 1;
    return idCounter++;
}

// Function to add an item to the inventory
void addItem(struct Item inventory[], int *itemCount) {
    struct Item newItem;

    printf("Enter product name: ");
    scanf("%s", newItem.name);
    printf("Enter price: ");
    scanf("%f", &newItem.price);
    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);

    // Assign a unique ID
    newItem.id = generateUniqueID();

    inventory[*itemCount] = newItem;
    (*itemCount)++;
    printf("Item added successfully.\n");
}

// Function to delete an item from the inventory by ID
void deleteItem(struct Item inventory[], int *itemCount, int itemID) {
    int index = -1;
    for (int i = 0; i < *itemCount; i++) {
        if (inventory[i].id == itemID) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        // Shift items to remove the deleted item
        for (int i = index; i < *itemCount - 1; i++) {
            inventory[i] = inventory[i + 1];
        }

        (*itemCount)--;
        printf("Item with ID %d deleted successfully.\n", itemID);
    } else {
        printf("Item with ID %d not found.\n", itemID);
    }
}

// Function to display the inventory
// Function to display the inventory
void displayInventory(const struct Item inventory[], int itemCount) {
    printf("Inventory:\n");
    printf("ID\tName\tPrice\tQuantity\n");

    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

int main() {
    struct Item inventory[100];  // Maximum of 100 items in inventory
    int itemCount = 0;

    int choice;
    int itemID;

    while (1) {
        printf("\nPharmacy Management System\n");
        printf("1. Add Item\n");
        printf("2. Delete Item\n");
        printf("3. Display Inventory\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(inventory, &itemCount);
                break;
            case 2:
    printf("Enter the ID of the item to delete: ");
    if (scanf("%d", &itemID) != 1) {
        printf("Invalid input. Please enter a valid item ID.\n");
        // Clear the input buffer
        while (getchar() != '\n');
    } else {
        deleteItem(inventory, &itemCount, itemID);
    }
    break;

            case 3:
                displayInventory(inventory, itemCount);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
