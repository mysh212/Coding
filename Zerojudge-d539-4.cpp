// Author : ysh
// 08/20/2022 Sat  8:02:03.34
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct table{
    vector<vector<int>>f;
    int n,l;

    table(vector<int>&v) {
        n = v.size();
        l = __lg(n);
        f.resize(n,vector<int>(l + 1));
        for(int i = 0;i<n;i++) {
            f[i][0] = v[i];
        }
        for(int i = 1;(1 << i) <= n;i++) {
            for(int j = 0;(1 << i) + j - 1<n;j++) {
                f[j][i] = max(f[j][i - 1],f[j + ((1 << (i - 1)))][i - 1]);
            }
        }
    }

    int get(int l,int r) {
        if(l > r) swap(l,r);
        int t = (r - l + 1);
        int d = __lg(t);
        return max(f[l][d],f[r - (1 << d) + 1][d]);
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    table t = table(f);
    int m;cin>>m;
    while(m--) {
        int a,b;cin>>a>>b;
        cout<<t.get(a - 1,b - 1)<<"\n";
    }
    return 0;
}