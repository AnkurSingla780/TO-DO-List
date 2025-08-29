#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node {
    char task[100];
    int priority;              
    bool completed;             
    struct node* next;
};

struct node* head = NULL;

void trimNewline(char* str) {
    str[strcspn(str, "\n")] = '\0';
}


void insertTask(char task[], int priority) {
    if (strlen(task) == 0) {  
        printf("\nTask cannot be empty!\n");
        return;
    }

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->task, task);
    newNode->priority = priority;
    newNode->completed = false;   
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("\nTask added successfully.\n");
}

void displayTasks() {
    int i = 1;
    if (head == NULL) {
        printf("\nNO TASKS AVAILABLE !!!\n");
    } else {
        struct node* ptr = head;
        while (ptr != NULL) {
            printf("%d. %s (Priority: %d) [%s]\n",
                   i, ptr->task, ptr->priority,
                   ptr->completed ? "Completed" : "Not Completed");
            i++;
            ptr = ptr->next;
        }
    }
}

void deleteTask(char task[]) {
    if (head == NULL) {
        printf("\nNO TASKS AVAILABLE !!!\n");
        return;
    }

    struct node* temp = head;
    struct node* prev = NULL;

    if (strcmp(temp->task, task) == 0) {
        head = temp->next;
        free(temp);
        printf("\nTask deleted successfully.\n");
        return;
    }

    while (temp != NULL && strcmp(temp->task, task) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nTASK NOT FOUND !!!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("\nTask deleted successfully.\n");
}

void markCompleted(char task[]) {
    if (head == NULL) {
        printf("\nNO TASKS AVAILABLE !!!\n");
        return;
    }

    struct node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->task, task) == 0) {
            temp->completed = true;
            printf("\nTask marked as completed.\n");
            return;
        }
        temp = temp->next;
    }

    printf("\nTASK NOT FOUND !!!\n");
}

int getChoice() {
    char buffer[10];
    if (!fgets(buffer, sizeof(buffer), stdin)) return -1;
    trimNewline(buffer);

    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] < '0' || buffer[i] > '9') {
            return -1; 
        }
    }
    return atoi(buffer);
}

int main() {
    int choice, priority;
    char task[100];

    while (true) {
        printf("\n<<<<<< TODO List >>>>>>\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Mark Task as Completed\n");
        printf("5. Exit\n");
        printf("=======================================================\n");
        printf("Enter your choice: ");

        choice = getChoice();

        switch (choice) {
            case 1:
                printf("Enter the task: ");
                if (fgets(task, sizeof(task), stdin)) {
                    trimNewline(task);
                }
                printf("Enter priority: ");
                scanf("%d", &priority);
                getchar(); 
                insertTask(task, priority);
                break;

            case 2:
                displayTasks();
                break;

            case 3:
                printf("Enter the task to delete: ");
                if (fgets(task, sizeof(task), stdin)) {
                    trimNewline(task);
                }
                deleteTask(task);
                break;

            case 4:
                printf("Enter the task to mark as completed: ");
                if (fgets(task, sizeof(task), stdin)) {
                    trimNewline(task);
                }
                markCompleted(task);
                break;

            case 5:
                printf("Exiting the LIST !!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}

