// Author : ysh
// 03/09/2022 Wed 10:23:30.16
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    set<int>f;
    int tmp,ans = 0;
    for(int i = 0;i<a;i++) {
        cin>>tmp;
        f.insert(tmp);
    }
    for(int i = 0;i<b;i++) {
        cin>>tmp;
        int d = f.count(c - tmp);
        if(d != 0) {
            ans += d;
        }
    }
    cout<<ans;
    return 0;
}