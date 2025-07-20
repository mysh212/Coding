// Author : ysh
// 2025/07/20 Sun 07:52:47
// https://www.luogu.com.cn/problem/P2921
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;cin>>n;
    vc<int>f(n);
    cin>>f;
    repo(&i, f) i--;
    
    
    vc<int>mk(n, -1), ans(n, -1);
    vc<bool>mark(n);
    function<int(int, int, int)> check = [&] (int last, int x, int d) {
        if(ans.at(x) != -1) return -1;
        if(mark.at(x) && mk.at(x) != -1) return ans.at(x) = d - mk.at(x);
        if(mk.at(x) != -1) return -1;
        mark.at(x) = 1;
        mk.at(x) = d;

        int now = check(x, f.at(x), d + 1);
        mark.at(x) = 0;
        if(ans.at(x) != -1) return -1;
        if(now != -1) return ans.at(x) = now;
    };

    function<int(int)> ck = [&] (int x) {
        if(ans.at(x) != -1) return ans.at(x);

        return ans.at(x) = ck(f.at(x)) + 1;
    };

    re(i, n) if(mk.at(i) == -1) check(-1, i, 0);
    debug(ans);
    re(i, n) if(ans.at(i) == -1) ck(i);
    
    repo(&i, ans) outl(i);
    return 0;
}