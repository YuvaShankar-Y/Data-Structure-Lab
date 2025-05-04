// Write a C++ menu-driven program to implement List ADT using a doubly linked list

#include <iostream>
using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList();
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
    DoublyLinkedList dl;

    while (true) {
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
                dl.insertBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                dl.insertEnd(value);
                break;
            case 3:
                cout << "Enter position: ";
                cin >> position;
                cout << "Enter value: ";
                cin >> value;
                dl.insertPosition(position, value);
                break;
            case 4:
                dl.deleteBeginning();
                break;
            case 5:
                dl.deleteEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> position;
                dl.deletePosition(position);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                dl.search(value);
                break;
            case 8:
                dl.display();
                break;
            case 9:
                cout << "Exiting...\n";
                cout << "Successfully Exited\n";
                return 0;
            default:
                cout << "Invalid option! Try again.\n";
                break;
        }
    }
}

// Constructor
DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

// Insert at beginning
void DoublyLinkedList::insertBeginning(int value) {
    Node* newNode = new Node{value, nullptr, head};

    if (!head) {
        head = tail = newNode;
    } else {
        head->prev = newNode;
        head = newNode;
    }
    cout << "Inserted " << value << " at the beginning.\n";
}

// Insert at end
void DoublyLinkedList::insertEnd(int value) {
    Node* newNode = new Node{value, tail, nullptr};

    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode; 
        newNode->prev = tail; 
        tail = newNode;
    }
}


// Insert at a specific position
void DoublyLinkedList::insertPosition(int position, int value) {
    if (position <= 1) {
        insertBeginning(value);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (temp && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (!temp || !temp->next) {  // If temp reaches nullptr or it's the last node
        cout << "Invalid position! Inserting at the end.\n";
        insertEnd(value);
        return;
    }

    Node* newNode = new Node{value, temp, temp->next};
    
    if (temp->next)  // Ensure the next node exists before accessing it
        temp->next->prev = newNode;
    
    temp->next = newNode;

    cout << "Inserted " << value << " at position " << position << "\n";
}


// Delete from beginning
void DoublyLinkedList::deleteBeginning() {
    if (!head) {
        cout << "List is empty! Cannot delete.\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head)
    head->prev = nullptr;
    else tail = nullptr;

    cout << "Deleted " << temp->data << " from the beginning.\n";
    delete temp;
}

// Delete from end
void DoublyLinkedList::deleteEnd() {
    if (!tail) {
        cout << "List is empty! Cannot delete.\n";
        return;
    }

    Node* temp = tail;
    tail = tail->prev;

    if (tail)
    tail->next = nullptr;
    else head = nullptr;

    cout << "Deleted " << temp->data << " from the end.\n";
    delete temp;
}

// Delete at a specific position
void DoublyLinkedList::deletePosition(int position) {
    if (!head) {
        cout << "List is empty! Cannot delete.\n";
        return;
    }
    if (position == 1) {
        deleteBeginning();
        return;
    }

    Node* temp = head;
    int count = 1;

    while (temp && count < position) {
        temp = temp->next;
        count++;
    }

    if (!temp) {
        cout << "Invalid position! No deletion performed.\n";
        return;
    }

    if (temp == tail) {
        deleteEnd();
        return;
    }

    // Adjust links carefully
    if (temp->prev) 
        temp->prev->next = temp->next;
    if (temp->next) 
        temp->next->prev = temp->prev;

    cout << "Deleted " << temp->data << " from position " << position << "\n";
    delete temp;
}

// Search for an element
bool DoublyLinkedList::search(int key) {
    Node* temp = head;
    int position = 1;
    while (temp) {
        if (temp->data == key) {
            cout << "Element " << key << " found at position " << position << ".\n";
            return true;
        }
        temp = temp->next;
        position++;
    }
    cout << "Element " << key << " not found in the list.\n";
    return false;
} 

// Display elements
void DoublyLinkedList::display() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "List: ";
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

/*
Time Complexity Analysis:
Operation	        Time Complexity
Insert Beginning	    O(1)
Insert End	            O(1)
Insert Position	        O(n) (in worst case)
Delete Beginning	    O(1)
Delete End	            O(1)
Delete Position	        O(n) (in worst case)
Search	                O(n)
Display	                O(n)
*/