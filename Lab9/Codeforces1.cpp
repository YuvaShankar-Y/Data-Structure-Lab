//That Nene sum
#include <iostream>
#include <vector>
using namespace std;

int calculateWinners(const vector<int>& a, int n) {
    // Create array representing players (true = still in game)
    vector<bool> inGame(n+1, true);
    int remainingPlayers = n;
    bool someoneKicked;
    
    do {
        someoneKicked = false;
        vector<int> kickedThisRound;
        
        // Find players to kick
        for (int position : a) {
            int currentPos = 0;
            
            // Count until we reach the position-th remaining player
            for (int i = 1; i <= n && currentPos < position; i++) {
                if (inGame[i]) {
                    currentPos++;
                    if (currentPos == position) {
                        kickedThisRound.push_back(i);
                    }
                }
            }
        }
        
        // Kick players simultaneously
        for (int player : kickedThisRound) {
            if (inGame[player]) {
                inGame[player] = false;
                remainingPlayers--;
                someoneKicked = true;
            }
        }
        
    } while (someoneKicked);
    
    return remainingPlayers;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int k, q;
        cin >> k >> q;
        
        vector<int> a(k);
        for (int i = 0; i < k; i++) {
            cin >> a[i];
        }
        
        vector<int> n_values(q);
        for (int i = 0; i < q; i++) {
            cin >> n_values[i];
        }
        
        for (int n_i : n_values) {
            cout << calculateWinners(a, n_i) << endl;
        }
    }
    
    return 0;
}