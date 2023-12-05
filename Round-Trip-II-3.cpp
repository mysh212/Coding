// Author : ysh
// 2023/11/30 Thu 00:15:31
// https://cses.fi/problemset/task/1678
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vc<vc<int>>f(a);
    re(b) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).pb(b);
    }

    vc<bool>mark(a),mk(a);
    vc<int>now;
    function<void(int)> check = [&] (int x) {
        if(mk.at(x)) {
            vc<int>tmp;
            while(!now.empty() && now.back() != x) tmp.pb(now.back()),now.pop_back();
            outl(tmp.size() + 2);
            outs(x + 1);
            reverse(all(tmp));
            repo(&i,tmp) outs(i + 1);
            out(x + 1);
            exit(0);
        }
        if(mark.at(x)) return;
        mark.at(x) = mk.at(x) = 1;
        now.pb(x);
        repo(&i,f.at(x)) {
            check(i);
        }
        now.pop_back();
        mk.at(x) = 0;
        return ;
    };

    re(i,a) {
        if(!mark.at(i)) check(i);
    }

    out("IMPOSSIBLE");
    return 0;
}