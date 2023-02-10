// Author : ysh
// 01/25/2023 Wed  8:53:39.32
// https://codeforces.com/contest/1792/problem/B
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b,c,d;cin>>a>>b>>c>>d;
        cout<<vector<int>({1,a + (min(b,c) << 1) + min(a + 1,abs(b - c) + d)})[a != 0]<<"\n";
    }
    return 0;
}