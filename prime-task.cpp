// Author : ysh
// 10/21/2022 Fri  8:27:03.37
// https://tioj.ck.tp.edu.tw/problems/1067
#include<bits/stdc++.h>
using namespace std;
#define R m
int check(int n,int m,vector<int> &f) {
    vector<vector<int>>mark(2,vector<int>(R));
    mark[0][f[0] % m]++;
    for(int i = 0,len = n - 1;i<len;i++) {
        // bool c = i & 1;
        mark[i & 1][f[i] % R] = max(mark[i & 1][f[i] % R],1);
        for(int j = 0;j<R;j++) {
            if(mark[i & 1][j] != 0) {
                mark[!(i & 1)][(j * 10 + f[i + 1]) % R] = max(mark[!(i & 1)][(j * 10 + f[i + 1]) % R],mark[i & 1][j] + 1);
                mark[!(i & 1)][j] = max(mark[i & 1][j],mark[!(i & 1)][j]);
            }
        }
    }
    int ans = 0;
    for(auto i : mark) {
        for(int &j : i) {
            cerr<<j<<" ";
        }
        cerr<<"\n";
    }
    for(int i = 0;i<m;i++) {
        if(mark[!(n & 1)][i] != 0 && __gcd(i,m) == 1) {
            ans = max(ans,mark[!(n & 1)][i]);
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    while(cin>>a>>b) {
        if(a == 0 && b == 0) break;
        vector<int>f(a);
        for(int &i : f) {
            cin>>i;
        }
        // if(b == 1) {
        //     cout<<"0\n";
        //     continue;
        // }
        cout<<check(a,b,f)<<"\n";
    }
    return 0;
}