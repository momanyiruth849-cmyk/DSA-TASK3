#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}
int isEmpty() {
    return front == -1;
}

// 1. Front Insertion
void insertFront(int value) {
    if (isFull()) {
        printf("Deque is full. Cannot insert %d at front.\n", value);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = SIZE - 1;
    } else {
        front--;
    }
    deque[front] = value;
    printf("Inserted %d at front.\n", value);
}

// 2. Rear Insertion
void insertRear(int value) {
    if (isFull()) {
        printf("Deque is full. Cannot insert %d at rear.\n", value);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = value;
    printf("Inserted %d at rear.\n", value);
}

// 3. Front Deletion
void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete from front.\n");
        return;
    }
    printf("Deleted %d from front.\n", deque[front]);
    if (front == rear) {
        front = rear = -1; // Deque is now empty
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

// 4. Rear Deletion
void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete from rear.\n");
        return;
    }
    printf("Deleted %d from rear.\n", deque[rear]);
    if (front == rear) {
        front = rear = -1; // Deque is now empty
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear--;
    }
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertFront(2);
    deleteRear();
    deleteFront();
    return 0;
}