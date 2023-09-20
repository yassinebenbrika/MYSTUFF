#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

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
    printf("2. Display all tasks (sorted by title)\n");
    printf("3. Display all tasks (sorted by deadline)\n");
    printf("4. Display tasks with a deadline in 3 days or less\n");
    printf("5. Modify a task\n");
    printf("6. Delete a task by ID\n");
    printf("7. Search for tasks\n");
    printf("8. Display statistics\n");
    printf("9. Exit\n");
    printf("Enter your choice: ");
}

// Function to add a new task
void addTask(struct Task tasks[], int *numTasks) {
    printf("Enter task details:\n");
    
    // Increment the ID for the new task
    int newId = *numTasks + 1;
    
    // Set the task ID
    tasks[*numTasks].id = newId;

    printf("Title: ");
    scanf(" %[^\n]", tasks[*numTasks].title); // Read until newline
    printf("Description: ");
    scanf(" %[^\n]", tasks[*numTasks].description); // Read until newline
    printf("Deadline (YYYY-MM-DD): ");
    scanf("%s", tasks[*numTasks].deadline);
    printf("Status (e.g., 'à réaliser', 'en cours de réalisation', 'finalisée'): ");
    scanf(" %[^\n]", tasks[*numTasks].status); // Read until newline
    
    (*numTasks)++; // Increment the task count
    printf("Task added successfully.\n");
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


// Function to modify a task
void modifyTask(struct Task tasks[], int numTasks) {
    if (numTasks <= 0) {
        printf("No tasks to modify.\n");
        return;
    }

    int taskId;
    printf("Enter the ID of the task you want to modify: ");
    scanf("%d", &taskId);

    // Find the task with the provided ID
    int taskIndex = -1;
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].id == taskId) {
            taskIndex = i;
            break;
        }
    }

    if (taskIndex == -1) {
        printf("Task with ID %d not found.\n", taskId);
        return;
    }

    int choice;
    printf("Choose what you want to modify:\n");
    printf("1. Description\n");
    printf("2. Status\n");
    printf("3. Deadline\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the new description: ");
            scanf(" %s[^\n]", tasks[taskIndex].description);
            printf("Description updated.\n");
            break;
        case 2:
            printf("Enter the new status: ");
            scanf(" %s[^\n]", tasks[taskIndex].status);
            printf("Status updated.\n");
            break;
        case 3:
            printf("Enter the new deadline (YYYY-MM-DD): ");
            scanf("%s", tasks[taskIndex].deadline);
            printf("Deadline updated.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }
}

// Function to delete a task by ID
void deleteTask(struct Task tasks[], int *numTasks) {
    int taskId;
    printf("Enter the ID of the task to delete: ");
    scanf("%d", &taskId);

    int taskIndex = -1;

    // Find the task with the given ID
    for (int i = 0; i < *numTasks; i++) {
        if (tasks[i].id == taskId) {
            taskIndex = i;
            break;
        }
    }

    if (taskIndex != -1) {
        // Shift remaining tasks to fill the gap
        for (int i = taskIndex; i < *numTasks - 1; i++) {
            tasks[i] = tasks[i + 1];
        }

        (*numTasks)--; // Decrement the task count
        printf("Task with ID %d deleted successfully.\n", taskId);
    } else {
        printf("Task with ID %d not found.\n", taskId);
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
            scanf(" %s[^\n]", searchTitle);

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

// Function to display statistics
void displayStatistics(struct Task tasks[], int numTasks) {
    int totalTasks = numTasks;
    int completedTasks = 0;

    // Get the current time
    time_t currentTime;
    struct tm *tmInfo;
    time(&currentTime);
    tmInfo = localtime(&currentTime);

    for (int i = 0; i < numTasks; i++) {
        // Count completed tasks
        if (strcmp(tasks[i].status, "finalisée") == 0) {
            completedTasks++;
        }

        // Calculate days remaining until deadline
        struct tm deadlineInfo;
        sscanf(tasks[i].deadline, "%d-%d-%d", &deadlineInfo.tm_year, &deadlineInfo.tm_mon, &deadlineInfo.tm_mday);
        deadlineInfo.tm_year -= 1900; // Adjust year
        deadlineInfo.tm_mon -= 1;     // Adjust month
        time_t deadlineTime = mktime(&deadlineInfo);
        double timeDifference = difftime(deadlineTime, currentTime);
        int daysRemaining = (int)(timeDifference / (60 * 60 * 24));

        printf("Task ID: %d\n", tasks[i].id);
        printf("Title: %s\n", tasks[i].title);
        printf("Days Remaining until Deadline: %d\n", daysRemaining);
        printf("Status: %s\n", tasks[i].status);
        printf("\n");
    }

    printf("Total Tasks: %d\n", totalTasks);
    printf("Completed Tasks: %d\n", completedTasks);
    printf("Incomplete Tasks: %d\n", totalTasks - completedTasks);
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
                addTask(tasks, &numTasks);
                break;
            case 2:
                displayTasksByTitle(tasks, numTasks);
                break;
            case 3:
                displayTasksByDeadline(tasks, numTasks);
                break;
  case 4:
    // Display tasks with a deadline in 3 days or less
    printf("Tasks with a deadline in 3 days or less:\n");
    for (int i = 0; i < numTasks; i++) {
        if (isNearDeadline(tasks[i].deadline)) {
            printf("ID: %d\n", tasks[i].id);
            printf("Title: %s\n", tasks[i].title);
            printf("Description: %s\n", tasks[i].description);
            printf("Deadline: %s\n", tasks[i].deadline);
            printf("Status: %s\n", tasks[i].status);
            printf("\n");
        }
    }
    break;

            case 5:
                modifyTask(tasks, numTasks);
                break;
            case 6:
                deleteTask(tasks, &numTasks);
                break;
            case 7:
                searchTasks(tasks, numTasks);
                break;
            case 8:
                displayStatistics(tasks, numTasks);
                break;
            case 9:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        
    }} while (choice != 9);

    return 0;}

