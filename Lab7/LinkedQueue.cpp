//To Make a Queue ADT using linked list
#include <iostream>
using namespace std;

// Node structure for linked list-based queue
struct Node {
    int data;
    Node* next;
    Node(int value){
    data=value;
    next=nullptr; 
    }
};

// Queue class using linked list
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue();
    void enqueue(int value);
    void dequeue();
    void peek();
    bool isEmpty();
};

int main() {
    Queue q;
    int choice, value;
    do {
        cout << "\nQueue Operations:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
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
                q.peek();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);
    return 0;
}

// Constructor
Queue::Queue(){
    front=nullptr;
    rear=nullptr;
}

// Check if the queue is empty
bool Queue::isEmpty() {
    return front == nullptr;
}

// Enqueue operation
void Queue::enqueue(int value) {
    Node* newNode = new Node(value);
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "Enqueued: " << value << endl;
}

// Dequeue operation
void Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Nothing to dequeue.\n";
        return;
    }
    Node* temp = front;
    cout << "Dequeued: " << temp->data << endl;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
}

// Peek operation
void Queue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty. No front element.\n";
        return;
    }
    cout << "Front element: " << front->data << endl;
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