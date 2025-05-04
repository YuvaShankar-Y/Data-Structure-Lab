//Binary Search Tree
#include <iostream>
using namespace std;

class BinarySearchTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };
    
    Node* root;
    
public:
    BinarySearchTree();
    void insert(int val);
    void preorder();
    void inorder();
    void postorder();
    bool search(int val);
};

// Main program with menu-driven interface
int main() {
    BinarySearchTree bst;
    int choice, value;
    
    while (true) {
        cout << "\n=== Binary Search Tree Operations ===" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Preorder" << endl;
        cout << "3. Inorder" << endl;
        cout << "4. Postorder" << endl;
        cout << "5. Search" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                bst.insert(value);
                cout << "Value " << value << " inserted successfully." << endl;
                break;
            case 2:
                bst.preorder();
                break;
            case 3:
                bst.inorder();
                break;
            case 4:
                bst.postorder();
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                if (bst.search(value)) {
                    cout << "Value " << value << " found in the tree." << endl;
                } else {
                    cout << "Value " << value << " not found in the tree." << endl;
                }
                break;
            case 6:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}

// Function Definitions
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

void BinarySearchTree::insert(int val) {
    Node* newNode = new Node(val);
    if (root == nullptr) {
        root = newNode;
        return;
    }
    Node* current = root;
    Node* parent = nullptr;
    while (current != nullptr) {
        parent = current;
        if (val < current->data) {
            current = current->left;
        } else if (val > current->data) {
            current = current->right;
        } else {
            return; // Avoid duplicate values
        }
    }
    if (val < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

void BinarySearchTree::preorder() {
    cout << "Preorder Traversal: ";
    Node* stack[100];
    int top = -1;
    Node* current = root;
    while (current != nullptr || top != -1) {
        while (current != nullptr) {
            cout << current->data << " ";
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        current = current->right;
    }
    cout << endl;
}

void BinarySearchTree::inorder() {
    cout << "Inorder Traversal: ";
    Node* stack[100];
    int top = -1;
    Node* current = root;
    while (current != nullptr || top != -1) {
        while (current != nullptr) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        cout << current->data << " ";
        current = current->right;
    }
    cout << endl;
}

void BinarySearchTree::postorder() {
    cout << "Postorder Traversal: ";
    Node* stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;
    while (top1 != -1) {
        Node* current = stack1[top1--];
        stack2[++top2] = current;
        if (current->left) stack1[++top1] = current->left;
        if (current->right) stack1[++top1] = current->right;
    }
    while (top2 != -1) {
        cout << stack2[top2--]->data << " ";
    }
    cout << endl;
}

bool BinarySearchTree::search(int val) {
    Node* current = root;
    while (current != nullptr) {
        if (current->data == val) {
            return true;
        } else if (val < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}
