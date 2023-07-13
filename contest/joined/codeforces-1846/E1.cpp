// Author : ysh
// 2023/07/07 Fri 23:17:47
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    set<int>s({});
    for(int i = 2;i<=1000;i++) {
        long long now = 1 + i;
        for(long long j = i * i;now <= int(1e6);j = j * i) {
            now = now + j;
            s.insert(now);
        }
    }

    int n;cin>>n;
    while(n--) {
        int tmp;cin>>tmp;
        if(s.find(tmp) != s.end()) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}