// To search for needed elements
#include<iostream>
#include<string>
#include"sortheader.h"
using namespace std;

// function declaration
int Linear_search(int arr[],int size,int key);
int Binary_search( int arr[],int size, int key);
void printArray(int arr[], int size);

// Main block 
int main(){
int input,size;

cout<<"Enter the size of the array you want to enter : ";
cin>>size;

if (size<=0){
    cout<<"Please enter a size greater than 0";
    return 1;
}

int arr[size];
cout<<"Enter "<< size << " Elements"<<endl;
for (int i = 0; i < size; i++){
    cin>>arr[i];
}
while(true){
    cout<<"\n            Menu           \n "<<endl
    <<"1.Linear Search"<<endl
    <<"2.Binary Search"<<endl
    <<"3.Exit"<<endl
    <<"Please choose an appropriate option: ";
    cin>>input;

    switch (input){
    case 1:{
        int key;
        cout << "\nEnter the key to search : ";
        cin >> key;
        cout << "The arranged inputs are as follows"<<endl;
        printArray(arr,size);
        int index= Linear_search (arr,size,key);
        if (index != -1){
            cout << "Key found at index : "<< index <<endl;
        }else{
            cout << "Key not found "<< endl;
        }
        
        break;
    }
    case 2:{
        bubble_sort(arr,size);
        cout<<"\nSorted array for binary search"<<endl;
        printArray(arr,size);

        int key;
        cout<< "Enter the key to search : ";
        cin>>key;
        int index=Binary_search(arr,size,key);
        if (index != -1){
            cout<< "Key found at index "<<index<<endl;
        }else{
            cout<<"Key not found";
        }
        
        break;
        }
    case 3:
        cout<<"Exiting..."<<endl;
        cout<<"Program successfully exited"<<endl;
        return 0;

    default:
        cout<<"Invalid choice entered Please enter a valid choice"<<endl;
        break;
    }
}
return 0;
}

//Function definition
int Binary_search(int arr[],int size,int key){
    int left =0, right= size-1;
    while (left <= right)
    {
        int mid=left + (right - left)/2;
        if (arr[mid]==key)return mid;
        else if (arr[mid]<key)left=mid + 1;
        else right = mid-1;
    }
    return -1;
}

int Linear_search(int arr[],int size, int key){
    for (int i=0; i<size;i++){
        if (arr[i]== key )
        return i;
    }
    return -1;
}

void printArray(int arr[],int size){
    for(int i=0; i<size;i++){
        cout<< arr[i]<<" ";
    }
    cout << endl;
}