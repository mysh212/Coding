// Author : ysh
// 2025/03/29 Sat 19:34:14
// https://cses.fi/problemset/task/1619
#include<bits/stdc++.h>
using namespace std;
// #include<seg_tree>
#include<slow>
int offline(vc<pair<int,int>>&f) {
    vc<int>pre;
    repo(&i, f) pre.push_back(i.first), pre.push_back(i.second);

    sort(all(pre));
    pre.resize(unique(all(pre)) - pre.begin());

    repo(&i, f) {
        i.first = lower_bound(all(pre), i.first) - pre.begin();
        i.second = lower_bound(all(pre), i.second) - pre.begin();
    }

    return pre.size();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vc<pair<int,int>>f(n);
    cin>>f;

    repo(&i, f) if(i.first > i.second) swap(i.first, i.second);
    
    int m = offline(f);
    vc<int>mark(m + 1);

    repo(&i, f) {
        mark.at(i.first)++;
        mark.at(i.second + 1)--;
    }

    int last = 0;
    repo(&i, mark) i = last += i;

    out(*max_element(all(mark)));
    return 0;
}