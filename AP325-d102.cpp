// Author : ysh
// 09/16/2022 Fri 20:49:09.27
// https://judge.tcirc.tw/ShowProblem?problemid=d102
#include<bits/stdc++.h>
using namespace std;
struct box{
    int f,t,r;
    box(int a = 0,int b = 0,int c = 0):
        f(min(a,b)), t(max(a,b)), r(c) {};
    inline bool operator<(const box b) const {
        if(r != b.r) return r < b.r;
        if(f != b.f) return f < b.f;
        return t < b.t;
    }
};
vector<vector<int>>mark;
vector<box>now;
vector<int>g;
int t;
inline int ff(int x) {
    if(g.at(x) == x) return x;
    return g.at(x) = ff(g.at(x));
}
inline bool mg(int a,int b) {
    if(ff(a) == ff(b)) return 0;
    g.at(ff(a)) = ff(b);
    t--;
    return 1;
}
vector<bool>mk;
void check(int n) {
    if(mk.at(n)) return;
    mk.at(n) = 1;
    sort(mark.at(n).begin(),mark.at(n).end());
    cout<<n<<" ";
    for(auto i : mark.at(n)) {
        if(mk.at(i)) continue;
        check(i);
        cout<<n<<" ";
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<box>f;
    int n;cin>>n;
    t = n;
    mark.resize(n,vector<int>());
    g.resize(n);
    mk.resize(n);
    iota(g.begin(),g.end(),0);
    for(int i = 0,len = n - 1;i < len;i++) {
        int a,b,c;cin>>a>>b>>c;
        f.push_back(box(a,b,c));
    }
    sort(f.begin(),f.end());
    for(auto &i : f) {
        if(mg(i.f,i.t)) {
            now.push_back(i);
            mark.at(i.f).push_back(i.t);
            mark.at(i.t).push_back(i.f);
        }
        if(t == 1) break;
    }
    int ans = 0;
    for(auto &i : now) {
        ans += i.r;
    }
    cout<<(ans << 1)<<"\n";
    check(0);
    return 0;
}