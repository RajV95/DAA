#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

vector<float> unitprofit;

map<float, int> knapsack(vector<int> a, vector<int> pf, int weight) {
    map<float, int> profit;
    for (int i = 0; i < a.size(); i++) {
        profit.insert({ pf[i] / (float)a[i], i });
        unitprofit.push_back(pf[i] / (float)a[i]);
    }
    sort(unitprofit.begin(), unitprofit.end());
    for (auto i : profit) {
        cout << i.first << " " << i.second << " ";
    }
    cout << endl;
    return profit;
}

int main() {
    vector<int> a = { 1, 7, 3, 8, 5, 6, 2, 4 };
    vector<int> pf = { 20, 30, 5, 15, 13, 14, 23, 12 };
    int weight;
    cin >> weight;
    int profit1 = 0;
    vector<int> ans;

    map<float, int> profit = knapsack(a, pf, weight);
    int i = unitprofit.size() - 1;
    while (weight != 0 && i >= 0) {
        if (a[profit[unitprofit[i]]] <= weight) {
            cout << "unit profit: " << unitprofit[i] << endl;
            ans.push_back(a[profit[unitprofit[i]]]);
            profit1 += pf[profit[unitprofit[i]]];
            weight -= a[profit[unitprofit[i]]];
            i--;
        }
        else {
            i--;
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    cout << "profit: " << profit1 << endl;
    return 0;
}
