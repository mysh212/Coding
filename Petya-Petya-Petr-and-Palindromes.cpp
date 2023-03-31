// Author : ysh
// 03/30/2023 Thu 13:47:58.10
// https://codeforces.com/contest/1808/problem/D
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
    }
    b = b >> 1;

    int ans = (a - (b << 1)) * b;
    vector<map<int,deque<int>>>mark(2);
    for(int i = 0;i<a;i++) {
        if(mark.at(i & 1).find(f.at(i)) == mark.at(i & 1).end()) mark.at(i & 1).insert({f.at(i),deque<int>()});
        auto &now = mark.at(i & 1).find(f.at(i))->second;
        while(!now.empty() && now.front() < i - (b << 1)) now.pop_front();
        auto found = lower_bound(now.begin(),now.end(),(b << 1) - i);
        auto ffound = lower_bound(now.rbegin(),now.rend(),(a << 1) - i - ((b + 1) << 1),greater<int>());
        int left = found - now.begin();
        int right = now.rend() - ffound - 1;
        ans = ans - (right - left + 1);
        now.push_back(i);
    }
    cout<<ans<<"\n";
    return 0;
}