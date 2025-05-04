//For making quadratic probing in hash adt
#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;
const int EMPTY = -1;
const int DELETED = -2;

//Class
class HashTable {
private:
    int table[TABLE_SIZE];
    int hashFunc(int key);

public:
    HashTable();
    void insert(int key);
    void remove(int key);
    void search(int key);
    void display();
};

// MAIN MENU
int main() {
    HashTable ht;
    int choice, key;

    do {
        cout << "\n=== Hash Table Menu (Quadratic Probing) ===\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
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
                ht.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

//DEFINITIONS AFTER MAIN

HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = EMPTY;
}

int HashTable::hashFunc(int key) {
    return key % TABLE_SIZE;
}

void HashTable::insert(int key) {
    int index = hashFunc(key);
    int i = 0;

    while (table[(index + i * i) % TABLE_SIZE] != EMPTY &&
           table[(index + i * i) % TABLE_SIZE] != DELETED &&
           table[(index + i * i) % TABLE_SIZE] != key) {
        i++;
        if (i == TABLE_SIZE) {
            cout << "Hash table is full. Cannot insert.\n";
            return;
        }
    }

    int newIndex = (index + i * i) % TABLE_SIZE;
    if (table[newIndex] == key) {
        cout << "Duplicate key. Already exists.\n";
    } else {
        table[newIndex] = key;
        cout << "Inserted key " << key << " at index " << newIndex << ".\n";
    }
}

void HashTable::remove(int key) {
    int index = hashFunc(key);
    int i = 0;

    while (table[(index + i * i) % TABLE_SIZE] != EMPTY) {
        int probeIndex = (index + i * i) % TABLE_SIZE;

        if (table[probeIndex] == key) {
            table[probeIndex] = DELETED;
            cout << "Key " << key << " deleted from index " << probeIndex << ".\n";
            return;
        }
        i++;
        if (i == TABLE_SIZE) break;
    }

    cout << "Key " << key << " not found.\n";
}

void HashTable::search(int key) {
    int index = hashFunc(key);
    int i = 0;

    while (table[(index + i * i) % TABLE_SIZE] != EMPTY) {
        int probeIndex = (index + i * i) % TABLE_SIZE;

        if (table[probeIndex] == key) {
            cout << "Key " << key << " found at index " << probeIndex << ".\n";
            return;
        }
        i++;
        if (i == TABLE_SIZE) break;
    }

    cout << "Key " << key << " not found.\n";
}

void HashTable::display() {
    cout << "\nHash Table Contents:\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << i << ": ";
        if (table[i] == EMPTY)
            cout << "EMPTY";
        else if (table[i] == DELETED)
            cout << "DELETED";
        else
            cout << table[i];
        cout << endl;
    }
}
