//To find the point won by each player in a word game
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve() {
    int n;
    cout << "\n Enter the number of words each player should enter: ";
    cin >> n;

    vector<vector<string>> words(3, vector<string>(n));
    vector<int> scores(3, 0);
    unordered_map<string, int> wordCount;

    cout << "\n Enter the words for each player:\n";
    for (int i = 0; i < 3; i++) {
        cout << "\n Player " << i + 1 << " - Please enter " << n << " words:\n";
        for (int j = 0; j < n; j++) {
            cout << "  Word " << j + 1 << ": ";
            cin >> words[i][j];
            wordCount[words[i][j]]++;
        }
    }

    // Calculate scores
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            string word = words[i][j];
            int count = wordCount[word];

            if (count == 1) scores[i] += 3;
            else if (count == 2) scores[i] += 1;
        }
    }

    // Print scores
    cout << "\n Final Scores:\n";
    for (int i = 0; i < 3; i++) {
        cout << "  Player " << i + 1 << ": " << scores[i] << " points\n";
    }
    cout << "-----------------------------------\n";
}

int main() {
    int t;
    cout << " Welcome to the Word Match Game!\n";
    cout << " Enter the number of test cases you want to run: ";
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
