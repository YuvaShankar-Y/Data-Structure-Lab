/*
Design 1: Counter-based approach
Time: O(n), Space: O(1)
Simple and optimal for only '(' and ')'.

Design 2: Stack-based approach
Time: O(n), Space: O(n)
Needed for all types of brackets ( (), {}, [] ).

Final Choice: Counter-based is optimal here
Reason: Given only '(' and ')', counter uses less space (O(1)) and works efficiently.
*/


#include <iostream>
using namespace std;

// function declaration
bool checkBalanceCounter(const string& str);

//Main function 
int main() {
    int choice;
    string input;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
    
        switch (choice) {
            case 1:
                cout << "Enter string of parentheses: ";
                cin >> input;
    
                if (checkBalanceCounter(input)) {
                    cout << "Parentheses are Balanced." << endl;
                } else {
                    cout << "Parentheses are NOT Balanced." << endl;
                }
                break;
    
            case 2:
                cout << "Exiting the program." << endl;
                return 0;  // Immediate exit
    
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}

//Function definition
bool checkBalanceCounter(const string& str) {
    for (char ch : str) {
        if (ch != '(' && ch != ')') {
            cout << "Invalid character detected! Only '(' and ')' are allowed.\n";
            return false;
        }
    }

    int counter = 0;
    for (char ch : str) {
        if (ch == '(') {
            counter++;
        } else if (ch == ')') {
            counter--;
        }
        if (counter < 0) {
            return false;  // More closing brackets than opening
        }
    }
    return counter == 0;
}

