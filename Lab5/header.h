//The header file
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
using namespace std;

class Process {
public:
    int time;
    Process* next;

    Process(int t) {
        time = t;
        next = nullptr;
    }
};

class RoundRobinScheduler {
private:
    Process* tail;
    int timeSlice;

public:
    RoundRobinScheduler(int slice) {
        tail = nullptr;
        timeSlice = slice;
    }

    // Insert process at the end of the queue
    void insertProcess(int time) {
        Process* newProcess = new Process(time);
        if (!tail) {
            tail = newProcess;
            tail->next = tail;
        } else {
            newProcess->next = tail->next;
            tail->next = newProcess;
            tail = newProcess;
        }
        cout << "Process with time " << time << " added to the queue.\n";
    }

    // Execute process
    void execute() {
        if (!tail) {
            cout << "No processes to execute.\n";
            return;
        }

        Process* head = tail->next;
        cout << "Executing process with time " << head->time << "...\n";
        head->time -= timeSlice;

        if (head->time <= 0) {
            if (head == tail) {
                delete head;
                tail = nullptr;
            } else {
                tail->next = head->next;
                delete head;
            }
            cout << "Process completed.\n";
        } else {
            tail = head;
            cout << "Process reinserted with remaining time " << tail->time << ".\n";
        }
    }

    // Exit scheduler and free memory
    void exitScheduler() {
        while (tail) {
            Process* temp = tail->next;
            if (temp == tail) {
                delete temp;
                tail = nullptr;
            } else {
                tail->next = temp->next;
                delete temp;
            }
        }
        cout << "Scheduler exited. All processes cleared.\n";
    }
};

#endif // HEADER_H