// Author : ysh
// 12/13/2022 Tue 10:54:40.86
// https://tioj.ck.tp.edu.tw/problems/1069
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

struct box{
    int x,y,t;
    box(int t = 0,int x = 0,int y = 0):
        x(x), y(y), t(t) {};
    bool operator<(box a) {
        return t < a.t;
    }
    bool operator==(box a) {
        return (x == a.x && y == a.y && t == a.t);
    }
};
bool check(vector<int>&now,vector<vector<int>>&f,vector<box>&line,int n,int x,vector<bool>&mark) {
    // if(now.at(x) == -1) {
    //     return 1;
    // }
    cout<<boolalpha;
    for(auto i : f.at(x)) {
        if(mark.at(i)) continue;
        mark.at(i) = 1;
        if(now.at(i) == -1) {
            now.at(i) = x;
            return 1;
        }
        if(now.at(i) == x) continue;
        if(check(now,f,line,n,now.at(i),mark)) {
            now.at(i) = x;
            return 1;
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<box>f(n);
        for(box &i : f) {
            cin>>i.t>>i.x>>i.y;
        }
        sort(f.rbegin(),f.rend());
        vector<vector<int>>v(n);
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                if(i == j) continue;
                if(f.at(i).t + abs(f.at(j).x - f.at(i).x) + abs(f.at(j).y - f.at(i).y) <= f.at(j).t) {
                    v.at(i).push_back(j);
                }
            }
        }
        vector<int>now(n,-1);
        int ans = 0;
        for(int i = 0;i<n;i++) {
            vector<bool>mark(n);
            if(check(now,v,f,n,i,mark)) ans++;
            debug(now);
        }
        cout<<n - ans<<"\n";
    }
    return 0;
}