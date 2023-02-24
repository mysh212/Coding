// Author : ysh
// 02/24/2023 Fri 13:28:19.73
// https://cses.fi/problemset/task/1628
#include<bits/stdc++.h>
using namespace std;
#define int long long
void check(int l,int r,vector<int>&s,vector<int>&f,int sig) {
    if(l == r + 1) {
        s.push_back(sig);
        return;
    }
    check(l + 1,r,s,f,sig + f.at(l));
    check(l + 1,r,s,f,sig);
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int &i : f) cin>>i;
    int mid = a >> 1;
    vector<int>left,right;
    check(0,mid,left,f,0);
    check(mid + 1,a - 1,right,f,0);
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    int ans = 0;
    for(int i : left) {
        ans = ans + ((int) (upper_bound(right.begin(),right.end(),b - i) - lower_bound(right.begin(),right.end(),b - i)));
    }
    cout<<ans;
    return 0;
}
