// Author : ysh
// 03/14/2023 Tue 14:35:34.51
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    for(int i = 0;i<n;i++) {
        int n;cin>>n;
        n = n << 1;
        vector<int>f(n);
        for(int &i : f) {
            cin>>i;
        }
        sort(f.begin(),f.end());
        bool c = 0;
        int t = 0;
        int last = 0;
        int mmax = 0;
        for(int i : f) {
            
            if(i & 1 || (t++ & 1 && i != last)) {
                c = 1;
                break;
            }
            last = i;
            mmax = max(mmax,i);
        }
        if((mmax >> 1) % n != 0) c = 1;
        sort(f.rbegin(),f.rend());
        if(c) cout<<"NO\n";
        else cout<<"YES\n";
    }
}