// Author : ysh
// 09/19/2022 Mon 10:35:28.99
#include<bits/stdc++.h>
using namespace std;
struct table{
    vector<vector<int>>f,x;
    int n = 0,g = 0;

    table(vector<int>&v) {
        n = v.size();
        g = __lg(n) + 1;
        f.resize(n,vector<int>(g));
        x.resize(n,vector<int>(g));
        for(int i = 0;i<n;i++) f[i][0] = v[i];
        for(int i = 1;(1 << i)<=n;i++) {
            for(int j = 0;j + (1 << (i - 1))<n;j++) {
                f[j][i] = max(f[j][i - 1],f[j + (1 << (i - 1))][i - 1]);
                x[j][i] = min(x[j][i - 1],x[j + (1 << (i - 1))][i - 1]);
            }
        }
    }

    pair<int,int> get(int l,int r) {
        if(l > r) swap(l,r);
        int t = r - l + 1;
        t = __lg(t);
        return {max(f[l][t],f[r - (1 << t) + 1][t]),min(x[l][t],x[r - (1 << t) + 1][t])};
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;cin>>m;
    while(m--) {
        int n;cin>>n;
        vector<int>f(n);
        for(int i = 0;i<n;i++) {
            string a;cin>>a;
            for(int j = 0;j<n;j++) {
                if(a[j] == '1') {
                    f[j] = i;
                }
            }
        }
        table t = table(f);
        int ans = 0;
        for(int i = 0;i<n;i++) {
            for(int j = i;j<n;j++) {
                auto tmp = t.get(i,j);
                if(tmp.first - tmp.second == j - i) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}