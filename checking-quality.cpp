// Author : ysh
// 10/15/2022 Sat 19:00:12.57
// https://www.luogu.com.cn/problem/P2251
#include<bits/stdc++.h>
using namespace std;
#define c(a,b) min(a,b)
#include<table>
#undef c
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
    }
    table<int> t(f);
    for(int i = 0;i + b - 1 < a;i++) {
        cout<<t.get(i,i + b - 1)<<"\n";
    }
    return 0;
}