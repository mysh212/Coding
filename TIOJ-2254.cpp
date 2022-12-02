// Author : ysh
// 11/25/2022 Fri 15:34:18.38
// https://tioj.ck.tp.edu.tw/problems/2254
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
// vector<int>color;
// int ff(int x) {
//     if(color.at(x) == x) return x;
//     return x = ff(color.at(x));
// }
// inline void mg(int a,int b) {
//     color.at(ff(a)) = ff(b);
//     return;
// }
struct box{
    int x,y,z;vector<int>f;
    box(int x = 0,int y = 0,int z = 0,vector<int>f = vector<int>({})):
        x(x), y(y), z(z), f(f) {};
    inline bool operator<(const box a) const {
        return z < a.z;
    }
    inline void input() {
        cin>>x>>y>>z;
        x--;y--;
    }
};
int a,b;
bool check(int z,vector<box>&f) {
    vector<vector<int>>v(a);
    vector<int>to(a);
    for(box &i : f) {
        if(z < i.z) {
            v.at(i.x).push_back(i.y);
            to.at(i.y) = to.at(i.y) + 1;
            continue;
        }
    }
    queue<int>q;
    for(int i = 0;i<a;i++) {
        if(to.at(i) == 0) q.push(i);
    }
    while(!q.empty()) {
        int now = q.front();q.pop();
        for(int &i : v.at(now)) {
            if(--to.at(i) == 0) {
                q.push(i);
            }
        }
    }
    for(int &i : to) {
        if(i != 0) {
            // debug(z,to);
            return 0;
        }
    }
    return 1;
}
int ck(int l,int r,vector<box>&f) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    if(check(mid,f)) return ck(l,mid,f);
    return ck(mid + 1,r,f);
}
void walk(vector<box>&f,int n) {
    vector<bool>re(a);
    vector<vector<int>>v(a);
    vector<vector<int>>todo(a);
    vector<int>to(a);
    for(box &i : f) {
        if(i.z > n) {
            v.at(i.x).push_back(i.y);
            to.at(i.y)++;
        } else {
            todo.at(i.x).push_back(i.y);
        }
    }
    vector<int>run;
    queue<int>q;
    for(int i = 0;i<a;i++) {
        if(to.at(i) == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int now = q.front();q.pop();
        run.push_back(now);
        for(int &i : v.at(now)) {
            if(--to.at(i) == 0) q.push(i);
        }
    }
    set<pair<int,int>>s;
    for(int &i : run) {
        for(int &j : todo.at(i)) {
            if(re.at(j)) {
                s.insert({i,j});
            }
        }
        re.at(i) = 1;
    }
    debug(s,f.size());
    vector<int>ans;
    for(int i = 0;i<b;i++) {
        box &now = f.at(i);
        debug(now.x,now.y);
        if(s.find({now.x,now.y}) == s.end()) continue;
        ans.push_back(i + 1);
    }
    cout<<ans.size()<<"\n";
    for(int &i : ans) {
        cout<<i<<"\n";
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    vector<box>f(b);
    for(box &i : f) {
        cin>>i.x>>i.y>>i.z;
        i.x--;i.y--;
    }
    int tmp = ck(0,(int) 1e9,f);
    cout<<tmp<<" ";
    walk(f,tmp);
    return 0;
}