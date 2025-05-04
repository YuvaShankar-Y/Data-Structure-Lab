//To make a menu driven queue adt to do operations using arrays of size 5
#include <iostream>
using namespace std;
#define MAX 5

//Class
class Queueadt
{
private:
    int Queue[MAX];
    int front;
    int back;
public:
    Queueadt();
    void Enqueue(int enqueue);
    void Dequeue();
    void peek();
};

int main(){
    Queueadt Q;
    int choice,enqueue;
    while (true){        
        cout<<"\n       Menu"<<endl;
        cout<<"1.Enqueue"<<endl;
        cout<<"2.Dequeue"<<endl;
        cout<<"3.Peek"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter The choice you want to choose from the menu: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter the value to Enqueue: ";
            cin>>enqueue;
            Q.Enqueue(enqueue);
            break;
        case 2:
            Q.Dequeue();
            break;
        case 3:
            Q.peek();
            break;
        case 4:
            cout<<"Exiting"<<endl;
            return 0;
        default:
            cout<<"Incorrect option entered, Enter a valid option\n"<<endl;            
            break;
        }  
    }
    return 0;
}

//Constructor
Queueadt::Queueadt()
{
    front=-1;
    back =-1;
}

void Queueadt::Enqueue(int enqueue){
    if (back==MAX-1)
    {
        cout<<"The Queue is full nothing can be added"<<endl;
        return;
    }
    if (front == -1){
        front=0;
    }
    back++;
    Queue[back]=enqueue;
    cout<<enqueue<<" Enqueued successfully"<<endl;
}

void Queueadt::Dequeue(){
    if (front>back||front==-1)
    {
        cout<<"The Queue is already empty,Nothing to Dequeue";
        return;
    }
    cout<<"Successfully Dequeued";
    front++;
    
    if (front > back) // Reset queue when all elements are dequeued
    {
        front = -1;
        back = -1;
    }

}

void Queueadt::peek(){

    if (front == -1 || front > back) // Queue is empty
    {
        cout << "Queue is Empty. No Front Element.\n";
        return;
    }

    cout << "Front Element: " << Queue[front] << endl;
}

/*
Time Complexity of Operations:
Enqueue: 𝑂(1)
O(1) – Insert at the rear in constant time.

Dequeue: 𝑂(1)
O(1) – Remove from the front in constant time.

Peek: 𝑂(1)
O(1) – Accessing the front element takes constant time.

Exit: 𝑂(1)
O(1) – Exiting the program is an instant operation.
*/