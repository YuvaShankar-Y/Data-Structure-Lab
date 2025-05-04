// No repetition set of numbers and giving their steps taken as output
#include<iostream>
#include<vector>
using namespace std;

void solve() {
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;

    vector<int> a(n);
    vector<int> seen;

    cout << "Enter " << n << " elements (space separated): ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int count = 0;

    for (int i = n - 1; i >= 0; i--) {
        bool found = false;
        for (int j = 0; j < seen.size(); j++) {
            if (seen[j] == a[i]) {
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
        seen.push_back(a[i]);
        count++;
    }

    cout << "Minimum steps to remove duplicates from the end: " << (n - count) << "\n\n";
}

int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
