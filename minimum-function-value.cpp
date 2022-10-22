// Author : ysh
// 10/15/2022 Sat 19:14:52.98
// https://www.luogu.com.cn/problem/P2085
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
inline int check(array<int,3> &a,int r) {
    return a[0] * r * r + a[1] * r + a[2];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    __gnu_pbds::priority_queue<pair<int,int>,greater<pair<int,int>>,pairing_heap_tag>q;
    int a,b;cin>>a>>b;
    vector<array<int,3>>f(a);
    vector<int>v(a,1);
    for(int i = 0;i<a;i++) {
        cin>>f[i][0]>>f[i][1]>>f[i][2];
        q.push({check(f[i],1),i});
    }
    while(b--) {
        auto now = q.top();q.pop();
        cout<<now.first<<" ";
        v.at(now.second)++;
        q.push({check(f.at(now.second),v.at(now.second)),now.second});
    }
    return 0;
}