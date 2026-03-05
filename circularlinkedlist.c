9. Write a program to perform the operations of the Circular linked list: - Insertion - Deletion - Display
#include <stdio.h>

#define MAX 25

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

    if (head == -1) {
        head = freeIndex;
        nodes[freeIndex].next = head;  
    } else {
        int temp = head;
        while (nodes[temp].next != head) {
            temp = nodes[temp].next;
        }
        nodes[temp].next = freeIndex;
        nodes[freeIndex].next = head;
    }
    freeIndex++;
}

void delete(int value) {
    if (head == -1) {
        printf("List is empty!\n");
        return;
    }

    int temp = head, prev = -1;

    if (nodes[head].data == value) {
        if (nodes[head].next == head) {
            head = -1; 
            return;
        }

        int last = head;
        while (nodes[last].next != head) {
            last = nodes[last].next;
        }
        head = nodes[head].next;
        nodes[last].next = head;
        return;
    }

    do {
        prev = temp;
        temp = nodes[temp].next;
        if (nodes[temp].data == value) {
            nodes[prev].next = nodes[temp].next;
            return;
        }
    } while (temp != head);

    printf("Value not found!\n");
}

void display() {
    if (head == -1) {
        printf("List is empty!\n");
        return;
    }

    int temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", nodes[temp].data);
        temp = nodes[temp].next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
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

