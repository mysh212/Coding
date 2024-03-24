// Author : ysh
// 2024/02/01 Thu 17:04:05
// https://codeforces.com/contest/1925/problem/B
#include<bits/stdc++.h>
using namespace std;
#include<slow>
constexpr int R = 1e4;
vector<int>prime;
bitset<R + 1>s;
void init() {
    re(i,2,R + 1) {
        if(!s.test(i)) prime.pb(i);
        re(j,i * i,R + 1) {
            s.set(i);
        }
    }
    return;
}
vector<pair<int,int>> check(int x) {
    vc<pair<int,int>>ans;
    repo(i,prime) {
        int now = 0;
        while(x % i == 0) now++,x = x / i;
        if(now != 0) ans.push_back({i,now});
    }
    if(x != 1) ans.push_back({x,1});
    if(ans.empty()) return {{1,1}};
    return ans;
}
vector<int>ans;
void ck(vector<pair<int,int>>v,int x,int now) {
    if(x == 0) ans.clear();
    if(x == v.size()) return ans.pb(now),void();
    int r = 1;
    re(v.at(x).second + 1) ck(v,x + 1,now * r),r = r * v.at(x).first;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    int n;cin>>n;
    re(n) {
        int a,b;cin>>a>>b;
        ck(check(a),0,1);
        sort(all(ans));
        debug(ans);
        auto found = lower_bound(all(ans),b);
        outl(a / (*found));
    }
    return 0;
}