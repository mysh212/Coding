// Author : ysh
// 12/13/2022 Tue 10:11:15.58
// https://tioj.ck.tp.edu.tw/problems/2228
// NF
#include<bits/stdc++.h>
using namespace std;
struct box{
    int x,y,r,t;
    explicit box(int x,int y,int r,int t):
        x(x), y(y), r(r), t(t) {};
    bool operator<(const box a) const {
        return r < a.r;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<box>f;
    vector<vector<box>>v(n);
    for(int i = 0;i<n;i++) {
        int a,b,c,d;cin>>a>>b>>c>>d;
        f.push_back(box(a,b,c,d));
        v.at(i).push_back(box(a - c,b,c,d));
        v.at(i).push_back(box(a,b + c,c,d));
        v.at(i).push_back(box(a,b - c,c,d));
        v.at(i).push_back(box(a + c,b,c,d));
    }
    int mmax = 0;
    for(auto t : v) for(box &i : t) {
        int x = i.x;
        int y = i.y;
        int ans = i.t;
        for(auto k : v) {
            for(auto &j : k) {
                if(abs(x - j.x) + abs(y - j.y) <= j.r) {
                    ans = ans + j.t;
                    break;
                }
            }
        }
        mmax = max(mmax,ans);
    }
    cout<<mmax;
    return 0;
}