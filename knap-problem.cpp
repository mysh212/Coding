// Author : ysh
// 2024/07/08 Mon 00:24:37
// https://codeforces.com/group/j50SrY6hsZ/contest/533977/problem/B
#include<bits/stdc++.h>
using namespace std;
const int R = int(1e3) + 1;
#define int int64_t
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<pair<int,int>>f(a);
    for(auto &i : f) cin>>i.first>>i.second;

    vector<int>mark(R,1e12);
    mark.at(0) = 0;
    for(auto &j : f) {
        for(int i = R - 1;i>=0;i--) {
            // if(i == 0) continue;
            int w = j.first;
            int v = j.second;

            if(i < v) continue;
            mark.at(i) = min({mark.at(i - v) + w,mark.at(i),(i == R - 1 ? mark.at(i) : mark.at(i + 1))});
        }
    }

    // for(int &i : mark) cerr<<(i == 1e12 ? -1 : i)<<" ";
    // cerr<<"\n";
    // cerr<<mark.at(90);
    // cerr<<"\n";

    for(int i = R - 1;i>=0;i--) {
        if(mark.at(i) <= b) {
            cout<<i<<"\n";
            break;
        }
    }
    return 0;
}