// Author : ysh
// 2025/06/18 Wed 18:30:57
#include<bits/stdc++.h>
using namespace std;
#include<fast>
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vc<long long>f(a);
    cin>>f;

    vc<int>l(a), r(a);
    iota(all(l), -1);
    iota(all(r), 1);
    r.back() = -1;

    auto concat = [&] (int x) {
        int ll = l.at(x);
        int rr = r.at(x);

        if(ll != -1) r.at(ll) = rr;
        if(rr != -1) l.at(rr) = ll;
        return;
    };

    #define left(i) l.at(i)
    #define right(i) r.at(i)

    set<pair<long long,int>>s;
    re(i, a) s.insert({f.at(i), i});

    long long ans = 0;
    while(!s.empty()) {
        auto now = *s.begin(); s.erase(s.begin());
        long long w = now.first;
        int d = now.second;

        if(w > b) break;
        ans += w;

        if(right(d) != -1) {
            s.erase({f.at(right(d)), right(d)});
            f.at(right(d)) += w;
            s.insert({f.at(right(d)), right(d)});
        }
        concat(d);
    }

    out(ans);
    return 0;
}