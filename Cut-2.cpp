// Author : ysh
// 01/01/2023 Sun  8:43:50.95
// https://192.168.193.20/problem/25
#include<bits/stdc++.h>
using namespace std;
int n,c[3];
vector<int>mark;
int check(int r) {
    if(r == 0) return 0;
    if(r < 0) return INT_MIN;
    if(mark.at(r) != 0) return mark.at(r);
    int mmax = INT_MIN;
    for(int i = 0;i<=2;i++) {
        mmax = max(mmax,check(r - c[i]));
    }
    return mark.at(r) = mmax + 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>c[0]>>c[1]>>c[2];
    mark.resize(n + 1);
    cout<<check(n);
    return 0;
}