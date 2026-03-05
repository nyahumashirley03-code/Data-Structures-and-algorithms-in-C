#include <stdio.h>

#define MAX 10   

struct Node {
    int data;
    int next;   
};


struct Node nodes[MAX];
int head = -1;     
int freeIndex = 0; 

void insert(int value) {
    if (freeIndex >= MAX) {
        printf("List is full!\n");
        return;
    }

    nodes[freeIndex].data = value;
    nodes[freeIndex].next = -1;

    if (head == -1) {
        head = freeIndex;
    } else {
        int temp = head;
        while (nodes[temp].next != -1) {
            temp = nodes[temp].next;
        }
        nodes[temp].next = freeIndex;
    }
    freeIndex++;
}

void delete(int value) {
    if (head == -1) {
        printf("List is empty!\n");
        return;
    }

    int temp = head;
    int prev = -1;

    while (temp != -1 && nodes[temp].data != value) {
        prev = temp;
        temp = nodes[temp].next;
    }

    if (temp == -1) {
        printf("Value not found!\n");
        return;
    }

    if (prev == -1) {
        head = nodes[temp].next;
    } else {
        nodes[prev].next = nodes[temp].next;
    }

    printf("Deleted %d\n", value);
}

void display() {
    if (head == -1) {
        printf("List is empty!\n");
        return;
    }
    int temp = head;
    printf("Linked List: ");
    while (temp != -1) {
        printf("%d -> ", nodes[temp].data);
        temp = nodes[temp].next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(value);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}