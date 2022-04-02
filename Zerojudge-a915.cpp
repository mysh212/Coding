// Author : ysh
// 03/27/2022 Sun 18:03:47.84
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int a,b;
    vector<pair<int,int>>f(n);
    while(n--) {
        cin>>a>>b;
        f[n] = {a,b};
    }
    sort(f.begin(),f.end());
    for(auto i : f) {
        cout<<i.first<<" "<<i.second<<"\n";
    }
    return 0;
}