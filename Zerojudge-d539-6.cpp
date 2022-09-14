// Author : ysh
// 09/14/2022 Wed  9:59:45.74
#include<bits/stdc++.h>
using namespace std;
struct table{
    vector<vector<int>>f;
    int n = 0,g = 0;

    table(vector<int>&v) {
        n = v.size();
        g = __lg(n) + 1;
        f.resize(n,vector<int>(g));
        for(int i = 0;i<n;i++) f[i][0] = v[i];
        for(int i = 1;(1 << i)<=n;i++) {
            for(int j = 0;j + (1 << (i - 1))<n;j++) {
                f[j][i] = max(f[j][i - 1],f[j + (1 << (i - 1))][i - 1]);
            }
        }
    }

    int get(int l,int r) {
        if(l > r) swap(l,r);
        int t = r - l + 1;
        t = __lg(t);
        return max(f[l][t],f[r - (1 << t) + 1][t]);
    }
};
int main() {
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