// Author : ysh
// 10/23/2022 Sun 10:34:15.50
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define R 0
#define D 1
#define L 2
#define U 3
struct box{
    int x,y,d;
    box(int x = 0,int y = 0,int d = 0):
        x(x), y(y), d(d) {};
    inline bool operator<(const box a) const {
        if(x == a.x) return y < a.y;
        return x < a.x;
    }
};
int ans = 0;
/*
R + 1 == D
L + 1 == U
U + 1 == L
D + 1 == R

R + 0 == U
L + 0 == D
U + 0 == R
D + 0 == L
*/
inline int touch(int a,int b) {
    // cerr<<a<<b;
    ans++;
    if(a == R && b == 1) return D;
    if(a == L && b == 1) return U;
    if(a == U && b == 1) return L;
    if(a == D && b == 1) return R;
    if(a == R && b == 0) return U;
    if(a == L && b == 0) return D;
    if(a == U && b == 0) return R;
    if(a == D && b == 0) return L;
    exit(-1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<box>f(n);
    gp_hash_table<int,map<int,int>>mx,my;
    for(auto &i : f) {
        cin>>i.x>>i.y>>i.d;
        auto found = mx.find(i.x);
        if(found == mx.end()) mx.insert({i.x,map<int,int>({{i.y,i.d}})});
        else found->second.insert({i.y,i.d});
        found = my.find(i.y);
        if(found == my.end()) my.insert({i.y,map<int,int>({{i.x,i.d}})});
        else found->second.insert({i.x,i.d});
    }
    // for(auto &i : mx) {
    //     for(auto &j : i.second) {
    //         cout<<i.first<<" "<<j.first<<" "<<j.second<<"\n";
    //     }
    //     cout<<"\n";
    // }
    int xx = 0,yy = 0,dd = R;
    while(1) {
        if(dd == R) {
            auto found = my.find(yy);
            if(found == my.end()) break;
            else {
                auto ffound = found->second.upper_bound(xx);
                if(ffound == found->second.end()) break;
                else {
                    xx = ffound->first;
                    dd = touch(dd,ffound->second);
                }
            }
        }
        if(dd == L) {
            auto found = my.find(yy);
            if(found == my.end()) break;
            else {
                auto ffound = prev(found->second.lower_bound(xx));
                if(next(ffound) == found->second.begin()) break;
                else {
                    xx = ffound->first;
                    dd = touch(dd,ffound->second);
                }
            }
        }
        if(dd == U) {
            auto found = mx.find(xx);
            if(found == my.end()) break;
            else {
                auto ffound = found->second.upper_bound(yy);
                if(ffound == found->second.end()) break;
                else {
                    yy = ffound->first;
                    dd = touch(dd,ffound->second);
                }
            }
        }
        if(dd == D) {
            auto found = mx.find(xx);
            if(found == my.end()) break;
            else {
                auto ffound = prev(found->second.lower_bound(yy));
            // cerr<<"\n"<<xx<<yy<<"\n";
                if(next(ffound) == found->second.begin()) break;
                else {
                    yy = ffound->first;
                    dd = touch(dd,ffound->second);
                }
            }
        }
    }
    cout<<ans;
    return 0;
}