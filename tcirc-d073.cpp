// Author : ysh
// 2023/11/17 Fri 16:04:33
// https://judge.tcirc.tw/ShowProblem?problemid=d073
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vc<vc<int>>f(a,vc<int>(b));
    cin>>f;
    
    int ans = 0;
    re(i,a) {
        vc<int>v(b);
        re(k,i,a) {
            int last = 0;
            int mmin = 0;
            re(j,b) {
                v.at(j) += f.at(k).at(j);
                last = last += v.at(j);
                mmin = min(last,mmin);
                ans = max(ans,last - mmin);
                // outs(last);
            }
            // out(ans);
            // outl("");
        }
    }
    out(ans);
    return 0;
}