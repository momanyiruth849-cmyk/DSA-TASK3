#include <iostream>
using namespace std;

class CircularQueue {
private:
    static const int SIZE = 100;
    int queue[SIZE]; // hidden representation
    int front = 0;
    int rear = 0;
    int count = 0;

public:
     CircularQueue() : front(-1), rear(-1) {}

     bool isFull() {return (rear + 1) % SIZE == front;}

     bool isEmpty() {return front == -1;}

     void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = (rear + 1) % SIZE;
            queue[rear] = value;
        }
    }    
        void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
        void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (i != rear) {
            cout << queue[i] << " ";
            i = (i + 1) % SIZE;
        }
        cout << queue[rear] << endl;
    }
};

int main() {
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display();
    cq.dequeue();
    cq.display();
    cq.dequeue();
    cq.dequeue();
    cq.dequeue(); // Attempt to dequeue from an empty queue
    return 0;
}