// Author : ysh
// 2023/11/17 Fri 16:17:22
// https://judge.tcirc.tw/ShowProblem?problemid=d073
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<int>>f(a,vector<int>(b));
    for(auto &i : f) {
        for(int &j : i) {
            cin>>j;
        }
    }

    int ans = 0;
    for(int i = 0;i<a;i++) {
        vector<int>v(b);
        for(int k = i;k<a;k++) {
            int last = 0;
            int mmin = 0;
            for(int j = 0;j<b;j++) {
                v.at(j) += f.at(k).at(j);
                last = last += v.at(j);
                mmin = min(last,mmin);
                ans = max(ans,last - mmin);
            }
        }
    }
    cout<<ans;
    return 0;
}