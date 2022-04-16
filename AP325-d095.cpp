// Author : ysh
// 04/15/2022 Fri 10:12:41.37
// https://judge.tcirc.tw/ShowProblem?problemid=d095
#include<bits/stdc++.h>
using namespace std;
#define p system("pause");
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c,d;cin>>a>>b>>c>>d;
    vector<pair<int,int>>e[a];
    int to[a] = {};
    {
    int f,g,h;
    for(int i = 0;i<b;i++) {
        cin>>f>>g>>h;
        e[f].push_back({g,h});
        to[g]++;
    }
    // delete &f,&g,&h;
    }
    // for(int i = 0;i<a;i++) {
    //     for(auto j : e[i]) {
    //         cerr<<j.first<<" "<<j.second<<"\n";
    //     }
    //     cerr<<"\n";
    // }
    // cerr<<"\n";
    queue<int>f;
    vector<int>mmax(a,INT_MIN),mmin(a,INT_MAX);
    for(int i = 0;i<a;i++) {
        if(to[i] == 0) {
            f.push(i);
            // mmax[i] = mmin[i] = 0;
        }
    }
    mmax[c] = mmin[c] = 0;
    while(!f.empty()) {
        auto now = f.front();f.pop();
        // cerr<<now;
        // mmax[now] = max(mmax[now],now.second);
        // mmin[now] = min(now.second,mmin[now]);
        for(auto i : e[now]) {
            // if(now == d) return 100;
            if(mmax[now] != INT_MIN) {
                mmax[i.first] = max(mmax[now] + i.second,mmax[i.first]);
                mmin[i.first] = min(mmin[now] + i.second,mmin[i.first]);
            }
            // to[i.first]--;
            if(--to[i.first] == 0) {
                f.push(i.first);
            }
        }
    }
    // for(int i = 0;i<a;i++) cout<<mmax.size();
    // cerr<<"\n";
    // for(int i : mmax) cerr<<i<<" ";
    // cerr<<"\n";
    // for(int i : mmin) cerr<<i<<" ";
    if(mmin[d] == INT_MAX) {
        cout<<"No path\nNo path\n";
        return 0;
    }
    cout<<mmin[d]<<"\n"<<mmax[d]<<"\n";
    return 0;
}