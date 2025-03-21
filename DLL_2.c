#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function prototypes
void insertAtEnd(struct Node** head, int value);
void displayList(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, value;

    do {
        // Display menu
        printf("\nDoubly Linked List Menu\n");
        printf("1. Insert at the end\n");
        printf("2. Display the list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on user's choice
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;

            case 2:
                displayList(head);
                break;

            case 3:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
    } else {
        struct Node* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
    }

    printf("Node inserted at the end.\n");
}

// Function to display the doubly linked list
void displayList(struct Node* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

