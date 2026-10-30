// Author : ysh
// 2026/10/30 Fri 12:56:24
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k, q;cin>>n>>m>>k>>q;
    vc<vc<set<int>>>f(k, vc<set<int>>(n));
    vc<set<int>> pre(k);
    re(m) {
        int a, b, c;cin>>a>>b>>c;
        a--;b--;c--;
        f.at(c).at(a).insert(b);
        pre.at(c).insert(a);
    }

    vc<bool>mark(n);
    int ans = 1;
    mark.at(0) = 1;

    re(q) {
        short op;cin>>op;
        if(op == 1) {
            int a, b, c;cin>>a>>b>>c;
            a--;b--;c--;
            if(!(mark.at(b))) {
                f.at(c).at(a).insert(b);
                pre.at(c).insert(a);
            }

            continue;
        }
        if(op == 2) {
            int a, b, c;cin>>a>>b>>c;
            a--;b--;c--;
            f.at(c).at(a).erase(b);

            continue;
        }
        {
            int k;cin>>k;
            k--;

            queue<int>q;
            // re(i, n) if(mark.at(i)) q.push(i);
            vc<int>mk;
            repo(&i, pre.at(k)) if(mark.at(i)) q.push(i), mk.push_back(i);
            repo(&i, mk) pre.at(k).erase(i);

            while(!q.empty()) {
                int now = q.front(); q.pop();
                debug(now);

                if(!mark.at(now)) ans++;
                mark.at(now) = 1;
                
                if(f.at(k).at(now).empty()) continue;

                for(int i : f.at(k).at(now)) {
                    q.push(i);
                }

                f.at(k).at(now).clear();
            }

            outl(ans);
        }
    }
    return 0;
}