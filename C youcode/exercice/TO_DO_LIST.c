#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Maximum number of tasks


// Structure to represent a task
struct Task {
    int id;
    char title[100];
    char description[500];
    char deadline[20]; // Format: YYYY-MM-DD
    char status[50];
};

// Function to display the menu options
void displayMenu() {
    printf("==== To-Do List Menu ====\n");
    printf("1. Add a new task\n");
    printf("2. Display tasks\n");
    printf("3. Modify a task\n");
    printf("4. Delete a task by ID\n");
    printf("5. Search for tasks\n");
    printf("6. Display statistics\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

// Function to add a new task
// Function to add a new task

int addTask(struct Task tasks[], int numTasks) {
    char continueInput;
    
    do {
        if (numTasks >= 100) {
            printf("Maximum number of tasks reached.\n");
            return numTasks;
        }

        printf("Enter task details:\n");

        // Increment the ID for the new task
        int newId = numTasks + 1;

        // Set the task ID
        tasks[numTasks].id = newId;

        printf("Title: ");
        scanf(" %[^\n]", tasks[numTasks].title); // Read until newline
        printf("Description: ");
        scanf(" %[^\n]", tasks[numTasks].description); // Read until newline
        printf("Deadline (YYYY-MM-DD): ");
        scanf("%s", tasks[numTasks].deadline);

        printf("Status:\n");
        printf("1. À réaliser\n");
        printf("2. En cours de réalisation\n");
        printf("3. Finalisée\n");
        printf("Enter your choice: ");
        
        int statusChoice;
        scanf("%d", &statusChoice);

        switch (statusChoice) {
            case 1:
                strcpy(tasks[numTasks].status, "À réaliser");
                break;
            case 2:
                strcpy(tasks[numTasks].status, "En cours de réalisation");
                break;
            case 3:
                strcpy(tasks[numTasks].status, "Finalisée");
                break;
            default:
                printf("Invalid choice.\n");
                return numTasks; // Return without adding the task
        }
        
        printf("Adding task successfully.\n");

        numTasks++; // Increment the task count

        printf("Do you want to continue (y/n): ");
        getchar(); // Consume the newline character
        scanf("%c", &continueInput);
    } while (continueInput == 'y' || continueInput == 'Y');

    return numTasks; // Return the updated task count
}


// Function to display all tasks sorted by title
void displayTasksByTitle(struct Task tasks[], int numTasks) {
    if (numTasks <= 0) {
        printf("No tasks to display.\n");
        return;
    }

    // Sort the tasks using a simple bubble sort algorithm based on titles
    for (int i = 0; i < numTasks - 1; i++) {
        for (int j = 0; j < numTasks - i - 1; j++) {
            if (strcmp(tasks[j].title, tasks[j + 1].title) > 0) {
                // Swap tasks[j] and tasks[j + 1]
                struct Task temp;
                temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }

    printf("Tasks sorted by title:\n");
    for (int i = 0; i < numTasks; i++) {
        printf("ID: %d\n", tasks[i].id);
        printf("Title: %s\n", tasks[i].title);
        printf("Description: %s\n", tasks[i].description);
        printf("Deadline: %s\n", tasks[i].deadline);
        printf("Status: %s\n", tasks[i].status);
        printf("\n");
    }
}

// Function to display all tasks sorted by deadline
void displayTasksByDeadline(struct Task tasks[], int numTasks) {
    if (numTasks <= 0) {
        printf("No tasks to display.\n");
        return;
    }

    // Sort the tasks using a simple bubble sort algorithm based on deadlines
    for (int i = 0; i < numTasks - 1; i++) {
        for (int j = 0; j < numTasks - i - 1; j++) {
            if (strcmp(tasks[j].deadline, tasks[j + 1].deadline) > 0) {
                // Swap tasks[j] and tasks[j + 1]
                struct Task temp;
                temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }

    printf("Tasks sorted by deadline:\n");
    for (int i = 0; i < numTasks; i++) {
        printf("ID: %d\n", tasks[i].id);
        printf("Title: %s\n", tasks[i].title);
        printf("Description: %s\n", tasks[i].description);
        printf("Deadline: %s\n", tasks[i].deadline);
        printf("Status: %s\n", tasks[i].status);
        printf("\n");
    }
}

bool isNearDeadline(const char deadline[]) {
    struct tm current_tm;
    struct tm task_tm;

    time_t current_time = time(NULL);
    current_tm = *localtime(&current_time);

    int task_year, task_month, task_day;
    sscanf(deadline, "%d-%d-%d", &task_year, &task_month, &task_day);
    task_tm.tm_year = task_year - 1900;
    task_tm.tm_mon = task_month - 1;
    task_tm.tm_mday = task_day;

    int days_difference = 0;

    time_t current_seconds = mktime(&current_tm);
    time_t task_seconds = mktime(&task_tm);

    days_difference = (int)difftime(task_seconds, current_seconds) / (60 * 60 * 24);

    return (days_difference <= 3 && days_difference >= 0);
}

int deleteTask(struct Task tasks[], int numTasks) {
    int taskId;
    printf("Enter the ID of the task to delete: ");
    scanf("%d", &taskId);

    int taskIndex = -1;

    // Find the task with the given ID
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].id == taskId) {
            taskIndex = i;
            break;
        }
    }

    if (taskIndex != -1) {
        // Shift remaining tasks to fill the gap
        for (int i = taskIndex; i < numTasks - 1; i++) {
            tasks[i] = tasks[i + 1];
        }

        printf("Task with ID %d deleted successfully.\n", taskId);
        return numTasks - 1; // Return the updated task count
    } else {
        printf("Task with ID %d not found.\n", taskId);
        return numTasks;
    }
}

// Function to search for tasks by ID or title
void searchTasks(struct Task tasks[], int numTasks) {
    int choice;
    printf("Search by:\n");
    printf("1. Task ID\n");
    printf("2. Task Title\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    getchar(); // Consume newline character

    switch (choice) {
        case 1: {
            int taskId;
            printf("Enter the ID of the task you want to search for: ");
            scanf("%d", &taskId);
            
            bool found = false;
            for (int i = 0; i < numTasks; i++) {
                if (tasks[i].id == taskId) {
                    printf("Task found:\n");
                    printf("ID: %d\n", tasks[i].id);
                    printf("Title: %s\n", tasks[i].title);
                    printf("Description: %s\n", tasks[i].description);
                    printf("Deadline: %s\n", tasks[i].deadline);
                    printf("Status: %s\n", tasks[i].status);
                    found = true;
                    break;
                }
            }

            if (!found) {
                printf("Task with ID %d not found.\n", taskId);
            }
            break;
        }
        case 2: {
            char searchTitle[100];
            printf("Enter the title of the task you want to search for: ");
            scanf(" %[^\n]", searchTitle);

            bool found = false;
            for (int i = 0; i < numTasks; i++) {
                if (strcmp(tasks[i].title, searchTitle) == 0) {
                    printf("Task found:\n");
                    printf("ID: %d\n", tasks[i].id);
                    printf("Title: %s\n", tasks[i].title);
                    printf("Description: %s\n", tasks[i].description);
                    printf("Deadline: %s\n", tasks[i].deadline);
                    printf("Status: %s\n", tasks[i].status);
                    found = true;
                }
            }

            if (!found) {
                printf("No tasks with title '%s' found.\n", searchTitle);
            }
            break;
        }
        default:
            printf("Invalid choice.\n");
    }
}

int main() {
    struct Task tasks[100]; // Assuming a maximum of 100 tasks
    int numTasks = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                numTasks = addTask(tasks, numTasks);
                break;
            case 2: {
                int displayChoice;
                printf("Display tasks by:\n");
                printf("1. Title\n");
                printf("2. Deadline\n");
                printf("Enter your choice: ");
                scanf("%d", &displayChoice);

                if (displayChoice == 1) {
                    displayTasksByTitle(tasks, numTasks);
                } else if (displayChoice == 2) {
                    displayTasksByDeadline(tasks, numTasks);
                } else {
                    printf("Invalid choice.\n");
                }
                break;
            }
            case 3:
                printf("Modify a task: Not implemented yet.\n");
                break;
            case 4:
                numTasks = deleteTask(tasks, numTasks);
                break;
            case 5:
                searchTasks(tasks, numTasks);
                break;
            case 6:
                printf("Display statistics: Not implemented yet.\n");
                break;
            case 7:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
