// Author : ysh
// 08/08/2022 Mon 16:43:20.40
// https://cses.fi/problemset/task/1083
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    bitset<200000>s;
    s.set();
    for(int i = 1;i<n;i++) {
        int tmp;cin>>tmp;
        s.reset(tmp - 1);
    }
    cout<<s._Find_first() + 1;
    return 0;
}