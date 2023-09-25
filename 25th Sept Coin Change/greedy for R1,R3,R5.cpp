#include<iostream>
#include<vector>
using namespace std;
void change(int x){
    vector<int> coins;
    int deno5 = x / 5;
    int remain5 = x % 5;
    cout<<"Deno of 5 : "<<deno5<<endl;
    coins.push_back(deno5);
    if(remain5 >= 3){
        int deno3 = remain5 / 3;
        int remain3 = remain5 % 3;
        cout<<"deno of 3 : "<<deno3<<endl;
        coins.push_back(deno3);
        if(remain3 == 0){

        }
        else{
            cout<<"deno of 1 : "<<deno3<<endl;
        }
    }
    else if(remain5 >=2){
        cout<<"deno of 1: " << remain5 << endl ;
        coins.push_back(remain5);
    }
    int sum = 0;
    for(int i =0;i<coins.size();i++){
        sum = sum + coins[i];
    }
    cout<<"Total No. of coins : "<<sum<<endl;

}
int main(){
    int x;
    cout<<"Enter your denomination: ";
    cin>>x;
    int r1=1,r3=3,r5=5;
    change(x);
    //performing greddy strategy for R1,R3,R5 denominations

}