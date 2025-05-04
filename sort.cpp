    // c++ program to create a menu driven search program
    #include <iostream>
    #include<string>
    using namespace std;

    // function declaration
    void bubble_sort(int arr[],int n);
    void selection_sort(int arr[],int n);
    void insertion_sort(int arr[],int n);

    int main(){
    int choice,input,n;
    int arr[input];

    while(true){
    cout<< "\n            Menu           \n "<<endl;
    cout<<"1.Bubbble sort"<<endl;
    cout<<"2.Selection sort"<<endl;
    cout<<"3.Insertion sort"<<endl;
    cout<<"4.Exit"<<endl;
    cout<< "Please select the choice you would like to choose: ";
    cin >> choice;
    
    switch (choice)
    {
    case 1:
        cout << "Enter the number of elements you want to add to the array for sorting: ";
        cin >> input;
        cout <<"Enter the elements"<<endl;
        for(int i=0;i<input;i++){
            cin>>arr[i];
        }
        bubble_sort(arr,input);    
        cout << "Sorted array: ";
        for (int i = 0; i < input; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
        break;
    case 2:
        cout << "Enter the number of elements you want to add to the array for sorting: ";
        cin >> input;
        cout <<"Enter the elements"<<endl;
        for(int i=0;i<input;i++){
            cin>>arr[i];
        }
        selection_sort(arr,input);    
        cout << "Sorted array: ";
        for (int i = 0; i < input; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;        
        
        break;
    case 3:
        cout << "Enter the number of elements you want to add to the array for sorting: ";
        cin >> input;
        cout <<"Enter the elements"<<endl;
        for(int i=0;i<input;i++){
            cin>>arr[i];
        }
        insertion_sort(arr,input);    
        cout << "Sorted array: ";
        for (int i = 0; i < input; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;        
        break;
    case 4:
        cout<<"Exiting..."<<endl;
        cout<<"Program successfully exited"<<endl;
        return 0;
    default:
        cout<<"Invalid choice entered!"<<endl;
        break;
    }
    }
    return 0;
    }
    //Function for bubble sort
    void bubble_sort(int arr[],int n){
        for (int i =0;i<n-1;i++){
            for (int j=0;j<n-i-1; j++){
                if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                }
            }
        }
    }

    //function for selection sort
    void selection_sort(int arr[],int n){
        for (int i=0;i<n-1;i++){
            int min_index=i;
            for (int j=i+1;j<n;j++){
                if (arr[j]<arr[min_index]){
                    min_index=j;
                }
            }
            int temp=arr[min_index];
            arr[min_index]=arr[i];
            arr[i]=temp;
        }
    }

    //function for insertion sort
    void insertion_sort(int arr[],int n){
        for (int i=1;i<n;i++){
            int key=arr[i];
            int j=i-1;
            while (j>=0&&arr[j]>key)
            {
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
    }



