// Author : ysh
// 2023/07/09 Sun 23:04:12
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<int,int>>f(n);
    for(auto &i : f) cin>>i.second;

    for(int i = 1;i<n - 1;i++) {
        f.at(i).first = f.at(i - 1).second + f.at(i + 1).second;
    }
    f.at(0).first = f.at(0).second;
    f.at(n - 1).first = f.at(n - 1).second;

    sort(f.begin(),f.end());
    for(auto &i : f) cout<<i.first<<" "<<i.second<<"\n";

    return 0;
}