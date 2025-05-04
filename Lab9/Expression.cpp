//Expression tree
#include <iostream>
#include <stack>
#include <cctype>
#include <limits> // For numeric_limits

using namespace std;

class ExpressionTree {
private:
    struct Node {
        char data;
        Node* left;
        Node* right;
        Node(char val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

public:
    ExpressionTree();
    bool constructExpressionTree(const string& postfix);
    void preorder();
    void inorder();
    void postorder();
};

// Main program with improved menu
int main() {
    ExpressionTree tree;
    string postfix;
    int choice;

    while (true) {
        cout << "\n=== Expression Tree Operations ===" << endl;
        cout << "1. Enter Postfix Expression" << endl;
        cout << "2. Construct Expression Tree" << endl;
        cout << "3. Preorder Traversal" << endl;
        cout << "4. Inorder Traversal" << endl;
        cout << "5. Postorder Traversal" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a valid postfix expression: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                getline(cin, postfix);
                break;
            case 2:
                if (postfix.empty()) {
                    cout << "Error: Enter a postfix expression first!" << endl;
                    break;
                }
                if (tree.constructExpressionTree(postfix))
                    cout << "Expression tree constructed successfully." << endl;
                else
                    cout << "Invalid postfix expression!" << endl;
                break;
            case 3:
                tree.preorder();
                break;
            case 4:
                tree.inorder();
                break;
            case 5:
                tree.postorder();
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
ExpressionTree::ExpressionTree() {
    root = nullptr;
}

bool ExpressionTree::constructExpressionTree(const string& postfix) {
    stack<Node*> s;
    int operandCount = 0, operatorCount = 0;

    for (char c : postfix) {
        if (isalnum(c)) { // Operand
            s.push(new Node(c));
            operandCount++;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') { // Valid Operators
            if (s.size() < 2) return false; // Invalid postfix expression
            Node* node = new Node(c);
            node->right = s.top(); s.pop();
            node->left = s.top(); s.pop();
            s.push(node);
            operatorCount++;
        } else {
            cout << "Invalid character in expression: " << c << endl;
            return false; 
        }
    }

    if (s.size() != 1 || operandCount != operatorCount + 1) return false; // Check validity
    root = s.top();
    return true;
}

void ExpressionTree::preorder() {
    if (!root) {
        cout << "Tree is empty. Construct the tree first." << endl;
        return;
    }
    stack<Node*> s;
    s.push(root);

    cout << "Preorder Traversal: ";
    while (!s.empty()) {
        Node* node = s.top(); s.pop();
        cout << node->data << " ";

        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
    }
    cout << endl;
}

void ExpressionTree::inorder() {
    if (!root) {
        cout << "Tree is empty. Construct the tree first." << endl;
        return;
    }
    stack<Node*> s;
    Node* curr = root;

    cout << "Inorder Traversal: ";
    while (!s.empty() || curr) {
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top(); s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

void ExpressionTree::postorder() {
    if (!root) {
        cout << "Tree is empty. Construct the tree first." << endl;
        return;
    }
    stack<Node*> s1, s2;
    s1.push(root);

    cout << "Postorder Traversal: ";
    while (!s1.empty()) {
        Node* node = s1.top(); s1.pop();
        s2.push(node);

        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
    cout << endl;
}
