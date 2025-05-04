//To implement a circular queue adt with integer array of size 5
#include <iostream>
using namespace std;
#define MAX 5

class CircularQueue {
private:
    int queue[MAX];
    int front, rear;

public:
    CircularQueue();
    void enqueue(int value);
    void dequeue();
    void peek();
    bool isFull();
    bool isEmpty();
};

int main() {
    CircularQueue cq;
    int choice, value;
    while (true) {
        cout << "\nMenu\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter the value to Enqueue: ";
            cin >> value;
            cq.enqueue(value);
            break;
        case 2:
            cq.dequeue();
            break;
        case 3:
            cq.peek();
            break;
        case 4:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid option! Please choose again.\n";
        }
    }
    return 0;
}

//Constructor
CircularQueue::CircularQueue() {
    front = -1;
    rear = -1;
}

bool CircularQueue::isFull() {
    return (front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1));
}

bool CircularQueue::isEmpty() {
    return front == -1;
}

void CircularQueue::enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow! Cannot Enqueue.\n";
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = value;
    cout << value << " Enqueued successfully!\n";
}

void CircularQueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Nothing to Dequeue.\n";
        return;
    }
    cout << queue[front] << " Dequeued successfully!\n";
    if (front == rear) {
        front = rear = -1; // Reset queue after last element
    } else {
        front = (front + 1) % MAX;
    }
}

void CircularQueue::peek() {
    if (isEmpty()) {
        cout << "Queue is Empty. No Front Element.\n";
        return;
    }
    cout << "Front Element: " << queue[front] << endl;
}

/*
Time Complexity of Operations:
Enqueue: 𝑂(1)
O(1) – Insert at the rear in constant time.

Dequeue: 𝑂(1)
O(1) – Remove from the front in constant time.

Peek: 𝑂(1)
O(1) – Accessing the front element takes constant time.

Exit: 𝑂(1)
O(1) – Exiting the program is an instant operation.
*/