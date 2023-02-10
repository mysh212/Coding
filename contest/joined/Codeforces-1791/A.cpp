// Author : ysh
// 02/03/2023 Fri 22:45:31.43
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    const string a = "codeforces";
    int n;cin>>n;
    while(n--) {
        char t;cin>>t;
        if(a.find(t) != -1) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}