// Author : ysh
// 05/24/2022 Tue  9:00:24.69
// WA
#include<bits/stdc++.h>
using namespace std;
vector<int>f;
inline int ff(int x) {
    if(f[x] == x) return x;
    return f[x] = ff(f[x]);
}
void check(int a,int b) {
    f[ff(a)] = ff(b);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    f.resize(a);
    iota(f.begin(),f.end(),0);
    int aa,bb;
    for(int i = 0;i<b;i++) {
        cin>>aa>>bb;
        check(aa,bb);
    }
    vector<int>v(a);
    int mmax = INT_MIN;
    for(int i : f) {
        v[ff(i)]++;
        mmax = max(mmax,v[i]);
    }
    cout<<mmax;
    return 0;
}