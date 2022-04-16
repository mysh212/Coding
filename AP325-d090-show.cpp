// Author : ysh
// 04/13/2022 Wed 13:59:30.26
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int n;cin>>n;
    bool c[a][a] = {};  // c[i][j] = 1 ==> i -> j
    int tmpa,tmpb;
    for(int i = 0;i<b;i++) {
        cin>>tmpa>>tmpb;
        c[tmpa][tmpb] = 1;
    }
    queue<pair<int,int>>f;
    f.push(make_pair(n,1));
    vector<bool>v(a);
    v[n] = 1;
    int dot = 0;
    int ans = 0;
    while(!f.empty()) {
        auto now = f.front();f.pop();
        for(int i = 0;i<a;i++) {
            if(c[now.first][i] && !(v[i])) {                
                if(now.first == i) continue;
                c[now.first][i] = 0;
                dot += 1;
                v[i] = 1;
                ans += now.second;
                f.push(make_pair(i,now.second + 1));
            }
        }
    }
    cout<<dot<<"\n"<<ans;
    return 0;
}