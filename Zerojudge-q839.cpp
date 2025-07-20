// Author : ysh
// 2025/06/18 Wed 18:24:07
#include<bits/stdc++.h>
using namespace std;
#include<fast>
#include<slow>
vc<int>color;
inline int ff(int x) {
    if(color.at(x) == x) return x;
    return color.at(x) = ff(color.at(x));
}
inline void mg(int a,int b) {
    color.at(ff(a)) = ff(b);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vc<vc<int>>f(a, vc<int>(a));
    cin>>f;

    vc<array<int, 3>>pre;
    re(i, a) re(j, i + 1, a) pre.push_back({i, j, f.at(i).at(j)});

    sort(all(pre), [](array<int, 3> &a, array<int, 3> &b) {
        return a[2] < b[2];
    });

    color = vc<int>(a);
    iota(all(color), 0);

    int groups = a;
    repo(&i, pre) {
        if(groups <= b) break;
        if(ff(i[0]) == ff(i[1])) continue;
        mg(i[0], i[1]);
        groups--;
    }

    repo(&i, pre) if(ff(i[0]) != ff(i[1])) return out(i[2]), 0;

    return -1;
}