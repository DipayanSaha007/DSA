#include <stdio.h>
#include <stdlib.h>

// Node structure for the priority queue
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to enqueue a new element with priority
void enqueue(struct Node** front, int data, int priority) {
    struct Node* newNode = createNode(data, priority);
    if (*front == NULL || priority < (*front)->priority) {
        newNode->next = *front;
        *front = newNode;
    } else {
        struct Node* temp = *front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Enqueued %d with priority %d\n", data, priority);
}

// Function to dequeue the element with the highest priority
void dequeue(struct Node** front) {
    if (*front == NULL) {
        printf("Queue is empty\n");
    } else {
        struct Node* temp = *front;
        *front = (*front)->next;
        printf("Dequeued %d with priority %d\n", temp->data, temp->priority);
        free(temp);
    }
}

// Function to display the elements in the priority queue
void display(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Priority Queue: ");
        while (front != NULL) {
            printf("(%d, %d) ", front->data, front->priority);
            front = front->next;
        }
        printf("\n");
    }
}

// Function to free the allocated memory for the priority queue
void freeQueue(struct Node* front) {
    while (front != NULL) {
        struct Node* temp = front;
        front = front->next;
        free(temp);
    }
}

int main() {
    struct Node* front = NULL;
    int choice, data, priority;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(&front, data, priority);
                break;

            case 2:
                dequeue(&front);
                break;

            case 3:
                display(front);
                break;

            case 4:
                freeQueue(front);
                printf("Program terminated\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

