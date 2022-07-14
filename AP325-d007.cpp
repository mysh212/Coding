// Author : ysh
// 07/14/2022 Thu 17:37:15.90
#include<bits/stdc++.h>
using namespace std;
#define int long long
int mmax = 0;
int a,b;
void check(vector<int> &f,int n,int sig = 0) {
    if(sig <= b) mmax = max(mmax,sig);
    if(sig > b) return;
    if(n == f.size()) return;
    check(f,n + 1,sig + f[n]);
    check(f,n + 1,sig);
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int>f;
    cin>>a>>b;
    for(int i = 0;i<a;i++) {
        int tmp;cin>>tmp;f.push_back(tmp);
    }
    check(f,0);
    cout<<mmax;
    return 0;
}