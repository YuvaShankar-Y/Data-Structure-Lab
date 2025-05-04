#include <iostream>
#include <algorithm>
using namespace std;

void sortArray(int arr[],int numElements){

        //Sort from the second element to the end
        std::sort(arr+1,arr+numElements)
}
int check(int arr[],int n){
    int temp=arr[0];
    int i=1;
    for(; i < n;i++)
    {
        if(arr[0]<arr[i]){
            return i;
        }
    }
    return 0;
}
int sum(int arr[],int n,int i){
    if (i==0){
        return arr[0];
    }
    while(i<n)
    {
        arr[0]=(arr[0]+arr[i]+1)/2;
        i++;
    }
    return arr[0];
}
int main(){
    int t;
    int n,temp;
    cin>>t;
    while(t>0){
        cin>>n;
        temp=n;
        int arr[n];
        int i=0;
    while(n>0){
        cin>>arr[i];
        i++;
        n--;
    }
    n=temp;
    sortArray(arr,n);
    cout<<sum(arr,n,check(arr,n))<<"\n";
    t--;
    }
    return 0;
}