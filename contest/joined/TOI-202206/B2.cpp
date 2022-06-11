// Author : ysh
// 06/10/2022 Fri 17:17:00.16
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b,c;cin>>a>>b>>c;
        b = b - a;
        int l,r;l=r=c;
        for(int i = 1;;i++) {
            if(i == 1) {
                b = b - 1;
                if(b < 0) cout<<i<<"\n";
                continue;
            }
            if(l > 1) l--;
            if(r < a) r++;
            // printf("%d\n",r - l + 1);
            b = b - (r - l + 1);
            if(b < 0) {
                cout<<(i - 1) + 1<<"\n";
                break;
            }
        }
    }
    return 0;
}