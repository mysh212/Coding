// Author : ysh
// 02/13/2022 Sun 15:39:52.90
// https://codeforces.com/group/H0qY3QmnOW/contest/366708/problem/H
#include<bits/stdc++.h>
using namespace std;
#define int long long
int check(int &a,int &b,int &c) {
    //cout<<((a^b^c)|(a|(b^c)) + (a^c) + (a|b|c) + (c|a)^((a + b)|c))<<" ";
    return ((a^b^c)|(a|(b^c))) + (a^c) + (a|b|c) + ((c|a)^((a + b)|c));
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b,c;cin>>a>>b>>c;
        cout<<max(check(a,b,c),max(check(b,a,c),max(check(a,c,b),max(check(c,a,b),max(check(b,c,a),check(c,b,a))))))<<"\n";
    }
}