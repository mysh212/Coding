// Author : ysh
// 10/22/2022 Sat 21:13:29.20
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

vector<int>now;
vector<bool>mark;
bool check(int n,vector<pair<int,int>>&f) {
    int c[2] = {f.at(n).first,f.at(n).second};
    debug(now);
    system("pause");
    for(int i = 0;i<=1;i++) {
        int r = c[i];
        if(mark.at(r)) continue;
        mark.at(r) = 1;
        if(now.at(r) != -1) {
            if(!check(now.at(r),f)) continue;
        }
        now.at(r) = n;
        return 1;
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    now = vector<int>(a + b + 1,-1);
    vector<pair<int,int>>f(c);
    for(auto &i : f) {
        cin>>i.first>>i.second;
        i.second = a + i.second;
        cerr<<i.first<<" "<<i.second<<"\n";
    }
    int ans = 0;
    for(int i = 0;i<c;i++) {
        mark = vector<bool>(a + b + 1);
        if(check(i,f)) ans++;
    }
    cout<<ans;
    return 0;
}