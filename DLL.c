#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function prototypes
void insertAtBeginning(struct Node** head, int value);
void insertAtEnd(struct Node** head, int value);
void insertAtPosition(struct Node** head, int value, int position);
void deleteNode(struct Node** head, int key);
void displayList(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, value, position;

    do {
        // Display menu
        printf("\nDoubly Linked List Menu\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific position\n");
        printf("4. Delete a node\n");
        printf("5. Display the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on user's choice
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;

            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;

            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insertAtPosition(&head, value, position);
                break;

            case 4:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;

            case 5:
                displayList(head);
                break;

            case 6:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to insert a node at the beginning of the doubly linked list
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    *head = newNode;

    printf("Node inserted at the beginning.\n");
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        printf("Node inserted at the end.\n");
        return;
    }

    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;

    printf("Node inserted at the end.\n");
}

// Function to insert a node at a specific position in the doubly linked list
void insertAtPosition(struct Node** head, int value, int position) {
    if (position <= 0) {
        printf("Invalid position. Please enter a position greater than 0.\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, value);
        return;
    }

    struct Node* current = *head;
    int currentPosition = 1;

    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Invalid position. Please enter a valid position.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = current;
    newNode->next = current->next;

    if (current->next != NULL) {
        current->next->prev = newNode;
    }

    current->next = newNode;

    printf("Node inserted at position %d.\n", position);
}

// Function to delete a node with a given value from the doubly linked list
void deleteNode(struct Node** head, int key) {
    struct Node* current = *head;

    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);

    printf("Node with value %d deleted.\n", key);
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

