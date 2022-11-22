// Author : ysh
// 11/20/2022 Sun 22:35:38.45
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b,c;cin>>a>>b>>c;
        if(a == b && b == c) {
            cout<<"YES\n";
            continue;
        }
        a = a - b - c;
        if(a >= 2) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}