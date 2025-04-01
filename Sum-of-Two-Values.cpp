// Author : ysh
// 2025/03/30 Sun 23:38:32
// https://cses.fi/problemset/task/1640
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vc<pair<int,int>>f(a);
    
    int t = 0;
    repo(&i, f) cin>>i.first, i.second = t++;

    sort(all(f));
    int l, r;l = 0, r = a - 1;
    while(l < r) {
        if(f.at(l).first + f.at(r).first == b) {
            outs(f.at(l).second + 1);
            out(f.at(r).second + 1);
            return 0;
        }

        if(r >= 0 && f.at(l).first + f.at(r).first > b) r--;
        else if(l < a && f.at(l).first + f.at(r).first < b) l++;
    }

    outt(IMPOSSIBLE);
    return 0;
}