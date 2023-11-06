#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> memo;

int maximizeCoins(vector<int>& pots, int left, int right, bool isPlayerA) {
    if (left > right) {
        return 0;
    }

    string key = to_string(left) + "|" + to_string(right) + "|" + to_string(isPlayerA);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    int leftChoice = pots[left] + min(maximizeCoins(pots, left + 2, right, !isPlayerA),
                                       maximizeCoins(pots, left + 1, right - 1, !isPlayerA));
    int rightChoice = pots[right] + min(maximizeCoins(pots, left + 1, right - 1, !isPlayerA),
                                         maximizeCoins(pots, left, right - 2, !isPlayerA));

    int maxCoins = isPlayerA ? max(leftChoice, rightChoice) : min(leftChoice, rightChoice);
    memo[key] = maxCoins;
    return maxCoins;
}

int main() {
    vector<int> pots = {5, 7, 3, 4};
    int totalCoins = maximizeCoins(pots, 0, pots.size() - 1, true);

    cout << "Player A: " << totalCoins << " coins" << endl;
    cout << "Player B: " << accumulate(pots.begin(), pots.end(), 0) - totalCoins << " coins" << endl;

    return 0;
}
