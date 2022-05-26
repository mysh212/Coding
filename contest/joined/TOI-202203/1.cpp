// Author : ysh
// 04/01/2022 Fri 18:07:56.16
#include<bits/stdc++.h>
using namespace std;
struct box{
    int x;
    int y;
    int r;
    int p;
    int l;
    bool mark = 0;
    bool mk = 0;
};
inline bool cp(box a,box b) {
    if(a.p != b.p) return a.p > b.p;
    if(a.r != b.r) return a.r > b.r;
    if(a.l != b.l) return a.l > b.l;
}
inline bool cpr(box a,box b) {
    if(a.p != b.p) return a.p > b.p;
    if(a.r != b.r) return a.r > b.r;
    if(a.l != b.l) return a.l > b.l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    int aa=a,bb=b,cc=c;
    int d = c;
    c = c * c;
    vector<box> t(a);
    for(int i = 0;i<a;i++) {
        cin>>t[i].x>>t[i].y>>t[i].r>>t[i].p;
        t[i].l = t[i].x * t[i].x + t[i].y * t[i].y;
    }
    sort(t.begin(),t.end(),cp);
    while(1) {
        pair<int,int> tmp = {b,c};
        for(int i = 0;i<a;i++) {
            if(t[i].l > c||t[i].mark == 1) {
                continue;
            }
            t[i].mark = 1;
            c = (d + t[i].r) * (d + t[i].r);
            d = d + t[i].r;
            b += t[i].p;
            b--;
    // cout<<"===\n"<<b<<" "<<c<<"\n";
    // for(auto i : t) {
    //     cout<<i.x<<" "<<i.y<<" "<<i.r<<" "<<i.p<<" "<<i.l<<" "<<(int) i.mark<<"\n";
    // }
            if(b == 0) break;
        }
        if((tmp.first == b&&tmp.second == c)||b == 0) break;
    }
    // cout<<"===\n";
    int e = d;
    a = aa;b = bb;c = cc * cc;d = cc;
    sort(t.begin(),t.end(),cpr);
    while(1) {
        pair<int,int> tmp = {b,c};
        for(int i = 0;i<a;i++) {
            if(t[i].l > c||t[i].mk == 1) {
                continue;
            }
            t[i].mk = 1;
            c = (d + t[i].r) * (d + t[i].r);
            d = d + t[i].r;
            b += t[i].p;
            b--;
    // cout<<"===\n"<<b<<" "<<c<<"\n";
    // for(auto i : t) {
    //     cout<<i.x<<" "<<i.y<<" "<<i.r<<" "<<i.p<<" "<<i.l<<" "<<(int) i.mark<<"\n";
    // }
            if(b == 0) break;
        }
        if((tmp.first == b&&tmp.second == c)||b == 0) break;
    }
    // cout<<"===\n";
    cout<<max(e,d);
    return 0;
}