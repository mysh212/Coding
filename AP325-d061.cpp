// Author : ysh
// 07/25/2022 Mon 17:00:30.84
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>f;
int n;
int x,y;
int check(int l,int r,int m) {
    if(l >= r) return 0;
    int mmax = 0;
    int ll = -1;
    int next = -1;
    for(int i = m;i<n;i++) {
        next = i;
        if(f[i].first > l) break;
        if(f[i].second - l > mmax) {
            mmax = f[i].second - l;
            ll = f[i].second;
        }
    }
    if(ll == -1) return INT_MIN;
    return check(ll,r,next) + 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    cin>>x>>y;
    f.resize(n);
    for(pair<int,int> &i : f) {
        cin>>i.first>>i.second;
        if(i.first > i.second) swap(i.first,i.second);
    }
    sort(f.begin(),f.end(),[] (pair<int,int> a,pair<int,int> b) {
        if(a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });
    int ans = check(x,y,0);
    if(ans < 0) {
        cout<<"-1";
        return 0;
    }
    cout<<ans;
    return 0;
}