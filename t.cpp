// Author : ysh
// 03/07/2023 Tue 11:31:43.58
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

vector<int>f;
int n,k;
int check(int x) {
    int l = 0,r = n - 1;
    while(l <= r && f.at(l) + f.at(r) < x) r--;
    int ans = 0;
    for(int i = 0;i<n;i++) {
        l = i;
        while(l <= r && f.at(l) + f.at(r) < x) r--;
        if(l > r) break;
        ans = ans + (r - l + 1);
    }
    debug(x,ans);
    return ans <= k;
}
int ck(int l,int r) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    if(check(mid)) return ck(l,mid);
    return ck(mid + 1,r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;
    f.resize(n);
    for(int &i : f) {
        cin>>i;
    }
    sort(f.rbegin(),f.rend());

    cout<<ck(0,1e9);
    return 0;
}