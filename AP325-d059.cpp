// Author : ysh
// 07/29/2022 Fri 22:34:36.50
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long
vector<int>f;
int a,b;
int check(int b) {
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i = 1;i<=b;i++) {
        q.push(0);
    }
    for(int i = 0;i<a;i++) {
        int tmp = f.at(i);
        int now = q.top();q.pop();
        q.push(now + tmp);
    }
    int mmax = 0;
    while(!q.empty()) {
        mmax = q.top();q.pop();
    }
    return mmax;
}
vector<int>mark;
inline int ff(int x) {
    if(mark.at(x) != -1) return mark.at(x);
    return mark.at(x) = check(x);
}
bool cp(int a,int b) {
    int l = ff(a);
    // int r = ff(b);
    return l > b;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    f.resize(a);
    for(int &i : f) {
        cin>>i;
    }
    // cout<<check(f,0,n - 1);
    mark.resize(a,-1);
    vector<int>v(a);
    iota(v.begin(),v.end(),0);
    cout<<*lower_bound(v.begin(),v.end(),b,cp);
    return 0;
}