#include <iostream>
using namespace std;

class Queue {
private:
    static const int MAX = 100;
    int data[MAX]; // hidden representation
    int front = 0;
    int rear = 0;
    int count = 0;

public:
    Queue() : front(0), rear(0), count(0) {}

    void enqueue(int value) {
        if (count == MAX) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return;
        }
        rear = (rear + 1) % MAX;
        data[rear] = value;
        count++;
        cout << "Enqueued: " << value << endl;
    }
    void dequeue() {
        if (count == 0) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        front = (front + 1) % MAX;
        count--;
        cout << "Dequeued element." << endl;
    }
    void display() {
        if (count == 0) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < count; i++) {
            cout << data[(front + i) % MAX] << " ";
        }
        cout << endl;
    }
};
    int main() {
        Queue q;
        int choice, value;
        do {
            cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Enter value to enqueue: ";
                    cin >> value;
                    q.enqueue(value);
                    break;
                case 2:
                    q.dequeue();
                    break;
                case 3:
                    q.display();
                    break;
                case 4:
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 4);
        
        return 0;
    }



