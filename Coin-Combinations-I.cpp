// Author : ysh
// 2024/03/10 Sun 20:59:26
// https://cses.fi/problemset/task/1635
#include<bits/stdc++.h>
using namespace std;
const int R = int(1e9) + 7;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
// #include<fast>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;cin>>n>>m;
    vector<int>f(n);
    for(auto &i : f) cin>>i;
    // sort(f.begin(),f.end());

    vector<int>mark(m + 1,0);
    mark.at(0) = 1;
    for(int i = 0;i<=m;i++) {
        for(int &j : f) {
            if(i - j >= 0) mark.at(i) = (mark.at(i) + mark.at(i - j)) % R;
        }
    }

    cout<<mark.back();
    return 0;
}