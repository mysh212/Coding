// Author : ysh
// 09/18/2022 Sun  9:20:33.41
// https://cses.fi/problemset/result/4647467/
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int c[a + 1] = {};
    for(int i = 1;i<=a;i++) {
        cin>>c[i];
        c[i] = c[i] ^ c[i - 1];
    }
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        cout<<(c[max(a,b)] ^ c[min(a,b) - 1])<<"\n";
    }
    return 0;
}