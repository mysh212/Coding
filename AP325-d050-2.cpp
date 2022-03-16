// Author : ysh
// 03/11/2022 Fri  8:02:11.48
// WA
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int m = 100000001;
    bitset<200000002>f;
    int n;cin>>n;
    int a,b;
    int mmax = INT_MIN;
    while(n--) {
        cin>>a>>b;
        mmax = max(b,mmax);
        for(int i = a+1;i<=b;i++) {
            f.set(i + m);
        }
    }
    int ans = 0;
    for(int j = 0;j<mmax + m;j++) {
        if(f.test(j) == 1) ans++;
    }
    cout<<ans;
    return 0;
}