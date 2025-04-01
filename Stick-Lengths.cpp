// Author : ysh
// 2025/03/31 Mon 11:59:49
// https://cses.fi/problemset/task/1074
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int n;
#define int long long
vc<int>f;
inline int check(int x) {
    int ans = 0;
    repo(&i, f) ans += abs(i - x);
    return ans;
}
inline int ck(int l, int r) {
    int mid = (l + r) >> 1;
    int mmin = check(mid);
    for(int i = 30;i>=0;i--) {
        int jump = (1 << i);
        
        for(int j = 1;j>=-1;j = j - 2) {
            if(mid + jump * j > r || mid + jump * j < l) continue;
            int ans = check(mid + jump * j);
            if(ans < mmin) {
                mmin = ans;
                mid = mid + jump * j;
                break;
            }
        }
    }
    return mmin;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    f = vc<int>(n);
    cin>>f;

    out(ck(0, *max_element(all(f))));
    return 0;
}