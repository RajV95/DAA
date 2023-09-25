#include <bits/stdc++.h>
//BRUTE FORCE
using namespace std;

int changeCoin(vector <int> coins, int amount)
{
    int count_m=INT_MAX;
    for(auto i : coins)
    {
        if(amount%i == 0)
        {
            count_m = amount/i;
        }
    }
    
    int count =0;
    int amt=amount;
    int change=0;
    int i=coins.size()-1;
    while(i>=0)
    {
        if(amt>=coins[i])
        {
            count = amt / coins[i];
            amt = amt % coins[i];
            change = change + count;
        }
        
        else
        {
            i--;
        }
    }
    
    if(count_m < change)
    {
        return count_m;
    }
    return change;
}

int main()
{
    int amount;
    cout << "Enter amount : ";
    cin >> amount;
    vector<int> coins;
    cout << "Enter number of denominations" << endl;
    int n;
    cin >> n;
    cout << "Please enter unique denominations" << endl;
    for(int i=0;i<n;i++)
    {
        int d;
        cout << "Enter Denomination : ";
        cin >> d;
        coins.push_back(d);
    }

    sort(coins.begin(), coins.end());
    int change = changeCoin(coins, amount);
    cout << "Change : " << change << endl;
    return 0;
}
