// Author : ysh
// 05/06/2023 Sat 22:36:45.57
#include<bits/stdc++.h>
using namespace std;
const string a = "codeforces";
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        string tmp;cin>>tmp;
        int ans = 0;
        for(int i = 0;i<=9;i++) {
            if(a.at(i) != tmp.at(i)) ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}