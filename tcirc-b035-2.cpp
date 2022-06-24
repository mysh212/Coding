// Author : ysh
// 06/21/2022 Tue 11:10:24.68
// https://judge.tcirc.tw/ShowProblem?problemid=b035
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    gp_hash_table<int,int>m;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    int ans = 0;
    int r;cin>>r;
    for(int i : f) {
        if(m.find(r - i) != m.end()) ans += m.find(r - i)->second;
        m[i]++;
    }
    cout<<ans;
    return 0;
}