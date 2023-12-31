#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

struct Task {
    int id;
    char title[100];
    char description[500];
    char deadline[20];
    char status[50];
};

void displayMenu() {
    printf("\n=================================================\n");
    printf("\t\t\t\tTo-Do List Menu           \n");
    printf("=================================================\n");
    printf("\t\t\t\t1. Add a new task\n");
    printf("\t\t\t\t2. Display tasks\n");
    printf("\t\t\t\t3. Modify a task\n");
    printf("\t\t\t\t4. Delete a task by ID\n");
    printf("\t\t\t\t5. Search for tasks\n");
    printf("\t\t\t\t6. Display statistics\n");
    printf("\t\t\t\t7. Exit\n");
    printf("=================================================\n");
    printf("Enter your choice: ");
}

int addTask(struct Task tasks[], int numTasks) {
    char continueInput;

    do {
        if (numTasks >= 100) {
            printf("Maximum number of tasks reached.\n");
            return numTasks;
        }

        printf("Enter task details:\n");

        int newId = numTasks + 1;

        tasks[numTasks].id = newId;

        printf("Title: ");
        scanf(" %[^\n]", tasks[numTasks].title);
        printf("Description: ");
        scanf(" %[^\n]", tasks[numTasks].description);
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
                return numTasks;
        }

        printf("Adding task successfully.\n");

        numTasks++;

        printf("Do you want to continue (y/n): ");
        getchar();
        scanf("%c", &continueInput);
    } while (continueInput == 'y' || continueInput == 'Y');

    return numTasks;
}

void displayTasksByTitle(struct Task tasks[], int numTasks) {
    if (numTasks <= 0) {
        printf("No tasks to display.\n");
        return;
    }

    for (int i = 0; i < numTasks - 1; i++) {
        for (int j = 0; j < numTasks - i - 1; j++) {
            if (strcmp(tasks[j].title, tasks[j + 1].title) > 0) {
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

void displayTasksByDeadline(struct Task tasks[], int numTasks) {
    if (numTasks <= 0) {
        printf("No tasks to display.\n");
        return;
    }

    for (int i = 0; i < numTasks - 1; i++) {
        for (int j = 0; j < numTasks - i - 1; j++) {
            if (strcmp(tasks[j].deadline, tasks[j + 1].deadline) > 0) {
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

void displayTasksWithinThreeDays(struct Task tasks[], int numTasks) {
    if (numTasks <= 0) {
        printf("No tasks to display.\n");
        return;
    }

    printf("Tasks with deadlines within 3 days:\n");

    time_t currentTime;
    time(&currentTime);

    struct tm* currentTM = localtime(&currentTime);

    int currentYear = currentTM->tm_year + 1900;
    int currentMonth = currentTM->tm_mon + 1;
    int currentDay = currentTM->tm_mday;

    for (int i = 0; i < numTasks; i++) {
        int taskYear, taskMonth, taskDay;
        sscanf(tasks[i].deadline, "%d-%d-%d", &taskYear, &taskMonth, &taskDay);

        if (taskYear < currentYear ||
            (taskYear == currentYear && taskMonth < currentMonth) ||
            (taskYear == currentYear && taskMonth == currentMonth && taskDay <= currentDay + 3)) {
            printf("ID: %d\n", tasks[i].id);
            printf("Title: %s\n", tasks[i].title);
            printf("Description: %s\n", tasks[i].description);
            printf("Deadline: %s\n", tasks[i].deadline);
            printf("Status: %s\n", tasks[i].status);
            printf("\n");
        }
    }
}

void modifyTask(struct Task tasks[], int numTasks) {
    int taskId;
    printf("Enter the ID of the task to modify: ");
    scanf("%d", &taskId);

    int taskIndex = -1;

    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].id == taskId) {
            taskIndex = i;
            break;
        }
    }

    if (taskIndex != -1) {
        int modifyChoice;

        printf("Modifying task with ID %d:\n", taskId);

        printf("Current Title: %s\n", tasks[taskIndex].title);
        printf("Current Description: %s\n", tasks[taskIndex].description);
        printf("Current Deadline: %s\n", tasks[taskIndex].deadline);
        printf("Current Status: %s\n", tasks[taskIndex].status);

        printf("Enter the number to modify:\n");
        printf("1. Title\n");
        printf("2. Description\n");
        printf("3. Deadline\n");
        printf("4. Status\n");
        printf("Enter your choice: ");
        scanf("%d", &modifyChoice);

        switch (modifyChoice) {
            case 1:
                printf("Enter new Title: ");
                scanf(" %[^\n]", tasks[taskIndex].title);
                break;
            case 2:
                printf("Enter new Description: ");
                scanf(" %[^\n]", tasks[taskIndex].description);
                break;
            case 3:
                printf("Enter new Deadline (YYYY-MM-DD): ");
                scanf("%s", tasks[taskIndex].deadline);
                break;
            case 4:
                printf("Enter new Status:\n");
                printf("1. À réaliser\n");
                printf("2. En cours de réalisation\n");
                printf("3. Finalisée\n");
                printf("Enter your choice: ");
                int statusChoice;
                scanf("%d", &statusChoice);
                switch (statusChoice) {
                    case 1:
                        strcpy(tasks[taskIndex].status, "À réaliser");
                        break;
                    case 2:
                        strcpy(tasks[taskIndex].status, "En cours de réalisation");
                        break;
                    case 3:
                        strcpy(tasks[taskIndex].status, "Finalisée");
                        break;
                    default:
                        printf("Invalid choice.\n");
                        return;
                }
                break;
            default:
                printf("Invalid choice.\n");
                return;
        }

        printf("Task with ID %d modified successfully.\n", taskId);
    } else {
        printf("Task with ID %d not found.\n", taskId);
    }
}

int deleteTask(struct Task tasks[], int numTasks) {
    int taskId;
    printf("Enter the ID of the task to delete: ");
    scanf("%d", &taskId);

    int taskIndex = -1;

    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].id == taskId) {
            taskIndex = i;
            break;
        }
    }

    if (taskIndex != -1) {
        for (int i = taskIndex; i < numTasks - 1; i++) {
            tasks[i] = tasks[i + 1];
        }

        printf("Task with ID %d deleted successfully.\n", taskId);
        return numTasks - 1;
    } else {
        printf("Task with ID %d not found.\n", taskId);
        return numTasks;
    }
}

void searchTasks(struct Task tasks[], int numTasks) {
    int choice;
    printf("Search by:\n");
    printf("1. Task ID\n");
    printf("2. Task Title\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    getchar();

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

void displayStatistics(struct Task tasks[], int numTasks) {
    if (numTasks <= 0) {
        printf("No tasks to display statistics for.\n");
        return;
    }

    int totalTasks = numTasks;
    int completedTasks = 0;
    int inProgressTasks = 0;
    int pendingTasks = 0;

    for (int i = 0; i < numTasks; i++) {
        if (strcmp(tasks[i].status, "Finalisée") == 0) {
            completedTasks++;
        } else if (strcmp(tasks[i].status, "En cours de réalisation") == 0) {
            inProgressTasks++;
        } else if (strcmp(tasks[i].status, "À réaliser") == 0) {
            pendingTasks++;
        }
    }

    printf("Total number of tasks: %d\n", totalTasks);
    printf("Finalisée tasks: %d\n", completedTasks);
    printf("Tasks En cours de réalisation: %d\n", inProgressTasks);
    printf("À réaliser tasks: %d\n", pendingTasks);
}

int main() {
    struct Task tasks[100];
    int numTasks = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                numTasks = addTask(tasks, numTasks);
                break;
            case 2: {
                int displayChoice;
                printf("Display tasks by:\n");
                printf("1. Title\n");
                printf("2. Deadline\n");
                printf("3. Tasks within 3 days\n");
                printf("Enter your choice: ");
                scanf("%d", &displayChoice);

                if (displayChoice == 1) {
                    displayTasksByTitle(tasks, numTasks);
                } else if (displayChoice == 2) {
                    displayTasksByDeadline(tasks, numTasks);
                } else if (displayChoice == 3) {
                    displayTasksWithinThreeDays(tasks, numTasks);
                } else {
                    printf("Invalid choice.\n");
                }
                break;
            }
            case 3:
                modifyTask(tasks, numTasks);
                break;
            case 4:
                numTasks = deleteTask(tasks, numTasks);
                break;
            case 5:
                searchTasks(tasks, numTasks);
                break;
            case 6:
                displayStatistics(tasks, numTasks);
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
