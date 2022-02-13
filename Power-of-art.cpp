// Author : ysh
// 02/13/2022 Sun 14:21:09.41
// https://codeforces.com/group/H0qY3QmnOW/contest/366708/problem/C
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b,c;cin>>a>>b>>c;
        if(a > b) {
            cout<<"penguin"<<"\n";
        } else {
            cout<<"Ginorz"<<"\n";
        }
    }
    return 0;
}