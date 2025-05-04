//For making separate chaining in hash adt
#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

//Classees
class Node {
public:
    int key;
    Node* next;
    Node(int k);
};

class HashTable {
private:
    Node* table[TABLE_SIZE];
    int hashFunc(int key);

public:
    HashTable();
    void insert(int key);
    void remove(int key);
    void search(int key);
};

//Main menu
int main() {
    HashTable ht;
    int choice, key;

    do {
        cout << "\n=== Hash Table Menu (Separate Chaining) ===\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                ht.insert(key);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                ht.remove(key);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                ht.search(key);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}

//Definitions After main 

Node::Node(int k) {
    key = k;
    next = nullptr;
}

HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = nullptr;
}

int HashTable::hashFunc(int key) {
    return key % TABLE_SIZE;
}

void HashTable::insert(int key) {
    int index = hashFunc(key);
    Node* newNode = new Node(key);
    newNode->next = table[index];
    table[index] = newNode;
    cout << "Inserted key " << key << " at index " << index << ".\n";
}

void HashTable::remove(int key) {
    int index = hashFunc(key);
    Node* curr = table[index];
    Node* prev = nullptr;

    while (curr != nullptr) {
        if (curr->key == key) {
            if (prev == nullptr)
                table[index] = curr->next;
            else
                prev->next = curr->next;

            delete curr;
            cout << "Deleted key " << key << " from index " << index << ".\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    cout << "Key " << key << " not found.\n";
}

void HashTable::search(int key) {
    int index = hashFunc(key);
    Node* curr = table[index];

    while (curr != nullptr) {
        if (curr->key == key) {
            cout << "Key " << key << " found at index " << index << ".\n";
            return;
        }
        curr = curr->next;
    }

    cout << "Key " << key << " not found.\n";
}
