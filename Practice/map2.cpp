// Author : ysh
// 03/01/2022 Tue 23:06:44.33
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<int,int>f({{1,1},{2,2},{3,3}});
    for(auto i : f) {
        cout<<i.first<<" "<<i.second<<"\n";
    }
    const int x=1;
    cout<<lower_bound(f.begin(),f.end(),x)->first<<"\n";
    cout<<f.lower_bound(x)->first;
}