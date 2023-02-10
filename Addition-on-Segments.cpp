// Author : ysh
// 01/25/2023 Wed  9:12:44.00
// https://codeforces.com/contest/981/problem/E
#include<bits/stdc++.h>
using namespace std;
const int R = (int) 1e4 + 1;
vector<vector<int>>f;
bitset<R>ans;
int n = 0;
void add(int l,int r,int x,int nl = -1,int nr = -1,int t = 0) {
    if(nl == -1 && nr == -1) nl = 0,nr = n - 1;
    if(nl >= l && nr <= r) {f.at(t).push_back(x); return;}
    if(nr < l || nl > r) return;
    int mid = (nl + nr) >> 1;
    add(l,r,x,nl,mid,(t << 1) + 1);
    add(l,r,x,mid + 1,nr,(t << 1) + 2);
    return;
}
void check(int t,bitset<R>s) {
    if(t >= f.size()) {ans = ans | s; return;}
    for(int &i : f.at(t)) {
        s = s | (s << i);
    }
    check((t << 1) + 1,s);
    check((t << 1) + 2,s);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    n = a;
    f.resize(a << 2);
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;a--;b--;
        add(a,b,c);
    }
    ans.set(0);
    check(0,ans);
    vector<int>p;
    for(int i = ans._Find_next(0);i <= a;i = ans._Find_next(i)) {
        p.push_back(i);
    }
    cout<<p.size()<<"\n";
    for(int &i : p) {
        cout<<i<<" ";
    }
    return 0;
}