//To write a menu driven program to implement list ADT using an array of size 5 ,maintaining proper boundary conditions
#include<iostream>
#include<cstdio>
using namespace std;

// Class
class list
{
private:
    int listadt[5];
    int size;
public:
    list(){
        size=0;
        for (int i = 0; i < 5; i++)
        {
            listadt[i]=0;
        }
    }
        //Function declaration
        void insertbeginning(int beginning);
        void insertend(int end);
        void insertposition(int position,int posnum);
        void deletebeginning();
        void deleteend();
        void deleteposition(int position);
        void search(int num);
        void display();
        void rotate(int right);
        void exit();
};

//Main block
int main(){
    list le;
    int choice,beginning,end,position,posnum,num,right;
while (1)
{
    cout<<"\n==========Menu==========\n"<<endl;
    cout<<"1.Insert Beginning"<<endl;
    cout<<"2.Insert End"<<endl;
    cout<<"3.Insert Position"<<endl;
    cout<<"4.Delete Beginning"<<endl;
    cout<<"5.Delete End"<<endl;
    cout<<"6.Delete Position"<<endl;
    cout<<"7.Search"<<endl;
    cout<<"8.Display"<<endl;
    cout<<"9.Rotate"<<endl;
    cout<<"10.Exit"<<endl;
    cout<<"Enter the option you want to choose from the Menu: ";
    cin>>choice;

    switch(choice){
        case 1:
            cout<<"Enter the number to inserted at the Beginning: ";
            cin>>beginning;
            le.insertbeginning(beginning);
        break;
        case 2:
            cout<<"Enter the number to be inserted at the End: ";
            cin>>end;
            le.insertend(end);
        break;
        case 3:
            cout<<"Enter the position you want to add the number: ";
            cin>>position;
            cout<<"Enter the number to be inserted at position " << position <<": ";
            cin>>posnum;
            le.insertposition(position,posnum);
        break;
        case 4:
            le.deletebeginning();
        break;
        case 5:
            le.deleteend();
        break;
        case 6:
            cout<<"Enter the position in which you want to delete the number: ";
            cin>>position;
            le.deleteposition(position);
        break;
        case 7:
            cout<<"Enter the number you want to search for in the given list: ";
            cin>>num;
            le.search(num);
        break;
        case 8:
            cout<<"List Elements: ";
            le.display();
        break;
        case 9:
            cout << "Enter number of right rotations: ";
            cin >> right;
            le.rotate(right);
        break;
        case 10:
            le.exit();
            return 0;
        default:
           cout<<"Invalid choice entered , Please enter a valid choice"<<endl;
        break;
    }
}
    return 0;
}

//Function definition
void list::insertbeginning(int beginning){
    if (size>=5)
    {
        cout<<"The list is full ,cannot insert.";
        return;
    }
    for (int i = size; i >0; i--)
    {
        listadt[i]=listadt[i-1];
    }
    listadt[0]=beginning; 
    size++;
    cout<<"The number has been placed at the Beginning Successfully\n";

    
}

void list::insertend(int end){
    if (size>=5){
        cout<<"The list is full ,cannot insert";
        return;
    }
    listadt[size]=end;
    size++;
    cout << "Inserted at the end successfully.\n";    
}

void list::insertposition(int position,int posnum){
    if (size>=5){
        cout<<"The list is full ,cannot insert";
        return;
    }
    if (position<0||position>size){
        cout<<"Invalid position entered , Please enter a valid position\n";
        return;
    }
    for (int i = size; i >position ; i--)
    {
        listadt[i]=listadt[i-1];
    }
    listadt[position]=posnum;   
    size++;
    cout << "Inserted at position " << position << " successfully.\n"; 
}

void list::deletebeginning(){
    if(size==0){
        cout<<"The list is empty, Nothing to delete";
        return ;
    }
    for (int i = 0; i < size-1; i++)
    {
        listadt[i]=listadt[i+1];
    }
    size--;    
    cout<<"Successfully deleted The number at the beginning"<<endl;
}

void list::deleteend(){
if(size==0){
    cout<<"The list is empty, Nothing to delete";
    return;
}
size--;
listadt[size]=0;
cout<<"The number at the end was successfully deleted"<<endl;
}

void list::deleteposition(int position){
if (size==0){
    cout<<"The list is empty , Nothing to delete";
    return;
}
if (position<0||position>=size){
    cout<<"Invalid position entered, Please enter a valid position";
    return;
}
for(int i=position;i<size-1;i++){
    listadt[i]=listadt[i+1];
}
size--;
cout<<"The number at the "<<position<<"Position was deleted successfully";
}

void list::search(int num){
for (int  i = 0; i < size; i++)
{
    if (listadt[i]==num)
    {
        cout<<"The element is found at index "<< i;
        return;
    }
}
cout<<"The element not found in the array";
}

void list::display(){
    if (size==0){
        cout<<"The list is empty , No elements found";
        return;
    }
    for (int i = 0; i <size; i++)
    {
        cout <<listadt[i]<<" ";
    }
    cout <<endl;
}

void list::rotate(int right){
    if (size==0)
    {
        cout<<"The list is empty , No elements found";
        return;
    }
    right=right%size;
    for (int i = 0; i < right; i++)
    {
        int temp=listadt[size-1];
        for (int j=size-1; j >0; j--)
        {
            listadt[j]=listadt[j-1];
        }
        listadt[0]=temp;
    }
    cout << "Rotated " << right << " times successfully.\n";
}

void list:: exit(){
cout<<"Exiting ..."<<endl;
cout<<"Successfully exited"<<endl;
}
