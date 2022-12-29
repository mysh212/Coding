// Author : ysh
// 12/29/2022 Thu 21:00:55.24
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

vector<pair<int,int>>f;
vector<int>mark;
int l;int m;
int check(int r) {
    // cerr<<r;
    mark.clear();
    int n = f.size();
    int ans = 0;
    for(auto &i : f) {
        // debug(r,ans);
        if(i.second == 1) {
            if(i.first + r > l) ans++;
            else mark.push_back(i.first + r);
            continue;
        }
        if(i.first - r <= 0) ans++;
        else mark.push_back(i.first - r);
    }
    return ans >= m;
}
int ck(int l,int r) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    if(check(mid)) return ck(l,mid);
    else return ck(mid + 1,r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>l;
    string a;cin>>a;
    int n;cin>>n;
    cin>>m;
    for(int i = 0;i<n;i++) {
        int a,b;cin>>a>>b;
        f.push_back({a,b});
    }
    check(ck(0,l));
    // for(int &i : mark) cout<<i;
    sort(mark.begin(),mark.end());
    mark.resize(unique(mark.begin(),mark.end()) - mark.begin());
    for(int &i : mark) {
        cout<<a.at(i - 1);
    }
    return 0;
}