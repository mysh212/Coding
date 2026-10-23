// Author : ysh
// 2026/10/22 Thu 18:55:16
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;cin>>a>>b;

    vc<vc<int>>f(a);
    vc<int>in(a);
    re(b) {
        int a, b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
        in.at(a)++;
        in.at(b)++;
    }

    vc<bool>ok(a);
    int ct = 0;
    re(i, a) if(in.at(i) >= 4) ct++, ok.at(i) = 1;
    debug(ct);
    debug(ok);
    if(ct >= 2) return out(a), 0;

    vc<bool>mark(a);
    function<bool(int)> check = [&] (int x) {
        queue<pair<int, int>>q;
        vc<bool>mk(a);
        q.push({0, x});

        int ans = 0;
        while(!mk.empty()) {
            auto [l, d] = q.front(); q.pop();

            if(mk.at(d)) continue;
            mk.at(d) = 1;

            if(ans >= 2) break;

            if(l >= 2) {
                ans++;
                continue;
            }

            for(int &i : f.at(d)) q.push({l + 1, i});
        }

        return ans >= 2;
    };

    re(i, a) ok.at(i) = ok.at(i) || check(i);

    ct = 0;
    re(i, a) if(ok.at(i)) ct++;

    if(ct >= 2) return out(a), 0;

    out(ct);
    return 0;
}