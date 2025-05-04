// TO write a menu driven program to calculate and display the area of a square,cube,cuboid,rectangle
#include <iostream>
using namespace std;

class Square
{
private:
    int len;
public:
    Square(){
        len=1;
    }
    void setlen(int);
    void area();
};

class Cube
{
private:
    int len;
public:
    Cube(){
        len=1;
    }
    void setlen(int);
    void area();
};

class Rectangle
{
private:
    int len,bre;
public:
    Rectangle(){
        len=1,bre=1;
    }
    void setlen(int);
    void setbre(int);
    void area();

};
class Cuboid{
    private:
    int len,bre,hei;
    public:
    Cuboid(){
        len=1,bre=1,hei=1;
    }
    void setlen(int);
    void setbre(int);
    void sethei(int);
    void area();
};

int main(){
int input,size1,size2,size3;
Square sq;
Cube cb;
Rectangle re;
Cuboid cd;

while (1)
{
cout<<"\n                Menu"<<endl;
cout<<"1.Square"<<endl;
cout<<"2.Cube"<<endl;
cout<<"3.Rectangle"<<endl;
cout<<"4.Cuboid"<<endl;
cout<<"5.Exit\n"<<endl;
cout<<"Enter the option from menu for which you want to find the area :  ";
cin>>input;

switch(input){
case 1:
    cout<<"Enter the side of the square : "<<endl;
    cin >> size1;
    sq.setlen(size1);
    sq.area();
    break;
case 2:
    cout<<"Enter the side of the cube : "<<endl;
    cin>>size1;
    cb.setlen(size1);
    cb.area();
    break;
case 3:
    cout<<"Enter the length of the rectangle"<<endl;
    cin>>size1;
    cout<<"Enter the breadth of the rectangle"<<endl;
    cin>>size2;
    re.setlen(size1);
    re.setbre(size2);
    re.area();
    break;
case 4:
    cout<<"Enter the length of the Cuboid : ";
    cin>>size1;
    cout<<"Enter the breadth of the Cuboid : ";
    cin>>size2;
    cout<<"Enter the height of the Cuboid : ";
    cin>>size3;
    cd.setlen(size1);
    cd.setbre(size2);
    cd.sethei(size3);
    cd.area();
    break; 
case 5:
    cout<<"Exiting ..."<<endl;
    cout<<"Program exited successfully !!"<<endl;
    return 1;
    break;
default:
    cout<<"Enter a valid input !!"<<endl;
    break;
}
}
    return 0;
}
void Square::setlen(int temp){
    len = temp;
}
void Square::area(){
cout<<"The area of the square is : " << len*len << " Units"<< endl;
}

void Cube::setlen(int temp){
    len=temp;
}

void Cube::area(){
    cout<<"The area of the cube is : "<< 6*(len*len) << " Units"<<endl;
}

void Rectangle::setlen(int temp){
    len=temp;
}

void Rectangle::setbre(int temp){
    bre=temp;
}

void Rectangle::area(){
    cout<<"The area of the rectangle is : "<< len*bre<< " Units"<<endl;
}

void Cuboid::setlen(int temp){
    len=temp;    
}

void Cuboid::setbre(int temp){
    bre=temp;
}

void Cuboid::sethei(int temp){
    hei=temp;
}

void Cuboid::area(){
    cout<<"The area of the cuboid is "<< 2*((len*bre)+(bre*hei)+(len*hei))<< " Units"<<endl;
}
