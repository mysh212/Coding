// Author : ysh
// 11/12/2022 Sat 10:08:40.49
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

vector<int>ans;
bool check(string a) {
    vector<int>f(a.size());
    // int ans = 0;
    for(int i = 1,len = a.size();i < len;i++) {
        int p = f[i - 1];
        while(a[p] != a[i] && p != 0) p = f[p - 1];
        if(a[p] == a[i]) f[i] = p + 1;
    }
    ans.push_back(f.back());
    int p = f[a.size() - 1];
    while(p != 0) {
        p = f[p - 1];
        if(a[p] == a[a.size() - 1]) ans.push_back(p + 1);
    }
    debug(f);
    debug(ans);
    return !(f.at(a.size() - 1) == 0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;cin>>a;
    int m;cin>>m;
    string b;
    while(m--) {
        cin>>b;
        // cerr<<1;
        if(!check(b + " " + a)) {
            cout<<"-1\n";
            ans.clear();
            continue;
        }
        int r = 0;
        while(!ans.empty()) {
            // int r = b.size() - tmp;
            r = max(r,min(ans.back(),((int) b.size()) - ans.back()));ans.pop_back();
        }
        cout<<r<<"\n";
    }
    return 0;
}