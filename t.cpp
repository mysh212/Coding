// Author : ysh
// 11/22/2022 Tue  9:22:03.60
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    f.resize(unique(f.begin(),f.end()) - f.begin());
    for(int &i : f) {
        cout<<i<<" ";
    }
    return 0;
}