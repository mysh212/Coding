// Author : ysh
// 02/23/2022 Wed  9:43:33.86
// https://judge.tcirc.tw/ShowProblem?problemid=d020
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>c(a+1);
    vector<long long>d(a+1);
    set<long long>m({0});
    long long ans = 0;
    for(int i = 1;i<=a;i++) {
        cin>>c[i];
        d[i] = d[i-1] + c[i];
        long long find = d[i] - b;
        auto found = m.lower_bound(find);
        if(found != m.end()) ans = max(ans,d[i] - *found);
        m.insert(d[i]);
        if(ans == b) break;
    }
    cout<<ans;
    return 0;
}