// Author : ysh
// 05/06/2022 Fri  9:18:56.38
// WA
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2],b[2];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;cin>>n>>k;
    a[1] = b[1] = k;
    int nowa,nowb;nowa=nowb=0;
    for(int i = 0;i<n;i++) {
        cin>>a[i & 1]>>b[i & 1];
        nowa = min(nowa + abs(a[!(i & 1)] - a[i & 1]),nowb + abs(b[!(i & 1)] - a[i & 1]));
        nowb = min(nowb + abs(b[!(i & 1)] - b[i & 1]),nowa + abs(a[!(i & 1)] - b[i & 1]));
    }
    cout<<min(nowa,nowb);
}