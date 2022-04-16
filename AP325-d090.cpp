// Author : ysh
// 04/13/2022 Wed  8:22:27.73
#include<bits/stdc++.h>
using namespace std;
bool c[100][100] = {0};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int n;cin>>n;
    int tmpa,tmpb;
    for(int i = 0;i<b;i++) {
        cin>>tmpa>>tmpb;
        c[tmpa][tmpb] = true;
    }
    queue<pair<int,int>>f;
    f.push({n,1});
    int ans = 0;
    int dot = 0;
    vector<bool>v(a);
    v[n] = 1;
    while(!f.empty()) {
        auto now = f.front();f.pop();
        for(int i = 0;i<a;i++) {
            if(c[now.first][i]&&(!v[i])) {
                if(now.first == i) continue;
                ans += now.second;
                v[i] = 1;
                c[now.first][i] = 0;
                dot++;
                f.push({i,now.second + 1});
            }
        }        
    }
    cout<<dot<<"\n"<<ans;
    return 0;
}