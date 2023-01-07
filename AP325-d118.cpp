// Author : ysh
// 03/13/2022 Sun 10:25:41.02
// NF
#include<bits/stdc++.h>
using namespace std;
struct line{
    int l = 0;
    int r = 0;
    int w = 0;
    int n = 0;
};
int find;
inline bool cp(line a,line b) {
    return a.l<b.l;
}
inline bool cpr(line a,int b) {
    return a.l<b;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<line>l(n);
    for(int i = 0;i<n;i++) {
        cin>>l[i].r>>l[i].l>>l[i].w;
    }
    sort(l.begin(),l.end(),cp);
    for(int i = 0;i<n;i++) {
        l[i].n = i;
    }
    int a[n+1] = {};
    for(int i = 0;i<n;i++) {
        a[i + 1] = max(a[i],a[upper_bound(l.begin(),l.end(),l[i].r,cpr)->n] + l[i].w);
    }
    cout<<a[n];
    return 0;
}