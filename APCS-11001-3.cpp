// Author : ysh
// 05/21/2022 Sat 21:19:53.85
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,r;cin>>n>>r;
    vector<int>f(n);
    {
    int a,b;
    for(int i = 0;i<n;i++) {
        cin>>a>>b;
        f[--b] = a;
    }
    }
    set<int>q;
    q.insert(0);
    q.insert(r);
    long long ans = 0;
    for(int i = 0;i<n;i++) {
        auto found = q.lower_bound(f[i]);
        ans += *found - *prev(found);
        q.insert(f[i]);
    }
    cout<<ans;
    return 0;
}