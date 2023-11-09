// Author : ysh
// 2023/09/21 Thu 23:03:44
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

#define int long long
vector<int>f;
int n,m;
bool check(int x) {
    int ans = 0;
    for(int &i : f) {
        ans = ans + max(x - i,0LL);
    }
    return ans <= m;
}
int ck(int l,int r) {
    debug(l,r);
    if(l + 1 == r) return l;
    int mid = (l + r) >> 1;
    if(check(mid)) return ck(mid,r);
    return ck(l,mid);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r;cin>>r;
    while(r--) {
        cin>>n>>m;
        f = vector<int>(n);
        for(int &i : f) {
            cin>>i;
        }

        cout<<ck(0,3e9)<<"\n";
    }
}