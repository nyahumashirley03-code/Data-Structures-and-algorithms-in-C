10 Write a program to perform all operations: - For Stack using Linked List. - For Queue using Linked List - For Circular Queue using Linked List 

#include <stdio.h>

#define MAX 100

int dataArr[MAX];
int nextArr[MAX];


int stackTop = -1;
int stackFree = 0;

void push(int value) {
    if (stackFree >= MAX) {
        printf("Stack overflow!\n");
        return;
    }
    dataArr[stackFree] = value;
    nextArr[stackFree] = stackTop;
    stackTop = stackFree;
    stackFree++;
}

void pop() {
    if (stackTop == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Popped: %d\n", dataArr[stackTop]);
    stackTop = nextArr[stackTop];
}

void displayStack() {
    if (stackTop == -1) {
        printf("Stack is empty!\n");
        return;
    }
    int temp = stackTop;
    printf("Stack: ");
    while (temp != -1) {
        printf("%d -> ", dataArr[temp]);
        temp = nextArr[temp];
    }
    printf("NULL\n");
}

int queueFront = -1, queueRear = -1;
int queueFree = 0;

void enqueue(int value) {
    if (queueFree >= MAX) {
        printf("Queue overflow!\n");
        return;
    }
    dataArr[queueFree] = value;
    nextArr[queueFree] = -1;

    if (queueFront == -1) {
        queueFront = queueRear = queueFree;
    } else {
        nextArr[queueRear] = queueFree;
        queueRear = queueFree;
    }
    queueFree++;
}

void dequeue() {
    if (queueFront == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Dequeued: %d\n", dataArr[queueFront]);
    queueFront = nextArr[queueFront];
    if (queueFront == -1) queueRear = -1;
}

void displayQueue() {
    if (queueFront == -1) {
        printf("Queue is empty!\n");
        return;
    }
    int temp = queueFront;
    printf("Queue: ");
    while (temp != -1) {
        printf("%d -> ", dataArr[temp]);
        temp = nextArr[temp];
    }
    printf("NULL\n");
}

int cqFront = -1, cqRear = -1;
int cqFree = 0;

void enqueueCQ(int value) {
    if (cqFree >= MAX) {
        printf("Circular Queue overflow!\n");
        return;
    }
    dataArr[cqFree] = value;
    if (cqFront == -1) {
        cqFront = cqRear = cqFree;
        nextArr[cqFree] = cqFront; 
    } else {
        nextArr[cqRear] = cqFree;
        cqRear = cqFree;
        nextArr[cqRear] = cqFront; 
    }
    cqFree++;
}

void dequeueCQ() {
    if (cqFront == -1) {
        printf("Circular Queue is empty!\n");
        return;
    }
    printf("Dequeued: %d\n", dataArr[cqFront]);
    if (cqFront == cqRear) {
        cqFront = cqRear = -1;
    } else {
        cqFront = nextArr[cqFront];
        nextArr[cqRear] = cqFront; 
    }
}

void displayCQ() {
    if (cqFront == -1) {
        printf("Circular Queue is empty!\n");
        return;
    }
    int temp = cqFront;
    printf("Circular Queue: ");
    do {
        printf("%d -> ", dataArr[temp]);
        temp = nextArr[temp];
    } while (temp != cqFront);
    printf("(back to front)\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Stack Push\n2. Stack Pop\n3. Stack Display\n");
        printf("4. Queue Enqueue\n5. Queue Dequeue\n6. Queue Display\n");
        printf("7. Circular Queue Enqueue\n8. Circular Queue Dequeue\n9. Circular Queue Display\n");
        printf("10. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &value); push(value); break;
            case 2: pop(); break;
            case 3: displayStack(); break;
            case 4: printf("Enter value: "); scanf("%d", &value); enqueue(value); break;
            case 5: dequeue(); break;
            case 6: displayQueue(); break;
            case 7: printf("Enter value: "); scanf("%d", &value); enqueueCQ(value); break;
            case 8: dequeueCQ(); break;
            case 9: displayCQ(); break;
            case 10: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}