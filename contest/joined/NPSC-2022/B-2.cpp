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
int check(string a,string b) {
    int aa = a.size();
    int bb = b.size();
    vector<vector<int>>f(aa,vector<int>(bb));
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