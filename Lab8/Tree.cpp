//To make a Tree adt using character binary tree
#include <iostream>
using namespace std;

class Node {
public:
    char data;  
    Node* left;
    Node* right;
    
    Node(char value) {  
        data = value;
        left = right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree();
    void insert(char value);  
    void inorder();
    void preorder();
    void postorder();
    void search(char value);  

private:
    Node* insertRecursive(Node* node, char value);
    void inorderRecursive(Node* node);
    void preorderRecursive(Node* node);
    void postorderRecursive(Node* node);
    bool searchRecursive(Node* node, char value);
};

// Main function with menu-driven approach
int main() {
    BinaryTree bt;
    int choice;
    char value;  

    while (1) {
        cout << "\nBinary Tree Menu:";
        cout << "\n1. Insert";
        cout << "\n2. Inorder Traversal";
        cout << "\n3. Preorder Traversal";
        cout << "\n4. Postorder Traversal";
        cout << "\n5. Search";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter character to insert: ";
                cin >> value;
                bt.insert(value);
                break;
            case 2:
                bt.inorder();
                break;
            case 3:
                bt.preorder();
                break;
            case 4:
                bt.postorder();
                break;
            case 5:
                cout << "Enter character to search: ";
                cin >> value;
                bt.search(value);
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid option! Please try again.\n";
        }
    }
}

// Constructor
BinaryTree::BinaryTree() {
    root = nullptr;
}

// Insert function
void BinaryTree::insert(char value) {
    root = insertRecursive(root, value);
    cout << "'" << value << "' inserted successfully!\n";
}

Node* BinaryTree::insertRecursive(Node* node, char value) {
    if (node == nullptr) {
        return new Node(value);
    }
    if (value < node->data) {
        node->left = insertRecursive(node->left, value);
    } else {
        node->right = insertRecursive(node->right, value);
    }
    return node;
}

// Inorder Traversal
void BinaryTree::inorder() {
    if (root == nullptr) {
        cout << "Tree is empty.\n";
        return;
    }
    cout << "Inorder Traversal: ";
    inorderRecursive(root);
    cout << endl;
}

void BinaryTree::inorderRecursive(Node* node) {
    if (node == nullptr) return;
    inorderRecursive(node->left);
    cout << node->data << " ";
    inorderRecursive(node->right);
}

// Preorder Traversal
void BinaryTree::preorder() {
    if (root == nullptr) {
        cout << "Tree is empty.\n";
        return;
    }
    cout << "Preorder Traversal: ";
    preorderRecursive(root);
    cout << endl;
}

void BinaryTree::preorderRecursive(Node* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    preorderRecursive(node->left);
    preorderRecursive(node->right);
}

// Postorder Traversal
void BinaryTree::postorder() {
    if (root == nullptr) {
        cout << "Tree is empty.\n";
        return;
    }
    cout << "Postorder Traversal: ";
    postorderRecursive(root);
    cout << endl;
}

void BinaryTree::postorderRecursive(Node* node) {
    if (node == nullptr) return;
    postorderRecursive(node->left);
    postorderRecursive(node->right);
    cout << node->data << " ";
}

// Search function
void BinaryTree::search(char value) {
    if (searchRecursive(root, value)) {
        cout << "'" << value << "' found in the tree!\n";
    } else {
        cout << "'" << value << "' not found in the tree!\n";
    }
}

bool BinaryTree::searchRecursive(Node* node, char value) {
    if (node == nullptr) return false;
    if (node->data == value) return true;
    if (value < node->data)
        return searchRecursive(node->left, value);
    return searchRecursive(node->right, value);
}
