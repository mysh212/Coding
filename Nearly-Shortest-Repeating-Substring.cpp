// Author : ysh
// 2024/04/01 Mon 20:30:14
// https://codeforces.com/contest/1950/problem/E
#include<bits/stdc++.h>
using namespace std;
#include<slow>
const int R = int(2e5) + 1;
bitset<R>s;
vector<int>prime;
inline void init() {
    for(int i = 2;i<R;i++) {
        if(s.test(i)) continue;
        prime.pb(i);
        for(long long j = 1LL * i * i;j<R;j = j + i) {
            s.set(j);
        }
    }
    return;
}
vector<int> check(int x) {
    vc<int>ans;
    repo(&i,prime) {
        if(i * i > x) break;
        while(x % i == 0) x = x / i,ans.pb(i);
    }
    if(x != 1) ans.pb(x);
    sort(all(ans));
    ans.resize(unique(all(ans)) - ans.begin());
    return ans;
}
vector<int> ck(int x,vector<int>pre) {
    vc<int>ans;
    repo(&i,pre) {
        while(x % i == 0) x = x / i,ans.pb(i);
    }
    return ans;
}
vector<pair<int,int>> ct(vector<int>pre) {
    vc<pair<int,int>>ans;
    repo(&i,pre) {
        if(ans.empty()) ans.push_back(make_pair(i,1));
        else if(ans.back().first == i) ans.back().second++;
        else ans.push_back(make_pair(i,1));
    }
    return ans;
}
inline bool fold(string a,int x,int m) {
    bool c = 0;
    int now = x;
    while(now != m) {
        if(a.at(now) != a.at(now - x)) {
            if(!c) c = 1;
            else return false;
            a.at(now) = a.at(now - x);
        }
        now++;
    }
    return true;
}
inline bool fold(string a,int x) {
    if(fold(a,x,a.size())) return true;
    reverse(all(a));
    if(fold(a,x,a.size())) return true;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        string a;cin>>a;

        auto f = ct(ck(n,check(n)));
        int m = f.size();
        vector<int>ans;

        function<void(int,int)> walk = [&] (int x,int now) {
            if(x == m) return ans.pb(now),void();
            int tmp = 1;
            int r = f.at(x).first;
            re(i,0,f.at(x).second + 1) {
                walk(x + 1,now * tmp);
                tmp = tmp * r;
            }
            return;
        };

        debug(f);
        walk(0,1);

        sort(all(ans));
        debug(ans);

        repo(&i,ans) if(fold(a,i)) {
            outl(i);
            goto yes;
        }

        yes:
        continue;

        no:
        outl("NO");
    }
    return 0;
}