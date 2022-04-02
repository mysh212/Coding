// Author : ysh
// 04/02/2022 Sat 12:42:12.17
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct box{
    box* l;
    box* r;
    bool s = 1;
    int n = -1;
};
box* fr(box* a,box* b) {
    if(b->s == 1) return b;
    if(b->r->s != 1) {
        return b->r = fr(a,b->r);
    } else {
        return b->r;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    box c[a + 2];
    c[a+1].r = &c[a+1];
    c[0].r = &c[1];
    for(int i = 1;i<=a;i++) {
        c[i].n = i;
        c[i].l = &c[i - 1];
        c[i].r = &c[i + 1];
    }
    string d;int tmp;
    while(b--) {
        cin>>d;
        cin>>tmp;
        if(d == "-") {
            if(c[tmp].s == 0) continue;
            c[tmp].r->l = c[tmp].l;
            c[tmp].l->r = c[tmp].r;
            c[tmp].s = 0;
        }
        if(d == "?") {
            cout<<fr(c,&c[tmp])->n<<"\n";
        }
    }
}