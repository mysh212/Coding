// Author : ysh
// 2026/11/07 Sat 22:01:26
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;cin>>a>>b;
    vc<pair<int, int>>f(b);
    cin>>f;

    repo(&i, f) i.first--, i.second--;

    vc<int>ct(a);
    repo(&i, f) ct.at(i.first)++;

    set<pair<int, int>>s;
    re(i, a) s.emplace(-ct.at(i), i);

    vc<map<int, int>>mark(a);
    repo(&i, f) mark.at(i.first)[i.second]++;

    debug(s);

    re(i, a) {
        for(auto &[l, r] : mark.at(i)) {
            s.erase({-ct.at(l), l});
            ct.at(l) += r;
            s.insert({-ct.at(l), l});
        }
        auto found = s.begin();
        assert(found != s.end());

        if(found -> second == i) found = next(found);
        assert(found != s.end());

        outl(found -> second + 1);

        for(auto &[l, r] : mark.at(i)) {
            s.erase({-ct.at(l), l});
            ct.at(l) -= r;
            s.insert({-ct.at(l), l});
        }
    }

    return 0;
}