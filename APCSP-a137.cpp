// Author : ysh
// 12/08/2022 Thu  9:16:23.78
// https://apcsclass.csie.ntnu.edu.tw/ShowProblem?problemid=a137
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

#define att(a) color.at(a.first).at(a.second)
int a,b;
int fx,fy,gx,gy;
vector<vector<pair<int,int>>>color;
pair<int,int> ff(pair<int,int>a) {
    if(att(a) == make_pair(-1,-1)) return att(a) = a;
    if(att(a) == a) return a;
    return att(a) = ff(att(a));
}
inline void mg(pair<int,int>a,pair<int,int>b) {
    // debug(a,b);
    att(ff(a)) = ff(b);
    return;
}
bool check(int r,vector<vector<int>>&f) {
    color = vector<vector<pair<int,int>>>(a,vector<pair<int,int>>(b,{-1,-1}));
    for(int i = 0;i<a;i++) {
        for(int j = 0;j<b;j++) {
            if(i != a - 1) {
                if(max(f.at(i).at(j),f.at(i + 1).at(j)) <= r) mg({i,j},{i + 1,j});
            }
            if(j != b - 1) {
                if(max(f.at(i).at(j),f.at(i).at(j + 1)) <= r) mg({i,j},{i,j + 1});
            }
        }
    }
    return ff({fx,fy}) == ff({gx,gy});
}
int ck(int l,int r,vector<vector<int>>&f) {
    // cerr<<l<<" "<<r<<"\n";
    if(l == r) return l;
    int mid = (l + r) >> 1;
    if(check(mid,f)) return ck(l,mid,f);
    return ck(mid + 1,r,f);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    cin>>fx>>fy>>gx>>gy;
    int r;cin>>r;
    vector<vector<int>>f(a,vector<int>(b,INT_MAX));
    f.at(fx).at(fy) = f.at(gx).at(gy) = 0;
    int mmax = 0;
    for(int i = 0;i<r;i++) {
        int a,b,c;cin>>a>>b>>c;
        f.at(a).at(b) = c;
        mmax = max(mmax,c);
    }
    // for(int i = 0;i<a;i++) {
    //     for(int j = 0;j<b;j++) {
    //         if(f.at(i).at(j) == INT_MAX) {
    //             cout<<"0 ";
    //             continue;
    //         }
    //         cerr<<f.at(i).at(j)<<" ";
    //     }
    //     cerr<<"\n";
    // }
    cout<<ck(0,mmax,f);
    return 0;
}