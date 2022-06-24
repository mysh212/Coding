// Author : ysh
// 06/21/2022 Tue 16:16:58.00
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
    int now = 0;
    // int last = -1;
    queue<int>q;
    for(int i = 0;i<lenb;i++) {
        if(now == lena) {
            now = 0;
            ans++;
            if(!q.empty()) {
                i = q.front();
                q.pop();
            }
        }
        debug(i,now);
        if(b[i] == a[0]) q.push(i);
        if(b[i] == a[now]) {
            if((!q.empty()) && now == 0 && q.front() == i) {
                q.pop();
            }
            now++;
            continue;
        }
        if(b[i] != a[now] && now != 0) {
            now = 0;
            if(!q.empty()) {
                i = q.front();
                q.pop();
            }
            continue;
        }
    }
    if(now == lena) {
        now = 0;
        ans++;
    }
    cout<<(ans == n ? "YES" : "NO");
    return 0;
}