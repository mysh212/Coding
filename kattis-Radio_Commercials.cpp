// Author : ysh
// 01/29/2022 Sat 21:33:37.27
// https://open.kattis.com/problems/commercials
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline void pc(int*);
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,p;cin>>n>>p;
    int a[n] = {};
    int b[n+1] = {};
    int k = 0;
    int tmp = 0,ttmp= 0;
    bool now = 0;
    cin>>ttmp;
    ttmp = ttmp - p;
    if(ttmp > 0) now = 1;
    else now = 0;
    for(int i = 1;i<n;i++) {
        cin>>tmp;
        tmp = tmp - p;
        if(tmp > 0) {
            if(now == 0) {
                a[k] = ttmp;
                k++;
                now = 1;
                ttmp = tmp;
            } else {
                ttmp += tmp;
            }
            //+
        } else if(tmp != 0) {
            if(now == 1) {
                a[k] = ttmp;
                k++;
                now = 0;
                ttmp = tmp;
            } else {
                ttmp += tmp;
            }
        }
    }
    a[k] = ttmp;
    k++;
    n = k;
    //pc(a);
    for(int i = 1;i<=n;i++) {
        b[i] = b[i - 1] + a[i - 1];
    }
    int ans = 0;
    for(int i = 0;i<n;i++) {
        for(int j = n;j>i;j--) {
            ans = max(ans,b[j] - b[i]);
            //printf("b[%d] - b[%d]\n",j,i);
        }
    }
    cout<<ans;
    return 0;
}
inline void pc(int* c) {
    for(int i = 0;i<6;i++) {
        cout<<c[i]<<" ";
    }
    cout<<"\n";
    return;
}