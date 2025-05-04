#include "stringprocess.h"  // Include the header file

int main() {
    string input;
    cout << "Enter the string: ";
    cin >> input;

    string output = StringProcessor::processString(input);
    cout << "Output: " << output << endl;

    return 0;
}

/*
Chosen ADT & Data Structure:
Abstract Data Type (ADT): Stack ADT
Reasons:
    (*)Follows Last-In-First-Out (LIFO):
    (*)When encountering a '+', the last non-'+' character should be removed, which is efficiently handled by a stack.
*/
