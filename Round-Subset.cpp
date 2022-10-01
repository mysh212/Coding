// Author : ysh
// 09/30/2022 Fri  8:40:15.16
// https://codeforces.com/contest/837/problem/D
#include<bits/stdc++.h>
using namespace std;
// #define int long long
int a,b;
pair<int,int> ts(pair<int,int>a,pair<int,int>b) {
    return {a.first + b.first,a.second + b.second};
}
inline pair<int,int> operator+(pair<int,int>a,pair<int,int>b) {
    return {a.first + b.first,a.second + b.second};
}
inline int get(pair<int,int>a) {
    return min(a.first,a.second);
}
vector<pair<int,int>>f;
vector<vector<pair<pair<int,int>,pair<int,int>>>>mark;
pair<int,int> check(int x,int r,pair<int,int>now) {
    if(x == a || r == b) return {0,0};
    if(mark.at(x).at(r) != make_pair(make_pair(0,0),make_pair(0,0))) {
        // auto ff = now + mark.at(x).at(r).first;
        // auto sc = now + mark.at(x).at(r).second;
        // if(get(ff) == get(sc)) {
        //     return (ff.first + ff.second > sc.first + sc.second ? )
        // }
        if(get(now + mark.at(x).at(r).first) > get(now + mark.at(x).at(r).second)) {
            return (mark.at(x).at(r).first);
        }
        return (mark.at(x).at(r).second);
    }
    auto as = check(x + 1,r + 1,now + f.at(x));
    auto ns = check(x + 1,r,now);
    as = as + f.at(x);
    mark.at(x).at(r) = make_pair(as,ns);
    return (get(now + as) > get(now + ns) ? as : ns);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    f.resize(1);
    while(a--) {
        long long tmp;cin>>tmp;
        while(!(tmp & 1)) {
            tmp = tmp >> 1;
            f.back().first++;
        }
        while(tmp % 5 == 0) {
            tmp = tmp / 5;
            f.back().second++;
        }
        if(f.back() != make_pair(0,0)) {
            f.push_back({0,0});
        }
    }
    a = f.size();
    mark.resize(a,vector<pair<pair<int,int>,pair<int,int>>>(b + 1));
    // for(int i = 0;i<a;i++) {
    //     long long tmp;cin>>tmp;
    //     while(!(tmp & 1)) {
    //         tmp = tmp >> 1;
    //         f.at(i).first++;
    //     }
    //     while(tmp % 5 == 0) {
    //         tmp = tmp / 5;
    //         f.at(i).second++;
    //     }
    // }
    /*
    sort(f.begin(),f.end(),[] (pair<int,int>a,pair<int,int>b) {
        return a.first + a.second > b.first + b.second;
    });
    for(auto i : f) cerr<<i.first<<" ";
    cerr<<"\n";
    for(auto i : f) cerr<<i.second<<" ";
    cerr<<"\n";
    */
    cout<<get(check(0,0,{0,0}));
    return 0;
}