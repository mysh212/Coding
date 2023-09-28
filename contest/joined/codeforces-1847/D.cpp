// Author : ysh
// 2023/07/06 Thu 23:56:33
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

#define left(i) ((i << 1) + 1)
#define right(i) ((i << 1) + 2)
int n;
vector<int>v;
vector<bool>f;
void init(int n) {
    f.resize(n << 2);
    ::n = n;
    return;
}
void add(int l,int r,int t = 0,int nl = -1,int nr = -1) {
    if(nl == -1 && nr == -1) nl = 0,nr = n - 1;
    if(r < nl || l > nr) return;
    if(f.at(t)) return;
    if(nl == nr) {
        if(f.at(t)) return;
        return v.push_back(nl),f.at(t) = 1,void();
    }
    int mid = (nl + nr) >> 1;
    add(l,r,left(t),nl,mid);
    add(l,r,right(t),mid + 1,nr);
    f.at(t) = f.at(left(t)) && f.at(right(t));
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    string d;cin>>d;
    init(a);
    for(int i = 1;i<=b;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        add(a,b);
    }

    vector<bool>f(a);
    int t = 0;
    int sig = 0;
    for(char i : d) {
        if(i == '1') {
            f.at(t) = 1;
            sig++;
        }
        t++;
    }

    vector<int>pre(a,-1);
    t = 0;
    for(int i : v) pre.at(i) = t++;

    int ans = 0;
    for(int i = 0;i<min(sig,int(v.size()));i++) {
        if(f.at(v.at(i))) ans++;
    }
    
    for(int i = 1;i<=c;i++) {
        int tmp;cin>>tmp;
        tmp--;
        if(f.at(tmp)) {
            f.at(tmp) = !f.at(tmp);
            sig--;
            if(pre.at(tmp) != -1 && pre.at(tmp) <= sig) ans--;
            if(not (sig >= v.size())) if(f.at(v.at(sig))) ans--;
        } else {
            f.at(tmp) = !f.at(tmp);
            sig++;
            if(pre.at(tmp) != -1 && pre.at(tmp) < sig - 1) ans++;
            if(not (sig > v.size())) if(f.at(v.at(sig - 1))) ans++;
        }
        debug(tmp + 1,sig,ans);
        cout<<min(sig,int(v.size())) - ans<<"\n";
    }
    return 0;
}