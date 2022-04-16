// Author : ysh
// 04/11/2022 Mon 11:16:53.53
#include<bits/stdc++.h>
using namespace std;
#define int long long
int find(int x,int* a) {
    if(a[x] == x||a[x] == -1) return x;
    return a[x] = find(a[x],a);
}
int cg(int x,vector<int> a,int to) {
    if(a[x] == x||a[x] == -1) {
        a[x] = to;
        return to;
    }
    return a[x] = cg(a[x],a,to);
}
struct line{
    int l,r,w;
};
inline bool cp(line a,line b) {
    return a.w<b.w;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    while(cin>>m>>n) {
        vector<line>f(n);
        for(int i = 0;i<n;i++) {
            cin>>f[i].l>>f[i].r>>f[i].w;
        }
        sort(f.begin(),f.end(),cp);
        int a[m] = {-1};
        for(int i = 0;i<m;i++) {
            a[i] = -1;
        }
        // int c = m;
        int ans = 0;
        int k = -1;
        for(int i = 0;i<m - 1;i++) {
            k++;
            if(k == n) break;
            int l = f[k].l;
            int r = f[k].r;
            int w = f[k].w;
            int lf = find(l,a);
            int rf = find(r,a);
            if(lf == -1||rf == -1) {
                ans += w;
                if(lf == -1 && rf == -1) {
                    a[lf] = r;
                    a[rf] = r;
                }
                if(lf == -1) {
                    a[r] = lf;
                    continue;
                }
                a[l] = rf;
            }
            if(lf == rf) {
                i--;
                continue;
            }
            ans += w;
            a[lf] = rf;
        }
            // for(int i : a) cerr<<i<<" ";
            // cerr<<"\n";
        int now = find(0,a);
        bool c = 0;
        for(int i = 1;i<m;i++) {
            if(find(i,a) != now) {
                cout<<-1<<"\n";
                c = 1;
                break;
            }
        }
        if(!c) cout<<ans<<"\n";
    }
    return 0;
}