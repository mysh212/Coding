// Author : ysh
// 09/01/2022 Thu 19:33:53.65
// https://cses.fi/problemset/task/1197/
#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<pair<int,int>>>f;
vector<int>dt;
vector<int>mark;
const long long R = 1e13;
int a,b;
int check() {
    int d = 0;
    for(int i = 0;i<a;i++) {
        d = -1;
        for(int j = 0;j<a;j++) {
            for(auto i : f.at(j)) {
                if(dt[i.first] > dt[j] + i.second) {
                    d = j;
                    mark[i.first] = j;
                    dt[i.first] = dt[j] + i.second;
                }
            }
        }
    }
    return (d);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    f.resize(a,vector<pair<int,int>>());
    dt.resize(a,R);
    dt[0] = 0;
    mark.resize(a,-1);
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        f.at(a - 1).push_back({b - 1,c});
    }
    int tmp = check();
    if(tmp != -1) {
        cout<<"YES\n";
        vector<int>v;
        // q.push(tmp);
        // bool c = 0;
        // while(!q.empty()) {
        //     cerr<<1;
        //     if(c && now == tmp) {
        while(a--) tmp = mark.at(tmp);
        int now = tmp;
        do {
            v.push_back(now);
            now = mark.at(now);
        } while(now != tmp);
        v.push_back(now);
        while(!v.empty()) {
            cout<<v.back() + 1<<" ";v.pop_back();
        }
        //         break;
        //     }
        //     c = 1;
        //     for(auto i : f.at(now)) {
        //         q.push(i.first);
        //         mark[i.first] = now;
        //     }
        // }
        return 0;
    }
    cout<<"NO\n";
    return 0;
}