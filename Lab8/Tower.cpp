#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
    int n;
    cout<<"Enter the number of towers: ";
    cin>>n;
    int arr[n]; 

    cout << "Enter the blocks in each tower: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

sort(arr+1,arr+n);

for (int i = 0; i < n; i++)
{
    arr[0]=(arr[0]+arr[i]+1)/2;
}
cout<<"Maximum blocks in Tower 1: " << arr[0] << "\n";
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
