// Author : ysh
// 2023/07/09 Sun 10:49:32
#include<bits/stdc++.h>
using namespace std;
int n;
vector<long long>f;
#define int long long
#define left(i) ((i << 1) + 1)
#define right(i) ((i << 1) + 2)
void mt(vector<int>&v,int t = 0,int nl = -1,int nr = -1) {
    if(nl == -1 && nr == -1) nl = 0,nr = n - 1;
    if(nl == nr) return f.at(t) = v.at(nl),void();
    int mid = (nl + nr) >> 1;
    mt(v,left(t),nl,mid);
    mt(v,right(t),mid + 1,nr);
    f.at(t) = min(f.at(left(t)),f.at(right(t)));
    return;
}
void add(int x,int v,int t = 0,int nl = -1,int nr = -1) {
    if(nl == -1 && nr == -1) nl = 0,nr = n - 1;
    if(nl == nr) return f.at(t) = f.at(t) + v,void();
    int mid = (nl + nr) >> 1;
    if(mid >= x) add(x,v,left(t),nl,mid);
    else add(x,v,right(t),mid + 1,nr);
    f.at(t) = min(f.at(left(t)),f.at(right(t)));
}
int get(int l,int r,int t = 0,int nl = -1,int nr = -1) {
    if(nl == -1 && nr == -1) nl = 0,nr = n - 1;
    if(l > r) swap(l,r);
    if(nr < l || nl > r) return INT_MAX;
    if(nl >= l && nr <= r) return f.at(t);
    int mid = (nl + nr) >> 1;
    return min(get(l,r,left(t),nl,mid),get(l,r,right(t),mid + 1,nr));
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    ::f = vector<long long>(a << 2);
    n = a;
    vector<long long>f(a);
    for(auto &i : f) cin>>i;

    mt(f);
    while(b--) {
        int tmp;cin>>tmp;
        if(tmp == 1) {
            int a,b;cin>>a>>b;
            a--;
            add(a,b - f.at(a));
            f.at(a) = b;
            continue;
        }
        int a,b;cin>>a>>b;
        cout<<get(a - 1,b - 1)<<"\n";
    }
    return 0;
}