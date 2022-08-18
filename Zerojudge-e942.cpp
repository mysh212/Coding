// Author : ysh
// 08/12/2022 Fri 15:40:01.49
#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    sort(f.begin(),f.end());
    do {
        for(int i : f) cout<<i<<" ";
        cout<<"\n";
    } while(next_permutation(f.begin(), f.end()));
    return 0;
}