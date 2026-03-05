11. Write a program to perform concatenation of two linked lists.

#include <stdio.h>

#define MAX 25

int dataArr[MAX];   
int nextArr[MAX];   
int freeIndex = 0;  

int createNode(int value) {
    if (freeIndex >= MAX) {
        printf("No more space!\n");
        return -1;
    }
    dataArr[freeIndex] = value;
    nextArr[freeIndex] = -1;
    return freeIndex++;
}

int insert(int head, int value) {
    int newNode = createNode(value);
    if (newNode == -1) return head;

    if (head == -1) {
        head = newNode;
    } else {
        int temp = head;
        while (nextArr[temp] != -1) {
            temp = nextArr[temp];
        }
        nextArr[temp] = newNode;
    }
    return head;
}

void display(int head) {
    if (head == -1) {
        printf("List is empty!\n");
        return;
    }
    int temp = head;
    while (temp != -1) {
        printf("%d -> ", dataArr[temp]);
        temp = nextArr[temp];
    }
    printf("NULL\n");
}

int concatenate(int head1, int head2) {
    if (head1 == -1) return head2;
    if (head2 == -1) return head1;

    int temp = head1;
    while (nextArr[temp] != -1) {
        temp = nextArr[temp];
    }
    nextArr[temp] = head2;
    return head1;
}

int main() {
    int list1 = -1, list2 = -1;
    int n1, n2, val;

    printf("Enter number of elements in List 1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        list1 = insert(list1, val);
    }

    printf("Enter number of elements in List 2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        list2 = insert(list2, val);
    }

    printf("\nList 1: ");
    display(list1);
    printf("List 2: ");
    display(list2);

    int concatenated = concatenate(list1, list2);
    printf("\nConcatenated List: ");
    display(concatenated);

    return 0;
}

