// Author : ysh
// 09/16/2022 Fri 14:09:42.63
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n),g;
    for(int &i : f) {
        cin>>i;
        g.push_back(i);
    }
    sort(g.begin(),g.end(),greater<int>());
    for(int i : f) {
        cout<<((lower_bound(g.begin(),g.end(),i,greater<int>()) - g.begin() + 1))<<" ";
    }
    return 0;
}