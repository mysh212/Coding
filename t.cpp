// Author : ysh
// 06/02/2023 Fri 15:32:12.73
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) cin>>i;

    sort(f.begin(),f.end(),greater<int>()); // less<int>()
    for(int i : f) cout<<i<<" ";

    cin.get();
    return 0;
}