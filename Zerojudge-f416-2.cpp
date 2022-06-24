// Author : ysh
// 06/21/2022 Tue 16:49:27.53
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int ans = 0;
    int n;cin>>n;
    string a,b;cin>>a>>b;
    int lena = a.size(),lenb = b.size();
    // int now = 0;
    // int last = -1;
    vector<int>q;
    for(int i = 0;i<lenb;i++) {
        if(b[i] == a[0]) q.push_back(i);
    }
    while(!q.empty()) {
        int aa = q.front();q.pop_back();
        if(aa >= lenb) continue;
        int now = 0;
        bool c = 0;
        for(int i = aa;i<lenb;i++) {
            if(now >= lena) {
                break;
            }
            if(b[i] != a[now++]) {
                c = 1;
                continue;
            }
            if(now >= lena) {
                break;
            }
        }
        if(!c && now == lena) ans++;
    }
    debug(ans);
    cout<<(ans == n ? "YES" : "NO");
    return 0;
}