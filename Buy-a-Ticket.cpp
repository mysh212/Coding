// Author : ysh
// 08/24/2022 Wed 17:39:53.03
// https://codeforces.com/problemset/problem/938/D
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

#define int long long
const int R = 1e13;
vector<int>f;
vector<vector<pair<int,int>>>line;
vector<int>mark;
int a,b;
void check() {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        f.clear();
        f.resize(a,R);
        //f[now] = 0;
        int r = 0;
        for(int i = 0;i<a;i++) {
            f[i] = mark[i];
            // q.emplace(i);
        }
        vector<bool>c(a);
        for(int i = 0;i<a;i++) {
            q.emplace(mark[i],i);
        }
        while(!q.empty()) {
            auto now = q.top();q.pop();
            if(c[now.second]) continue;
            c[now.second] = 1;
            for(auto i : line[now.second]) {
                f[i.first] = min(f[i.first],f[now.second] + i.second);
                q.emplace(f[i.first],i.first);
            }
        }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    f.resize(a,R);
    line.resize((a),{});
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        line[a - 1].emplace_back(b - 1,c << 1);
        line[b - 1].emplace_back(a - 1,c << 1);
    }
    mark.resize(a,R);
    for(int i = 0;i<a;i++) {
        cin>>mark[i];
    }
    /*
    for(int i = 0;i<a;i++) {
        f[i][i] = 0;
    }
    */
    check();
    //debug(f);
    for(int i : f) {
        cout<<i<<" ";
    }
    /*
    for(auto i : f) {
        for(int j : i) {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    */
    return 0;
}