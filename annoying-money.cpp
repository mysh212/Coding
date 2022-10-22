// Author : ysh
// 10/21/2022 Fri  9:09:09.77
// https://tioj.ck.tp.edu.tw/problems/1066
#include<bits/stdc++.h>
using namespace std;
const int mn[] = {1,5,10,20,50};
int check(int n,vector<int>&f,vector<int>&b) {
    int ff = 0,cc = 0;
    // vector<int>all(f.begin(),f.end());
    for(int i = 0;i<5;i++) {
        // all[i] = all[i] + b[i];
        ff = ff + f[i] * mn[i];
        // bb = bb + b[i] * mn[i];
        cc = cc + f[i];
    }
    ff = ff - n;
    // bb = bb + n;
    int coins = 0;
    for(int i = 4;i >= 0;i--) {
        coins = coins + min(f[i] + b[i],ff / mn[i]);
        ff -= min((f[i] + b[i]) * mn[i],(ff / mn[i]) * mn[i]);
    }
    return coins;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int m;cin>>m;
        vector<int>f(5),b(5);
        for(int &i : f) {
            cin>>i;
        }
        for(int &i : b) {
            cin>>i;
        }
        cout<<check(m,f,b)<<"\n";
    }
    return 0;
}