// Author : ysh
// 12/16/2022 Fri 22:25:43.84
// https://codeforces.com/problemset/problem/1749/C
// NF
#include<bits/stdc++.h>
using namespace std;
set<int,greater<int>>f;
bool check(int x) {
    int r = 0;
    x++;
    int t = f.size();
    set<int,greater<int>>f(::f);
    while(--x) {
        auto found = f.lower_bound((x << 7));
        if(found == f.end()) return 0;
        f.erase(found);
        f.insert(((*f.begin() >> 7) + x) << 7 + t++);
        f.erase(next(f.begin()));
        for(int i : f) cerr<<(i >> 7)<<" ";
        cerr<<"\n";
    }
    cerr<<"\n";
    return 1;
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

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        f = set<int,greater<int>>();
        int t = 0;
        for(int i = 0;i<n;i++) {
            int tmp;cin>>tmp;
            f.insert((tmp << 7) + t++);
        }
        cout<<ck(0,n)<<"\n";
    }
    return 0;
}