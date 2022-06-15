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
    bool operator<(const box &c)
    {
        return a < c.a;
    }
    box(int a,int b):
        a(a),b(b) {}
};
inline bool cp(box a,box b) {
    return a<b;
}
void check(int &c,int &d,int &x,int &y) {
            if(c == 0) {
                if(d == 0) {
                    // y++;
                    d = 1;
                } else if(d == 1) {
                    // x++;
                    d = 0;
                } else if(d == 2) {
                    // y--;
                    d = 3;
                } else {
                    // x--;
                    d = 2;
                }
            } else {
                if(d == 0) {
                    // y--;
                    d = 3;
                } else if(d == 1) {
                    // x--;
                    d = 2;
                } else if(d == 2) {
                    // y++;
                    d = 1;
                } else {
                    // x++;
                    d = 0;
                }
            }
            return;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

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
            // for(box i : g[s[x]]) {
            //     cout<<i.a<<" "<<i.b<<" ";
            // }
            // cout<<"\n";
            // int tmp = tmp;
            // debug(f[tmp]);
            auto found = upper_bound(f[tmp].begin(),f[tmp].end(),box(y,0),cp);
                // cout<<1;
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
            // for(box i : f[tmp]) {
            //     cout<<i.a<<" "<<i.b<<"\n";
            // }
            // cout<<"\n";
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
            // for(auto i : g[tmp]) {
            //     cout<<y<<" "<<i.a<<" ";
            // }
            // cout<<"\n";
            auto found = upper_bound(g[tmp].begin(),g[tmp].end(),box(x,0),cp);
            // cout<<y<<" "<<found->a<<" "<<found - g[tmp].begin()<<"\n";
            if(found != g[tmp].end()) {
                x = (found)->a;
                int c = (found)->b;
                check(c,d,x,y);
                debug(x,y,d);
                continue;
            }
        }

        // system("pause");
        // cout<<x<<" "<<y<<"\n";
        // if(x == 30000 || y == 30000 || x == -30000 || y == -30000) {
        //     break;
        // }
        // auto found = m.find({x,y});
        // if(found != m.end()) {
        //     ans++;
        //     int c = found->second;
        //     if(c == 0) {
        //         if(d == 0) {
        //             y++;
        //             d = 3;
        //         } else if(d == 1) {
        //             x--;
        //             d = 2;
        //         } else if(d == 2) {
        //             y--;
        //             d = 1;
        //         } else {
        //             x++;
        //             d = 0;
        //         }
        //     } else {
        //         if(d == 0) {
        //             y--;
        //             d = 1;
        //         } else if(d == 1) {
        //             x++;
        //             d = 0;
        //         } else if(d == 2) {
        //             y++;
        //             d = 3;
        //         } else {
        //             x--;
        //             d = 2;
        //         }
        //     }
        //     continue;
        // }

        cout<<--ans;
        return 0;
        // if(d == 0 || d == 2) {
        //     if(d == 0) {
        //         x++;
        //     } else {
        //         x--;
        //     }
        // }
        // if(d == 1 || d == 3) {
        //     if(d == 1) {
        //         y--;
        //     } else {
        //         y++;
        //     }
        // }
    }
    cout<<--ans;
    return 0;
}