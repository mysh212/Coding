// Author : ysh
// 07/14/2022 Thu 21:43:10.18
#include<bits/stdc++.h>
using namespace std;
int m;
int c[15][15];
int mmax = 0;
int x = 0,y = 0;
void check(vector<bool> &f,vector<bool> &g,vector<bool> &h,vector<bool> &r,int sig,int n) {
    mmax = max(mmax,sig);
    if(n == 0) return;
    // cerr<<n<<" "<<sig<<"\n";
    for(int i = -1;i<m;i++) {
        for(int j = 0;j<m;j++) {
            if(i == -1) {
                i = x;
                j = y;
            }
            // cerr<<i<<" "<<j<<"\n";
            if((!f[i]) && (!g[j]) && (!h[i + j]) && (!r[m + i - j])) {
                x = i;y = j;
                f[i] = 1;
                g[j] = 1;
                h[i + j] = 1;
                // cerr<<m + i - j<<"\n";
                r[m + i - j] = 1;
                check(f,g,h,r,sig + c[i][j],n - 1);
                f[i] = 0;
                g[j] = 0;
                h[i + j] = 0;
                r[m + i - j] = 0;
            }
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<bool>f,g,h,r;
    cin>>m;
    if(m == 1) {
        cin>>m;
        cout<<m;
        return 0;
    }
    for(int i = 0;i<m;i++) {
        for(int j = 0;j<m;j++) {
            cin>>c[i][j];
        }
    }
    f.resize(m);
    g.resize(m);
    h.resize(m << 2);
    r.resize(m << 2);
    check(f,g,h,r,0,m);
    cout<<mmax;
    return 0;
}