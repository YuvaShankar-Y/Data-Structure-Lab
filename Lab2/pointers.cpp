#include <iostream>
#include <cstdlib>  
using namespace std;

// Function declarations
void palindrome(int *number1);
void armstrong(int *number2);
void perfect(int *number3);
int power(int base, int exp);

int main() {
    // Dynamic memory allocation for all variables
    int *input = (int*)malloc(sizeof(int));
    int *number1 = (int*)malloc(sizeof(int));
    int *number2 = (int*)malloc(sizeof(int));
    int *number3 = (int*)malloc(sizeof(int));

    if (!input || !number1 || !number2 || !number3) { 
        cout << "Memory allocation failed!" << endl;
        return 1;
    }

    while (1) {
        cout << "          Menu          " << endl;
        cout << "1. Palindrome" << endl;
        cout << "2. Armstrong number" << endl;
        cout << "3. Perfect number" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> *input;

        switch (*input) {
            case 1:
                cout << "Enter a number to check if it is a Palindrome: ";
                cin >> *number1;
                palindrome(number1);  // Passing pointer
                break;
            case 2:
                cout << "Enter a number to check if it is an Armstrong number: ";
                cin >> *number2;
                armstrong(number2);  // Passing pointer
                break;
            case 3:
                cout << "Enter a number to check if it is a Perfect number: ";
                cin >> *number3;
                perfect(number3);  // Passing pointer
                break;
            case 4:
                cout << "Exiting..." << endl;
                cout << "Program exited successfully" << endl;
                
                // Free dynamically allocated memory
                free(input);
                free(number1);
                free(number2);
                free(number3);
                
                return 0;
            default:
                cout << "Invalid choice entered, Enter a valid choice" << endl;
                break;
        }
    }
}

// Function definitions

void palindrome(int *number1) {
    // Dynamic memory allocation for all variables
    int *original = (int*)malloc(sizeof(int));
    int *reverse = (int*)malloc(sizeof(int));
    int *temp = (int*)malloc(sizeof(int));
    
    *original = *number1;
    *reverse = 0;
    *temp = *number1;

    while (*temp > 0) {
        int *digit = (int*)malloc(sizeof(int));
        *digit = *temp % 10;
        *reverse = (*reverse * 10) + *digit;
        *temp /= 10;
        free(digit);
    }

    if (*original == *reverse) {
        cout << "The number entered is a palindrome\n" << endl;
    } else {
        cout << "The number entered is not a palindrome\n" << endl;
    }

    // Free allocated memory
    free(original);
    free(reverse);
    free(temp);
}

void armstrong(int *number2) {
    int *original = (int*)malloc(sizeof(int));
    int *sum = (int*)malloc(sizeof(int));
    int *digits = (int*)malloc(sizeof(int));
    int *temp = (int*)malloc(sizeof(int));

    *original = *number2;
    *sum = 0;
    *digits = 0;
    *temp = *number2;

    // Count the number of digits
    while (*temp > 0) {
        (*digits)++;
        *temp /= 10;
    }

    *temp = *number2;
    while (*temp > 0) {
        int *digit = (int*)malloc(sizeof(int));
        *digit = *temp % 10;
        *sum += power(*digit, *digits);
        *temp /= 10;
        free(digit);
    }

    if (*sum == *original) {
        cout << "The number is an Armstrong number\n" << endl;
    } else {
        cout << "The number is not an Armstrong number\n" << endl;
    }

    // Free allocated memory
    free(original);
    free(sum);
    free(digits);
    free(temp);
}

void perfect(int *number3) {
    int *sum = (int*)malloc(sizeof(int));
    *sum = 0;

    for (int i = 1; i < *number3; i++) {
        if (*number3 % i == 0) {
            *sum += i;
        }
    }

    if (*sum == *number3) {
        cout << "The number entered is a perfect number\n" << endl;
    } else {
        cout << "The number entered is not a perfect number\n" << endl;
    }

    // Free allocated memory
    free(sum);
}
// Function to calculate power
int power(int base, int exp) {
    int *result = (int*)malloc(sizeof(int));
    *result = 1;

    for (int i = 0; i < exp; i++) {
        *result *= base;
    }
    int final_result = *result;
    free(result);

    return final_result;
}