// Author : ysh
// 04/01/2022 Fri 18:32:18.59
#include<bits/stdc++.h>
using namespace std;
int n;
int a[18][18] = {};
int check(int now,vector<bool>f,int sig,int front) {
    int mmin = INT_MIN;
    for(int i = 0;i<n;i++) {
        if(f[i] == 0) {
            f[i] = 1;
            mmin = min(mmin,check(now + 1,f,sig + a[i][front],i));
            f[i] = 0;
        }
    }
    if(mmin == INT_MIN) return sig;
    return mmin;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            cin>>c[i][j];
        }
    }
    vector<bool>f(n+1);
    int mmin = INT_MIN;
    for(int i = 0;i<n;i++) {
        f[i] = 1;
        mmin = min(mmin,check(i,f,0,-1));
        f[i] = 0;
    }
    cout<<mmin;return 0;
}