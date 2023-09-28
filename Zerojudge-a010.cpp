// Author : ysh
// 2023/06/29 Thu 10:54:08
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    bool c = false;

    for(int i = 2,len = n;i<=len;i++) {
        int ans = 0;
        while(n % i == 0) {
            n = n / i;
            ans++;
        }
        if(ans == 1) cout<<(c ? "* " : "")<<i<<" ",c = 1;
        else if(ans != 0) cout<<(c ? "* " : "")<<i<<"^"<<ans<<" ",c = 1;
    }
    return 0;
}