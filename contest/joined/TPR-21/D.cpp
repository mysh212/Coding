// Author : ysh
// 05/29/2022 Sun 15:33:13.79
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    map<int,int>m;
    int tmp;
    for(int i = 0;i<(n << 1);i++) {
        cin>>tmp;
        m[tmp]++;
    }
    int mmax = 0;
    for(auto i : m) {
        i.second = i.second - n;
        if(i.second > 0) mmax = max(mmax,i.second);
    }
    cout<<mmax;
    return 0;
}