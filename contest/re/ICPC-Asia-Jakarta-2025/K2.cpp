// Author : ysh
// 2026/10/30 Fri 12:27:48
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k, q;cin>>n>>m>>k>>q;
    vc<set<pair<int, int>>>f(n), g(n);
    re(m) {
        int a, b, c;cin>>a>>b>>c;
        a--;b--;
        g.at(a).insert({b, c});
        // g.at(b).insert({a, c});
    }

    int ans = 1;
    vc<bool>mark(n);
    // queue<int>pre;
    mark.at(0) = 1;
    re(q) {
        short op;cin>>op;
        switch(op) {
            case 1: {
                int a, b, c;cin>>a>>b>>c;
                a--;b--;
                g.at(a).insert({b, c});
                // g.at(b).insert({a, c});
                continue;
            }
            case 2: {
                int a, b, c; cin>>a>>b>>c;
                debug(g);
                a--;b--;
                #define f g
                {
                    auto found = f.at(a).find({b, c});
                    if(found == f.at(a).end() || *found != make_pair(b, c)) continue;
                    f.at(a).erase(found);
                }
                // {
                //     auto found = f.at(b).find({a, c});
                //     if(found == f.at(b).end() || *found != make_pair(a, c)) continue;
                //     f.at(b).erase(found);
                // }
                #undef f
                debug(g);
                continue;
            }
            default: {
                #undef nl

                int k;cin>>k;
                function<void(int, int)> check = [&] (int last, int x) {
                    if(!mark.at(x)) ans++;
                    mark.at(x) = 1;

                    vc<tuple<int, int, int>>er;
                    for(auto &[nd, nl] : g.at(x)) {
                        if(nl != k) continue;

                        // x <-> nd -- k / nl
                        f.at(x).insert({nd, nl});
                        // f.at(nd).insert({x, nl});

                        er.emplace_back(x, nd, nl);
                    }

                    for(auto &[l, r, k] : er) {
                        g.at(l).erase({r, k});
                        // g.at(r).erase({l, k});

                        check(x, r);
                    }
                };

                re(i, n) if(mark.at(i) && !g.at(i).empty()) check(-1, i);
                debug(mark);
                outl(ans);
            }
        }
    }

    return 0;
}