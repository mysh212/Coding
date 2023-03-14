// Author : ysh
// 03/12/2023 Sun  7:57:14.63
// https://codeforces.com/problemset/problem/1720/C
#include<bits/stdc++.h>
using namespace std;
const int xx[] = {-1,-1,-1,0,0,1,1,1};
const int yy[] = {-1,0,1,-1,1,-1,0,1};
bool check(int n,int m,vector<vector<bool>>&f) {
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            if(f.at(i).at(j)) continue;
            for(int k = 0;k<=7;k++) {
                int nx = i + xx[k];
                int ny = j + yy[k];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(!f.at(nx).at(ny)) return 1;
            }
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;cin>>m;
    while(m--) {
        int a,b;cin>>a>>b;
        int ans = 0;
        vector<vector<bool>>f(a,vector<bool>(b));
        for(int i = 0;i<a;i++) {
            for(int j = 0;j<b;j++) {
                char tmp;cin>>tmp;
                f.at(i).at(j) = (tmp == '1');
                if(tmp == '1') ans = ans + 1;
            }
        }
        if(ans == a * b) cout<<ans - 2<<"\n";
        else if(check(a,b,f)) cout<<ans<<"\n";
        else cout<<max(0,ans - 1)<<"\n";
    }
    return 0;
}