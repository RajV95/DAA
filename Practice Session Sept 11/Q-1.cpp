#include<bits/stdc++.h>
using namespace std;
bool ispalin(int l, int r, string str){
    while(l<r){
        if(str[l]!=str[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}
int f(int i, int n, string &str, vector<int> &dp){
    if(i==n) return 0;
    if(dp[i]!= -1) return dp[i];
    int minCost = INT_MAX;
    for(int j=i;j<n;j++){
        if(ispalin(i, j, str)){
            int cost = 1 + f( j+1, n, str,dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}
int palinpart(string str){
    int n = str.size();
    vector<int> dp(n,-1);
    return f(0,n,str,dp)-1;
}
int main(){
    cout<<"Enter your String"<<endl;
    string str;
    getline(cin,str);
    cout<<"The minimun Number of partitions is : "<<palinpart(str)+1<<endl;
}