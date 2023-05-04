// Author : ysh
// 04/10/2023 Mon 10:39:18.24
#include<bits/stdc++.h>
using namespace std;
// #define int long long
struct box{
    int a,b,c;
    box(int a = 0,int b = 0,int c = 0):
        a(a), b(b), c(c) {};
    bool operator<(box &x) {
        return c < x.c;
    }
};
vector<int>mark;
int walk(vector<box>&f,vector<vector<int>>&v,int x,bool c = 0) {
    if(mark.at(x) != -1 && mark.at(x) != (int) c) return 0;
    if(mark.at(x) == (int) c) return 1;
    mark.at(x) = (int) c;
    for(int &i : v.at(x)) {
        if(!walk(f,v,i,!c)) return 0;
    }
    return 1;
}
bool check(vector<box>&f,int x,int a,int b) {
    mark = vector<int>(a,-1);
    vector<vector<int>>v(a);
    for(int i = 0;i<=x;i++) {
        v.at(f.at(i).a).push_back(f.at(i).b);
        v.at(f.at(i).b).push_back(f.at(i).a);
    }
    for(int i = 0;i<a;i++) {
        if(mark.at(i) == -1) if(!walk(f,v,i)) return 0;
    }
    return 1;
}
int ck(vector<box>&f,int l,int r,int a,int b) {
    if(l == r && l == b) return 0;
    if(l == r) return f.at(l).c;
    int mid = (l + r) >> 1;
    if(check(f,mid,a,b)) return ck(f,mid + 1,r,a,b);
    return ck(f,l,mid,a,b);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<box>f(b);
    for(auto &i : f) {
        cin>>i.a>>i.b>>i.c;
        i.a--;i.b--;
    }
    sort(f.rbegin(),f.rend());
    // for(auto i : f) {
    //     cout<<i.a<<" "<<i.b<<" "<<i.c<<"\n";
    // }
    // for(int i = 0;i<b;i++) {
    //     cout<<(int) check(f,i,a,b)<<" ";
    // }
    // cout<<"\n";
    cout<<ck(f,0,b,a,b);
    return 0;
}