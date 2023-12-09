#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> winner(string arr[], int n) {
    unordered_map<string, int> votes;

    // Count votes for each candidate
    for (int i = 0; i < n; ++i) {
        votes[arr[i]]++;
    }

    int maxVotes = 0;
    string winnerName = "";

    // Find the candidate with the maximum votes
    for (auto it = votes.begin(); it != votes.end(); ++it) {
        if (it->second > maxVotes || (it->second == maxVotes && it->first < winnerName)) {
            maxVotes = it->second;
            winnerName = it->first;
        }
    }

    // Return the winner's name and number of votes
    return {winnerName, to_string(maxVotes)};
}

int main() {
    int n = 13;
    string arr[] = {"john","johnny","jackie","johnny","john","jackie","jamie","jamie","john","johnny","jamie","johnny","john"};

    vector<string> result = winner(arr, n);
    cout << result[0] << " " << result[1] << endl; // Output: john 4

    return 0;
}
