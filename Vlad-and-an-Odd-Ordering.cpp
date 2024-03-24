// Author : ysh
// 2024/02/22 Thu 17:59:49
// https://codeforces.com/contest/1926/problem/E
#include<bits/stdc++.h>
using namespace std;
#include<fast>
int check(int n,int x) {
    int pre = (n + 1) >> 1;
    if(x - pre <= 0) return (x << 1) - 1;
    return (check(n >> 1,x - pre) << 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        cout<<check(a,b)<<"\n";
    }
    return 0;
}