// Author : ysh
// 10/21/2022 Fri  9:41:17.61
// https://tioj.ck.tp.edu.tw/problems/1069
#include<bits/stdc++.h>
using namespace std;
struct box{
    int t,x,y;
    box(int t = 0,int x = 0,int y = 0):
        t(t), x(x), y(y) {};
    inline bool operator<(const box &a) const {
        return t > a.t;
    }
};
inline int dt(int a,int b,int c,int d) {
    return (abs(a - c) + abs(b - d));
}
bool ck(int n,vector<box>&f) {
    priority_queue<box>q;
    for(int i = 0;i<n;i++) q.emplace(0,1001,1001);
    int finish = 0;
    int a = f.size();
    vector<bool>mark(f.size());
    while(!q.empty()) {
        auto now = q.top();q.pop();
        int x = now.x;
        int y = now.y;
        int t = now.t;
        // int nx = f.at(finish).x;
        // int ny = f.at(finish).y;
        // int nt = f.at(finish).t;
        if(x == y && y == 1001) {
            for(int i = 0;i<a;i++) {
                if(!mark.at(i)) {
                    q.emplace(f.at(i).t,f.at(i).x,f.at(i).y);
                    break;
                }
            }
        }
        for(int i = 0;i<a;i++) {
            if(mark.at(i)) continue;
            if(t + dt(x,y,f.at(i).x,f.at(i).y) > f.at(i).t) continue;
            mark.at(i) = 1;
            q.emplace(f.at(i).t,f.at(i).x,f.at(i).y);
            continue;
        }
    }
    for(bool i : mark) {
        cerr<<(int) i<<" ";
        // if(!i) return 0;
    }
    cerr<<"\n";
    return 1;
}
int check(int n,vector<box>f) {
    int l = 1,r = n;
    while(r != l) {
        // cerr<<l<<" "<<r<<"\n";
        int mid = (l + r) >> 1;
        if(ck(mid,f)) r = mid;
        else l = mid + 1;
    }
    // cerr<<"\n";
    // int mid = (l + r) >> 1;
    // if(ck(mid,f)) r = mid;
    // else l = mid;
    return l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int m;cin>>m;
        vector<box>f(m);
        for(auto &i : f) {
            cin>>i.t>>i.x>>i.y;
        }
        sort(f.rbegin(),f.rend());
        cout<<ck(2,f)<<"\n";
    }
    return 0;
}