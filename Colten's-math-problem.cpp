// Author : ysh
// 02/13/2022 Sun 15:19:55.74
// https://codeforces.com/group/H0qY3QmnOW/contest/366708/problem/G
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a,b;
    cin>>a>>b;
    int aa,bb;aa=bb=0;
    for(char i : a) {
        int tmp = ((int) (i - 'A')) + 1 + 2022;
        aa = aa * 10000 + tmp;
    }
    for(char i : b) {
        int tmp = ((int) (i - 'A')) + 1 + 2022;
        bb = bb * 10000 + tmp;
    }
    cout<<aa + bb;
}