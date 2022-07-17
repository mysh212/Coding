// Author : ysh
// 07/16/2022 Sat 15:06:45.25
// https://judge.tcirc.tw/ShowProblem?problemid=d031
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
    }
    int l,r;l=r=0;
    long long sig = 0;sig = f[0];
    long long mmax = 0;
    int c = 0;
    while(r != a + 1) {
        if(l > r) r = l;
        if(sig > b) {
            sig = sig - f[l++];
        }
        if(sig <= b) {
            if(sig > mmax) {
                mmax = sig;
                c = 1;
            } else if(sig == mmax) {
                c++;
            }
            sig = sig + f[++r];
        }
    }
    cout<<mmax<<"\n"<<c;
    return 0;
}