// Author : ysh
// 09/27/2022 Tue 10:46:25.13
// https://codeforces.com/contest/1734/problem/C
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int m;cin>>m;
        bitset<1000001>s,t;
        s.reset();
        string a;cin>>a;
        for(int i = 0,len = a.size();i<len;i++) {
            if(a.at(i) == '1') s.set(i + 1);
        }
        int ans = 0;
        for(int i = 1;i<=m;i++) {
            int now = i;
            if(!s.test(now)) {
                ans += now;
                s.set(now);
                for(int j = (now << 1);j <= m;j = j + now) {
                    if(!s.test(j)) {
                        ans += now;
                        s.set(j);
                    } else {
                        break;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}