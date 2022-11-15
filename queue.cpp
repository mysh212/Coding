// Author : ysh
// 11/10/2022 Thu 16:17:33.71
// http://192.168.8.39/problem/N2020G
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f;
    while(b--) {
        int tmp;cin>>tmp;
        int now = f.back();f.pop_back();
        // tmp--;
        int c = 0;
        int ans = tmp;
        while(now <= tmp) {
            c++;
            tmp++;
            ans += tmp - now;
        }
        while(c--) f.push_back(tmp--);
        cout<<ans<<"\n";
    }
}