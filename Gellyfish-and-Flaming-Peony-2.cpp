// Author : ysh
// 2025/06/06 Fri 09:47:24
// https://codeforces.com/contest/2116/problem/C
#include<bits/stdc++.h>
using namespace std;
#include<slow>
#define MAX 5001
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    re(n) {
        int n;cin>>n;
        vc<int>f(n);
        cin>>f;

        auto g = f;
        sort(all(f));
        f.resize(unique(all(f)) - f.begin());
        
        int target = f.at(0);
        repo(&i, f) target = __gcd(target, i);

        if(binary_search(all(f), target)) {
            int ans = 0;
            repo(&i, g) if(i != target) ans++;
            outl(ans);
            continue;
        }

        int ans = -1;
        vc<bool>mark(MAX);
        queue<pair<int,int>>q;
        repo(&i, f) q.emplace(0, i);
        while(!q.empty()) {
            auto now = q.front();q.pop();
            int l = now.first;
            int d = now.second;

            if(d == target) {
                ans = l;
                break;
            }

            if(mark.at(d)) continue;
            mark.at(d) = 1;

            repo(&i, f) q.emplace(l + 1, __gcd(d, i));
        }

        // debug(ans);
        outl(n - 1 + ans);
    }
    return 0;
}