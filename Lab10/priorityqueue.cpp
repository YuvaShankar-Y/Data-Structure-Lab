// To make a menu-driven priority queue in C++
#include <iostream>
#include <vector>
using namespace std;

// Class Definition
class MaxHeap {
private:
    vector<int> heap;
    int size;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    MaxHeap();
    void insert(int val);
    void deleteMax();
    void display();
    bool search(int val);
    void heapSort();
};

// Main Menu
int main() {
    MaxHeap pq;
    int choice, value;

    while (true) {
        cout << "\n=== Priority Queue using Max Heap ===\n";
        cout << "1. Insert\n";
        cout << "2. Delete Max\n";
        cout << "3. Display\n";
        cout << "4. Search\n";
        cout << "5. Sort (Heap Sort)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                pq.insert(value);
                break;
            case 2:
                pq.deleteMax();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                if (pq.search(value))
                    cout << "Value found in the heap.\n";
                else
                    cout << "Value not found.\n";
                break;
            case 5:
                pq.heapSort();
                break;
            case 6:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

// Constructor
MaxHeap::MaxHeap() {
    size = 0;
    heap.reserve(100); 
}

// Heapify Up
void MaxHeap::heapifyUp(int index) {
    while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Heapify Down
void MaxHeap::heapifyDown(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapifyDown(largest);
    }
}

// Insert
void MaxHeap::insert(int val) {
    if (size >= 100) {
        cout << "Heap is full!\n";
        return;
    }
    heap.push_back(val);
    heapifyUp(size);
    size++;
}

// Delete Max
void MaxHeap::deleteMax() {
    if (size == 0) {
        cout << "Heap is empty!\n";
        return;
    }
    cout << "Deleted max: " << heap[0] << endl;
    heap[0] = heap[size - 1];
    heap.pop_back();
    size--;
    heapifyDown(0);
}

// Display Heap
void MaxHeap::display() {
    if (size == 0) {
        cout << "Heap is empty!\n";
        return;
    }
    cout << "Heap Elements: ";
    for (int i = 0; i < size; i++)
        cout << heap[i] << " ";
    cout << endl;
}

// Search
bool MaxHeap::search(int val) {
    for (int i = 0; i < size; i++) {
        if (heap[i] == val)
            return true;
    }
    return false;
}

// Heap Sort
void MaxHeap::heapSort() {
    vector<int> temp = heap;
    int originalSize = size;

    for (int i = size - 1; i > 0; i--) {
        swap(heap[0], heap[i]);
        size--;
        heapifyDown(0);
    }

    cout << "Sorted Elements (Descending): ";
    for (int i = 0; i < originalSize; i++)
        cout << heap[i] << " ";
    cout << endl;

    heap = temp;
    size = originalSize;
}

/*
Operation		Time Complexity
Insert		        O(log n)
Delete		        O(log n)
Display		        O(n)
Search		        O(n)
Sort (Heap Sort)	O(n log n)
Exit		        O(1)
*/