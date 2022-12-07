// Author : ysh
// 12/07/2022 Wed 11:27:02.80
// https://tioj.ck.tp.edu.tw/problems/1175
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) cin>>i;
    vector<int>g;
    for(int i = 0;i<n;i++) {
        auto found = lower_bound(g.begin(),g.end(),f.at(i));
        if(found == g.end()) g.push_back(f.at(i));
        else *found = f.at(i);
    }
    cout<<g.size();
    return 0;
}