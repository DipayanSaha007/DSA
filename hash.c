#include <stdio.h>

#define SIZE 10

// Function to calculate the hash value
int hash(int key) {
    return key % SIZE;
}

// Function to insert an element into the hash table using linear probing
void insert(int table[], int key) {
    int index = hash(key);

    // Linear probing to handle collisions
    while (table[index] != -1) {
        index = (index + 1) % SIZE;
    }

    // Insert the key at the calculated index
    table[index] = key;
}

// Function to display the contents of the hash table
void display(int table[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d: %d\n", i, table[i]);
    }
}

int main() {
    int hashTable[SIZE];

    // Initialize hash table with -1 (indicating empty)
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    int n, key;

    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(hashTable, key);
    }

    display(hashTable);

    return 0;
}

