// Author : ysh
// 09/16/2022 Fri 11:07:18.90
// https://atcoder.jp/contests/dp/tasks/dp_s
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;cin>>a;
    vector<int>f;
    for(char i : a) {
        f.push_back(i - '1' + 1);
    }
    int n = f.size();
    int m;cin>>m;
    int c[n][m][2] = {};
}