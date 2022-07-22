// Author : ysh
// 07/18/2022 Mon  8:45:50.17
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

#define int long long
int n;
vector<int>f;
int check(int,int);
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("0.in","r",stdin);
    cin>>n;
    f.resize(n);
    for(int &i : f) {
        cin>>i;
    }
    cout<<check(0,n - 1);
    return 0;
}
int check(int l,int r) {
    // debug(l,r);
    if(l >= r) {
        return max(f[l],0LL);
    }
    int mid = (l + r) >> 1;
    int mmax = max(check(l,mid),check(mid + 1,r));
    int lm,rm;lm=rm=0;
    int sig = 0;
    for(int i = mid;i >= l;i--) {
        lm = max(sig += f[i],lm);
    }
    sig = 0;
    for(int i = mid + 1;i <= r;i++) {
        rm = max(sig += f[i],rm);
    }
    // debug(lm,rm);
    // system("pause");
    return max(mmax,(lm + rm) * 1LL);
}