// Author : ysh
// 06/12/2022 Sun 17:32:48.08
#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

struct box{
    int a,b;
    bool operator<(box &c)
    {
        return a < c.a;
    }
    // bool operator<(int &c)
    // {
    //     return a < c;
    // }
    box(int a,int b):
        a(a),b(b) {}
};
// inline bool operator<(box b,box a) {
//     return b.a<a.a;
// }
inline bool cp(box a,box b) {
    return a<b;
}
inline void check(int&,int&,int&,int&);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int t = 0;
    int r = 0;
    vector<vector<box>>f,g;
    map<int,int>m,s;
    for(int i = 0;i<n;i++) {
        int a,b,c;cin>>a>>b>>c;
        int nowx,nowy;
        if(m.find(a) == m.end()) {
            m.insert({a,t++});
            f.resize(t);
            nowx = t - 1;
        } else {
            nowx = m.find(a)->second;
        }
        if(s.find(b) == s.end()) {
            s.insert({b,r++});
            g.resize(r);
            nowy = r - 1;
        } else {
            nowy = s.find(b)->second;
        }
        f[nowx].push_back({b,c});
        g[nowy].push_back({a,c});
    }
    for(auto &i : f) {
        sort(i.begin(),i.end());
    }
    for(auto &i : g) {
        sort(i.begin(),i.end());
    }
    int ans = 0;
    int x = 0,y = 0,d = 0;
    while(1) {
        debug(x,y,d);
        ans++;
        if(d == 1) {
            auto founds = m.find(x);
            if(founds == m.end()) break;
            int tmp = founds->second;
            auto found = upper_bound(f[tmp].begin(),f[tmp].end(),box(y,0),cp);
            if(found != f[tmp].end()) {
                y = (found)->a;
                int c = (found)->b;
                check(c,d,x,y);
                continue;
            }
        }
        if(d == 2) {
            auto founds = s.find(y);
            if(founds == s.end()) break;
            int tmp = founds->second;
            auto found = --lower_bound(g[tmp].begin(),g[tmp].end(),box(x,0),cp);
            if(found != --g[tmp].begin()) {
                x = (found)->a;
                int c = (found)->b;
                check(c,d,x,y);
                continue;
            }
        }
        if(d == 3) {
            auto founds = m.find(x);
            if(founds == m.end()) break;
            int tmp = founds->second;
            auto found = --lower_bound(f[tmp].begin(),f[tmp].end(),box(y,0),cp);
            if(found - f[tmp].begin() != -1) {
                y = (found)->a;
                int c = (found)->b;
                check(c,d,x,y);
                continue;
            }
        }
        if(d == 0) {
            auto founds = s.find(y);
            if(founds == s.end()) break;
            int tmp = founds->second;
            auto found = upper_bound(g[tmp].begin(),g[tmp].end(),box(x,0),cp);
            if(found != g[tmp].end()) {
                x = (found)->a;
                int c = (found)->b;
                check(c,d,x,y);
                debug(x,y,d);
                continue;
            }
        }
        cout<<--ans;
        return 0;
    }
    cout<<--ans;
    return 0;
}
void check(int &c,int &d,int &x,int &y) {
            if(c == 0) {
                if(d == 0) {
                    d = 1;
                } else if(d == 1) {
                    d = 0;
                } else if(d == 2) {
                    d = 3;
                } else {
                    d = 2;
                }
            } else {
                if(d == 0) {
                    d = 3;
                } else if(d == 1) {
                    d = 2;
                } else if(d == 2) {
                    d = 1;
                } else {
                    d = 0;
                }
            }
            return;
}