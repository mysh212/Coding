// Author : ysh
// 11/07/2022 Mon 11:07:36.00
// https://cses.fi/problemset/task/2190
#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
inline pair<int,int> operator-(pair<int,int>a,pair<int,int>b) {
    return make_pair(a.x - b.x,a.y - b.y);
}
inline int operator| (pair<int,int>a,int x) {
    return a.x * a.x + a.y * a.y;
}
inline int operator* (pair<int,int>a,pair<int,int>b) {
    return a.x * b.x + a.y * b.y;
}
inline bool operator% (pair<int,int>a,pair<int,int>b) {
    if(b.x * a.y == b.y * a.x) return 1;
    return 0;
}
inline int operator^ (pair<int,int>a,pair<int,int>b) {
    return a.x * b.y - b.x * a.y;
}
inline bool each(pair<int,int>a,pair<int,int>b,pair<int,int>c,pair<int,int>d) {
    return (((b - a) ^ (c - a)) * ((b - a) ^ (d - a)) <= 0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        pair<int,int> a,b,c,d;cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
        cout<<(each(a,b,c,d) && each(c,d,a,b) ? "YES" : "NO")<<"\n";
    }
    return 0;
}