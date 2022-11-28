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
        // break;
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
    // for(int i = 0;i<a;i++) {
    //     for(int &j : v.at(i)) {
    //         cerr<<i + 1<<" "<<j + 1<<"\n";
    //     }
    // }
    // cerr<<"\n";
    // vector<int>root;
    // vector<int>dt(a,0);
    // for(int i = 0;i<a;i++) {
    //     if(!to.at(i)) dt.at(i) = 0;
    // }
    // debug(dt);
    // for(int i = 0;i<a - 1;i++) {
    //     bool c = 0;
    //     for(int j = 0;j<a;j++) {
    //         for(int &k : v.at(j)) {
    //             if(dt.at(j) + 1 > dt.at(k)) {
    //                 dt.at(k) = dt.at(j) + 1;
    //                 c = 1;
    //             }
    //         }
    //     }
    //     // debug(dt);
    //     if(!c) return 1;
    // }
    // for(int j = 0;j<a;j++) {
    //     for(int &k : v.at(j)) {
    //         if(dt.at(j) + 1 < dt.at(k)) {
    //             return 0;
    //         }
    //     }
    // }
    // return 1;
}
int ck(int l,int r,vector<box>&f) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    if(check(mid,f)) return ck(l,mid,f);
    return ck(mid + 1,r,f);
}
void walk(vector<box>&f,int n) {
    vector<vector<box>>v(a);
    vector<int>to(a);
    for(int i = 0;i<b;i++) {
        if(f.at(i).z <= n) {
            v.at(f.at(i).y).push_back(box(f.at(i).x,i,1));
            v.at(f.at(i).x).push_back(box(f.at(i).y,i,0));
            continue;
        }
        v.at(f.at(i).x).push_back(box(f.at(i).y,-1,0));
        to.at(f.at(i).y)++;
    }
    debug(to);
    vector<bool>mark(a);
    vector<int>re;
    set<pair<int,int>>s;
    function<void(int,int)> check = [&] (int x,int t) {
        queue<box>q;
        q.emplace(x,-1);
        while(!q.empty()) {
            auto now = q.front();q.pop();
            int d = now.x;
            if(mark.at(d)) {
                if(now.y != -1 && now.z == 0) re.push_back(now.y);
                continue;
            }
            mark.at(d) = 1;
            if(now.y != -1 && now.z == 1) {
                re.push_back(now.y);
                s.insert({f.at(now.y).x,f.at(now.y).y});
            }
            for(box &i : v.at(d)) {
                q.push(box(i.x,i.y,i.z));
            }
        }
    };
    for(int i = 0;i<a;i++) if(!mark.at(i) && to.at(i) == 0) check(i,-1);
    set<int>r;
    for(int i = 0;i<b;i++) {
        if(s.find(make_pair(f.at(i).x,f.at(i).y)) != s.end()) r.insert(i);
    }
    for(int &i : re) r.insert(i);
    set<int>ans;
    for(int i : r) {
        for(int j : f.at(i).f) {
            ans.insert(j);
        }
    }
    cout<<ans.size()<<"\n";
    for(int i : ans) cout<<i + 1<<"\n";
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    map<pair<int,int>,pair<int,vector<int>>>m;
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        auto found = m.find({a,b});
        if(found == m.end()) m.insert({{a,b},{c,vector<int>({i})}});
        else {
            int r = found->second.first;
            found->second.first = max(r,c);
            found->second.second.push_back(i);
        }
    }
    vector<box>f;
    for(auto i : m) {
        f.push_back(box(i.first.first,i.first.second,i.second.first,i.second.second));
    }
    b = f.size();
    // sort(f.rbegin(),f.rend());
    int tmp = ck(0,(int) 1e9,f);
    cout<<tmp<<" ";
    // cerr<<1;
    walk(f,tmp);
    return 0;
}