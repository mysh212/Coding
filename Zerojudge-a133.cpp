// Author : ysh
// 06/23/2022 Thu 10:29:46.82
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    int t = 1;
    while(cin>>a>>b) {
        if(a == 0 && b == 0) break;
        vector<int>f(a),g(b);
        for(int &i : f) {
            cin>>i;
        }
        for(int &i : g) {
            cin>>i;
        }
        vector<vector<int>>v(a + 1,vector<int>(b + 1));
        // if(f.at(0) == g.at(0)) v.at(0).at(0) = 1;
        for(int i = 1;i<=a;i++) {
            for(int j = 1;j<=b;j++) {
                if(f[i - 1] == g[j - 1]) v[i][j] = v[i - 1][j - 1] + 1;
                else v[i][j] = max(v[i][j - 1],v[i - 1][j]);
                continue;
            }
        }
        // for(vector<int> i : v) {
        //     for(int j : i) cout<<j<<" ";
        //     cout<<"\n";
        // }
        cout<<"Twin Towers #"<<t++<<"\nNumber of Tiles : ";
        cout<<v[a][b]<<"\n\n";
    }
    return 0;
}