// Author : ysh
// 08/18/2022 Thu 16:31:39.44
#include<bits/stdc++.h>
using namespace std;
struct table{
    vector<vector<int>>f;
    int n;
    int l;

    table(vector<int>&v) {
        l = __lg(v.size());
        n = v.size();
        f.resize(n,vector<int>(l + 1));
        /*
        for(int i = 0;i<n;i++) {
            int tmp = INT_MIN;
            int r = 0;
            f[i][0] = v[i];
            int j = 0;
            for(int k = 1;i + k<=n;k = (k << 1)) {
                // int t = (1 << k) - 1;
                for(;j<k;j++) {
                    tmp = max(tmp,v[i + j]);
                }
                f[i][r] = tmp;
                r = r + 1;
            }
        }
        */
       for(int i = 0;i<n;i++) f[i][0] = v[i];
        for(int i = 1;(1 << i) <=n;i++) {
            for(int j = 0;j + (1 << i) - 1 < n;j++) {
                f[j][i] = max(f[j][i - 1],f[j + (1 << (i - 1))][i - 1]);
            }
        }
    }

    void check() {
        for(auto i : f) {
            for(int j : i) {
                cout<<j<<" ";
            }
            cout<<"\n";
        }
    }

    int get(int l,int r) {
        int now = __lg(r - l + 1);
        return max(f[l][now],f[r - (1 << now) + 1][now]);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int i = 0;i<n;i++) {
        cin>>f[i];
    }
    table t = table(f);
    // t.check();
    int m;cin>>m;
    int a,b;
    while(m--) {
        cin>>a>>b;
        if(a > b) swap(a,b);
        cout<<t.get(a - 1,b - 1)<<"\n";
    }
    return 0;
}