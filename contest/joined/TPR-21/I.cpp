// Author : ysh
// 05/31/2022 Tue 16:41:02.99
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int i = 0;i<a;i++) {
        cin>>f[i];
    }
    int hold = 0,sig = 0;
    for(int i = 0;i<a;i++) {
        cout<<f[i] * b;
    }
}