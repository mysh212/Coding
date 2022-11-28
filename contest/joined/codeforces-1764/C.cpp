// Author : ysh
// 11/26/2022 Sat 22:37:28.43
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>f(n);
        for(int &i : f) {
            cin>>i;
        }
        sort(f.begin(),f.end());
        if(f.front() == f.back()) {
            cout<<(f.size() >> 1)<<"\n";
            continue;
        }
        int now = 0,l = 0,r = 0;
        for(int i = 0;i<n;i++) {
            if(now != f.at(i)) {
                r = i - 1;
                int left = l;
                int right = n - 1 - r;
                if(left > right) break;
                now = f.at(i);
                l = i;
            }
        }
        // cerr<<l - 1<<" ";
        int right = n - l;
        cout<<l * right<<"\n";
    }
    return 0;
}