// Write a C++ menu-driven program to implement List ADT using a circular linked list
#include <iostream>
using namespace std;

class CircularLinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* tail; // Tail pointer (head can be accessed via tail->next)

public:
    CircularLinkedList();
    void insertBeginning(int value);
    void insertEnd(int value);
    void insertPosition(int position, int value);
    void deleteBeginning();
    void deleteEnd();
    void deletePosition(int position);
    bool search(int key);
    void display();
};

// Main function
int main() {
    int choice, value, position;
    CircularLinkedList cl;

    while (1) {
        cout << "\n    MENU\n";
        cout << "1. Insert Beginning\n";
        cout << "2. Insert End\n";
        cout << "3. Insert Position\n";
        cout << "4. Delete Beginning\n";
        cout << "5. Delete End\n";
        cout << "6. Delete Position\n";
        cout << "7. Search\n";
        cout << "8. Display\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                cl.insertBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                cl.insertEnd(value);
                break;
            case 3:
                cout << "Enter position: ";
                cin >> position;
                cout << "Enter value: ";
                cin >> value;
                cl.insertPosition(position, value);
                break;
            case 4:
                cl.deleteBeginning();
                break;
            case 5:
                cl.deleteEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> position;
                cl.deletePosition(position);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                cl.search(value);
                break;
            case 8:
                cl.display();
                break;
            case 9:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Error: Invalid option! Try again.\n";
        }
    }
}

// Constructor
CircularLinkedList::CircularLinkedList() {
    tail = nullptr;
}

// Insert at beginning
void CircularLinkedList::insertBeginning(int value) {
    Node* newNode = new Node{value, nullptr};

    if (!tail) {  
        newNode->next = newNode;
        tail = newNode;
    } else {  
        newNode->next = tail->next;  
        tail->next = newNode;  
    }

    cout << "Inserted " << value << " at the beginning.\n";
}

// Insert at end
void CircularLinkedList::insertEnd(int value) {
    Node* newNode = new Node{value, nullptr};

    if (!tail) {
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode; // Update tail
    }
    cout << "Inserted " << value << " at the end.\n";
}

// Insert at a specific position
void CircularLinkedList::insertPosition(int position, int value) {
    if (position <= 1) {
        insertBeginning(value);
        return;
    }

    if (!tail) {
        cout << "Warning: List is empty. Inserting at beginning.\n";
        insertBeginning(value);
        return;
    }

    Node* temp = tail->next;
    int count = 1;

    // Count number of nodes
    do {
        temp = temp->next;
        count++;
    } while (temp != tail->next);

    // If position exceeds the number of elements + 1
    if (position > count + 1) {
        cout << "Error: Position " << position << " is out of range. The list has only " << count << " elements.\n";
        return;
    }

    // If inserting at the last position (count + 1), it's the same as insertEnd
    if (position == count + 1) {
        insertEnd(value);
        return;
    }

    // Move temp to the node just before the insertion point
    temp = tail->next;
    count = 1;
    
    while (count < position - 1) {
        temp = temp->next;
        count++;
    }

    // Create and insert new node
    Node* newNode = new Node{value, temp->next};
    temp->next = newNode;

    cout << "Inserted " << value << " at position " << position << ".\n";
}


// Delete from beginning
void CircularLinkedList::deleteBeginning() {
    if (!tail) {
        cout << "Error: List is empty. Nothing to delete.\n";
        return;
    }

    Node* temp = tail->next;

    if (tail == tail->next) { // Only one node
        tail = nullptr; // Updating tail BEFORE deleting to avoid accessing freed memory
    } else {
        tail->next = temp->next;
    }

    cout << "Deleted " << temp->data << " from the beginning.\n";
    delete temp; // Freeing memory
}

// Delete from end
void CircularLinkedList::deleteEnd() {
    if (!tail) {
        cout << "Error: List is empty. Nothing to delete.\n";
        return;
    }

    Node* temp = tail->next;

    if (tail == tail->next) { // Single node case
        cout << "Deleted " << tail->data << " from the end.\n";
        delete tail;
        tail = nullptr;
        return;
    }

    // Find second-last node 
    while (temp->next != tail) {
        temp = temp->next;
    }

    cout << "Deleted " << tail->data << " from the end.\n";
    temp->next = tail->next; // Bypass tail
    delete tail; // Free memory
    tail = temp; // Update tail to second-last node
}


// Delete at a specific position
void CircularLinkedList::deletePosition(int position) {
    if (!tail) {
        cout << "Error: List is empty. Nothing to delete.\n";
        return;
    }

    if (position == 1) {
        deleteBeginning();
        return;
    }

    Node* temp = tail->next;
    Node* prev = nullptr;
    int count = 1;

    // Count number of nodes
    Node* counter = tail->next;
    int totalNodes = 0;
    do {
        totalNodes++;
        counter = counter->next;
    } while (counter != tail->next);

    if (position > totalNodes) {
        cout << "Error: Position " << position << " is out of range. The list has only " << totalNodes << " elements.\n";
        return;
    }

    // If position is the last node, call deleteEnd()
    if (position == totalNodes) {
        deleteEnd();
        return;
    }

    // Traverse to the node before the one to be deleted
    while (count < position) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    prev->next = temp->next;
    cout << "Deleted " << temp->data << " from position " << position << ".\n";
    delete temp;
}

// Search for an element
bool CircularLinkedList::search(int key) {
    if (!tail) {
        cout << "Error: List is empty.\n";
        return false;
    }

    Node* temp = tail->next;
    int position = 1;

    do {
        if (temp->data == key) {
            cout << "Element " << key << " found at position " << position << ".\n";
            return true;
        }
        temp = temp->next;
        position++;
    } while (temp != tail->next);  // Ensures full traversal

    cout << "Element " << key << " not found in the list.\n";
    return false;
}

// Display elements
void CircularLinkedList::display() {
    if (!tail) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = tail->next;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << "(Back to Head)\n";
}

/*
    Time Complexity Analysis
Operation	        Time Complexity
Insert Beginning	    O(1)
Insert End	            O(1)
Insert Position	        O(n)
Delete Beginning	    O(1)
Delete End	            O(n)
Delete Position	        O(n)
Search	                O(n)
Display	                O(n)
*/