// Author : ysh
// 02/10/2023 Fri  8:32:33.52
// https://codeforces.com/contest/786/problem/B
#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>>f;
vector<vector<int>>dot;
vector<int>leftindex;
vector<int>rightindex;
vector<int>st;
int x = 0;
int n;
void init(int n,int r,int t = 0,int nl = -1,int nr = -1,int last = -1) {
    if(nl == -1 && nr == -1) {
        nl = 0,nr = n - 1;
        f.resize(n << 3);
        leftindex.resize(n << 3);
        rightindex.resize(n << 3);
        dot.resize(2,vector<int>(n));
        st.resize(2);
        st.at(r) = x++;
        t = x - 1;
    }
    // cerr<<t<<" "<<nl<<" "<<nr<<"\n";
    if(last != -1) {
        if(r == 0) f.at(last).push_back({t,0});
        if(r == 1) f.at(t).push_back({last,0});
    }
    if(nl == nr) return dot.at(r).at(nl) = t,(r == 1 ? f.at(t).push_back({dot.at(0).at(nl),0}),f.at(dot.at(0).at(nl)).push_back({t,0}) : void()),void();
    int mid = (nl + nr) >> 1;
    leftindex.at(t) = x++;
    init(n,r,leftindex.at(t),nl,mid,t);
    rightindex.at(t) = x++;
    init(n,r,rightindex.at(t),mid + 1,nr,t);
    return;
}
void add(int x,int l,int r,int v,int rr,int t = 0,int nl = -1,int nr = -1) {
    if(nl == -1 && nr == -1) nl = 0,nr = n - 1,t = st.at(rr);
    if(nl > r || nr < l) return;
    if(nl>=l && nr <= r) {
        if(rr == 0) f.at(dot.at(rr).at(x)).push_back({t,v});
        if(rr == 1) f.at(t).push_back({dot.at(rr).at(x),v});
        return;
    }
    int mid = (nl + nr) >> 1;
    add(x,l,r,v,rr,leftindex.at(t),nl,mid);
    add(x,l,r,v,rr,rightindex.at(t),mid + 1,nr);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m,start;cin>>n>>m>>start;
    start--;
    init(n,0);
    init(n,1);
    while(m--) {
        int a;cin>>a;
        if(a == 1) {
            int a,b,c;cin>>a>>b>>c;
            a--;b--;
            f.at(dot.at(0).at(a)).push_back({dot.at(0).at(b),c});
            continue;
        }
        int b,c,d,e;cin>>b>>c>>d>>e;
        b--;c--;d--;
        add(b,c,d,e,a - 2);
    }
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
    q.emplace(0,dot.at(0).at(start));
    vector<long long>dt(n << 3,-1);
    while(!q.empty()) {
        auto now = q.top();q.pop();
        long long l = now.first;
        int d = now.second;
        // cerr<<d<<"\n";
        if(dt.at(d) != -1) continue;
        dt.at(d) = l;
        for(auto &i : f.at(d)) {
            q.emplace(l + i.second,i.first);
        }
    }
    // for(long long &i : dt) cerr<<i<<" ";
    // cerr<<"\n";
    for(int &i : dot.at(0)) cout<<dt.at(i)<<" ";
    return 0;
}