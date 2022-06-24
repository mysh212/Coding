// Author : ysh
// 06/18/2022 Sat  9:07:18.04
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct box{
    box* l[2];
    int n = 0;
};
bool now = 0;
inline void ff(box*,box*);
inline void g(box*,box*);
inline void r(box*,box*);
vector<box>f(100002);
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int l = 0;
    while(cin>>n) {
        now = 0;
        l++;
        f[0].l[1] = &f[1];
        f[0].n = 0;
        f[n + 1].l[0] = &f[n];
        f[n + 1].n = n + 1;
        for(int i = 1;i<=n;i++) {
            f[i].l[0] = &f[i - 1];
            f[i].l[1] = &f[i + 1];
            f[i].n = i;
        }
        // g(&f[5],&f[7]);
        // r(&f[4],&f[5]);
        // for(int i = 1;i<=n;i++) {
        //     cout<<f[i].n<<": "<<f[i].l[0]->n<<" "<<f[i].l[1]->n<<"\n";   
        // }
        // return 1;
        int m;cin>>m;
        
            // cout<<f[6].l[0]->n<<" "<<f[6].l[1]->n<<"\n";
        for(int i = 0;i<m;i++) {
            int a;cin>>a;
            if(a == 1) {
                int b,c;cin>>b>>c;
                ff(&f[b],&f[c]);
            }
            if(a == 2) {
                int b,c;cin>>b>>c;
                g(&f[b],&f[c]);
            }
            if(a == 3) {
                int b,c;cin>>b>>c;
                if(b > c) swap(b,c);
                r(&f[b],&f[c]);
            }
            if(a == 4) now = !now;
            
        // box* p = (!now ? &f[0] : &f[n + 1]);
        // int rr = n + 1;
        // while(rr--) {
        //     cerr<<p->n<<" ";
        //     if(p->n == ((!now) ? n + 1 : 0)) break;
        //     p = p->l[!now];
        // }
        // cerr<<"\n";

        }
        int i = 0;
        box* p = (!now ? &f[0] : &f[n + 1]);
        int ans = 0;
        // n = 20;
        // int k = 20;
        int rr = n + 2;
        while(rr--) {
            // cout<<f[6].l[0]->n<<" "<<f[6].l[1]->n<<"\n";
            // cerr<<p->n;
            if(p->n == ((!now) ? n + 1 : 0)) break;
            if(i & 1) ans = ans + p->n;
            // cout<<ans;
            p = p->l[!now];
            i++;
        }
        cout<<"Case "<<l<<": "<<ans<<"\n";
    }
    return 0;
}
inline void ff(box* l,box* r) {
    if(now) {
        l->l[1]->l[0] = l->l[0];
        l->l[0]->l[1] = l->l[1];
        l->l[1] = r->l[1];
        l->l[0] = r;
        r->l[1] = l;
        l->l[1]->l[0] = l;
        return;
    }
    l->l[0]->l[1] = l->l[1];
    l->l[1]->l[0] = l->l[0];
    l->l[0] = r->l[0];
    l->l[1] = r;
    r->l[0] = l;
    l->l[0]->l[1] = l;
    return;
}
inline void g(box* l,box* r) {
    if(now) {
        l->l[1]->l[0] = l->l[0];
        l->l[0]->l[1] = l->l[1];
        l->l[0] = r->l[0];
        l->l[1] = r;
        r->l[0] = l;
        l->l[0]->l[1] = l;
        return;
    }
    l->l[0]->l[1] = l->l[1];
    l->l[1]->l[0] = l->l[0];
    l->l[1] = r->l[1];
    l->l[0] = r;
    r->l[1] = l;
    l->l[1]->l[0] = l;
    return;
}
inline void r(box* l,box* r) {
    if((l->l[1] == r)) {
        l->l[0]->l[1] = r;
        r->l[1]->l[0] = l;
        r->l[0] = l->l[0];
        l->l[1] = r->l[1];
        l->l[0] = r;
        r->l[1] = l;
        return;
    }
    if((l->l[0] == r)) {
        r->l[0]->l[1] = l;
        l->l[1]->l[0] = r;
        l->l[0] = r->l[0];
        r->l[1] = l->l[1];
        r->l[0] = l;
        l->l[1] = r;
        return;
    }
    l->l[0]->l[1] = r;
    r->l[1]->l[0] = l;
    l->l[1]->l[0] = r;
    r->l[0]->l[1] = l;
    swap(l->l[0],r->l[0]);
    swap(l->l[1],r->l[1]);
    return;
}