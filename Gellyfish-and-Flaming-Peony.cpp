// Author : ysh
// 2025/05/31 Sat 23:23:45
// https://codeforces.com/contest/2116/problem/C
// WA
#include<bits/stdc++.h>
using namespace std;
int check(deque<int>&f, int target, int n = -1, int now = -1, int sig = 0, int x = 0) {
    if(n == -1) n = f.size();
    if(now == target) return sig;
    if(x == n) return INT_MAX;
    int i = f.at(x);
    {
        int p = (now == -1 ? i : __gcd(now, i));
        return min(check(f, target, n, p, sig + 1, x + 1), check(f, target, n, now, sig, x + 1));
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>f(n);
        for(int &i : f) cin>>i;
        sort(f.begin(), f.end());

        deque<int>pre({f[0]});
        int target = f[0];
        int preq = -1;
        for(int &i : f) {
            int tmp = __gcd(target, i);
            if(tmp != target) pre.push_back(i), preq = (preq == -1 ? i : __gcd(preq, i));
            target = tmp;
        }

        if(preq == target) pre.pop_front();

        // int l, r;l = r = -1;
        // for(int i = 0;i<n;i++) {
        //     for(int j = 0;j<n;j++) {
        //         if(__gcd(f[i], f[j]) == target) {
        //             l = i, r = j;
        //             break;
        //         }
        //     }
        //     if(!(l == -1 && r == -1)) break;
        // }

        int m = check(pre, target);

        // cerr<<target<<" "<<l<<" "<<r<<" -\n";
        // for(int &i : pre) cerr<<i<<" ";
        // cerr<<"\n";

        int ans = -1;
        for(int &i : f) if(i != target) ans++;

        int tmp = m;
        if(tmp == 1) cout<<ans + 1<<"\n";
        else cout<<tmp - 1 + ans<<"\n";
        
        // for(int i = 0;i<n;i++) {
        //     for(int j =0 ;j<n;j++) {
        //         cout<<__gcd(f[i], f[j])<<" ";
        //     }
        //     cout<<"\n";
        // }
    }
    return 0;
}