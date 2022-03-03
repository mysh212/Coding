// Author : ysh
// 02/23/2022 Wed  8:48:27.42
// https://judge.tcirc.tw/ShowProblem?problemid=d010
// CE
#include<bits/stdc++.h>
using namespace std;
const int mmax = 1000000000;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    bitset<(mmax<<1)+1>f;
    int n;cin>>n;
    int tmp;
    for(int i = 0;i<n;i++) {
        cin>>tmp;
        f.set(tmp+mmax);
    }
    cout<<f.count()<<"\n";
    for(int i = f._Find_first();i<((mmax<<1)+1);i = f._Find_next(i)) {
        cout<<i - mmax<<" ";
    }
    return 0;
}