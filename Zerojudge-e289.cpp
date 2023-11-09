// Author : ysh
// 2023/10/16 Mon 20:04:49
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<string>f(b);
    for(string &i : f) {
        cin>>i;
    }

    int l = 0,r = -1;
    map<string,int>mark;
    int now = 0;
    int ans = 0;
    while(r != b - 1) {
        r++;
        if(mark[f.at(r)] == 0) now++;
        mark[f.at(r)]++;
        if((r - l + 1) > a) {
            if(mark[f.at(l)] == 1) now--;
            mark[f.at(l)]--;
            l++;
        }
        if(now == a) ans++;
    }
    cout<<ans;
    return 0;
}