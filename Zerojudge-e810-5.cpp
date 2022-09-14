// Author : ysh
// 09/09/2022 Fri 18:08:01.66
// NA
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<array<int,3>>f;
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        f.push_back({a,b,c});
    }
    vector<int>dt(a,INT_MAX);
    int c,d;cin>>c>>d;
    dt[c] = 0;
    for(int i = 0;i<b - 1;i++) {
        for(auto i : f) {
            dt[i[1]] = min(max(dt[i[0]],i[2]),dt[i[1]]);
        }
    }
    cout<<(dt[d] == INT_MAX ? -1 : dt[d]);
    return 0;
}