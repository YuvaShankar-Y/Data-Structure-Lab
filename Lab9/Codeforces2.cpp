//Strengths of ppl 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> strengths(n);
        for (int i = 0; i < n; i++) {
            cin >> strengths[i];
        }
        
        // Calculate differences for each participant
        for (int i = 0; i < n; i++) {
            int maxOtherStrength = 0;
            
            // Find max strength excluding the current participant
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    maxOtherStrength = max(maxOtherStrength, strengths[j]);
                }
            }
            
            // Output the difference
            cout << (strengths[i] - maxOtherStrength);
            if (i < n - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}