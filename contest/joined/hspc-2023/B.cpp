// Author : ysh
// 04/09/2023 Sun 16:07:47.39
#include<bits/stdc++.h>
using namespace std;
struct box{
    int a,b,c;
    box(int a = 0,int b = 0,int c = 0):
        a(a), b(b), c(c) {};
    bool operator<(const box &x) const {
        return c < x.c;
    }
};
// vector<int>color;
// vector<int>now;
// int ff(int x) {
//     if(color.at(x) == x || color.at(x) == -1) return x;
//     return color.at(x) = ff(color.at(x));
// }
// int r = 0;
// bool mg(int a,int b) {
//     int aa = ff(a);
//     int bb = ff(b);
//     int aaa = now.at(a);
//     int bbb = now.at(b);
//     if(!(aaa == -1 || bbb == -1 || (aaa == 1 && bbb == 0) || (aaa == 0 && bbb == 1))) return 0;
//     if(aaa == bbb) aaa = 1,bbb = 0;
//     color.at(aa) = bb;
//     return !(r == 1);
// }
bool ok(vector<vector<int>>&f,vector<short>&mark,int x,bool r = 0) {
    if(mark.at(x) != -1 && mark.at(x) != (r ? 1 : 0)) return 0;
    if(mark.at(x) == (r ? 1 : 0)) return 1;
    mark.at(x) = (r ? 1 : 0);
    for(int &i : f.at(x)) {
        if(!ok(f,mark,!r)) return 0;
    }
    return 1;
}
int check(int x,vector<box>&f,int a,int b) {
    vector<vector<int>>v(a);
    for(int i = 0;i<x;i++) {
        int x = f.at(i).a;
        int y = f.at(i).b;
        v.at(x).push_back(y);
        v.at(y).push_back(x);
    }
    vector<short>now(a);
    for(int i = 0;i<a;i++) {
        if(now.at(i) == -1) {
            if(!ok(v,now,i,0)) return 0;
        }
    }
    return 1;
}
int ck(int l,int r,vector<box>&f,int a,int b) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    if(check(mid,f,a,b)) return ck(l,mid,f,a,b);
    else return ck(mid + 1,r,f,a,b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<box>f(b);
    for(box &i : f) {
        cin>>i.a>>i.b>>i.c;
        i.a--;i.b--;
    }
    sort(f.rbegin(),f.rend());
    int tmp = ck(0,b,f,a,b);
    cout<<check(7,f,a,b);
    return 0;
}