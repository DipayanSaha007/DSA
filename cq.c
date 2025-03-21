#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Circular Queue structure
struct CircularQueue {
    struct Node* front;
    struct Node* rear;
};

// Function prototypes
void initializeQueue(struct CircularQueue* cq);
void enqueue(struct CircularQueue* cq, int value);
int dequeue(struct CircularQueue* cq);
void display(struct CircularQueue* cq);

int main() {
    struct CircularQueue cq;
    initializeQueue(&cq);

    int choice, value;

    do {
        // Menu
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&cq, value);
                break;
            case 2:
                if (cq.front == NULL) {
                    printf("Queue is empty. Cannot dequeue.\n");
                } else {
                    printf("Dequeued value: %d\n", dequeue(&cq));
                }
                break;
            case 3:
                display(&cq);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to initialize an empty circular queue
void initializeQueue(struct CircularQueue* cq) {
    cq->front = NULL;
    cq->rear = NULL;
}

// Function to enqueue a value into the circular queue
void enqueue(struct CircularQueue* cq, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (cq->front == NULL) {
        cq->front = newNode;
        cq->rear = newNode;
        newNode->next = cq->front; // Point to itself to form a circular structure
    } else {
        cq->rear->next = newNode;
        cq->rear = newNode;
        cq->rear->next = cq->front; // Point rear to front to maintain circular structure
    }

    printf("%d enqueued successfully.\n", value);
}

// Function to dequeue a value from the circular queue
int dequeue(struct CircularQueue* cq) {
    int value;
    struct Node* temp;

    if (cq->front == cq->rear) {
        // Only one element in the queue
        value = cq->front->data;
        free(cq->front);
        cq->front = NULL;
        cq->rear = NULL;
    } else {
        // More than one element in the queue
        value = cq->front->data;
        temp = cq->front;
        cq->front = cq->front->next;
        cq->rear->next = cq->front; // Update rear to maintain circular structure
        free(temp);
    }

    return value;
}

// Function to display the elements of the circular queue
void display(struct CircularQueue* cq) {
    if (cq->front == NULL) {
        printf("Queue is empty.\n");
    } else {
        struct Node* current = cq->front;

        printf("Circular Queue elements: ");
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != cq->front);

        printf("\n");
    }
}

