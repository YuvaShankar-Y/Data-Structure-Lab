//To implement round robin scheduling
#include "header.h"

int main() {
    int timeSlice;
    cout << "Enter fixed time slot for Round-Robin scheduling: ";
    cin >> timeSlice;

    RoundRobinScheduler scheduler(timeSlice);
    int choice, time;

    while (true) {
        cout << "\n1. Insert Process\n";
        cout << "2. Execute\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter process time: ";
                cin >> time;
                scheduler.insertProcess(time);
                break;
            case 2:
                scheduler.execute();
                break;
            case 3:
                scheduler.exitScheduler();
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
/*
    Time Complexity Analysis
Operation	    Time Complexity
Insert Process	    O(1)
Execute Process	    O(1)
Exit	            O(1)
*/