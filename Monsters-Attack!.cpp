// Author : ysh
// 2024/09/20 Fri 16:58:58
// https://codeforces.com/contest/1923/problem/B
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    re(n) {
        int a,b;cin>>a>>b;
        vc<pair<int,int>> f(a);
        repo(&i,f) cin>>i.second;
        repo(&i,f) cin>>i.first;

        sort(rall(f));
        int t = 0;
        while(!f.empty()) {
            int k = b;
            while(k != 0) {
                auto now = f.back();f.pop_back();
                now.second -= (k -= min(k,now.second));
                if(now.second != 0) f.push_back({now.first,now.second});
            }
        }
    }
}