// Author : ysh
// 2025/04/12 Sat 22:40:16
// https://vjudge.net/problem/UVA-10791
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

const int R = (1 << (32 >> 1));
bitset<R>s;
vector<int>prime;
void init() {
    for(int i = 2;i<R;i++) {
        // s.set(i);
        if(!s.test(i)) prime.push_back(i);
        else continue;
        for(long long j = 1LL * i * i;j<R;j = j + i) {
            s.set(j);
        }
    }
    return;
}
inline bool check(int x) {
    if(x < R) return !s.test(x);
    for(int &i : prime) if(x % i == 0) return 0;
    return 1;
}
inline vector<pair<int,int>> ck(int x) {
    if(x == 1) return {{1, 1}};
    vector<pair<int,int>>ans;
    for(int &i : prime) {
        int now = 0;
        while(x % i == 0) x = x / i, now++;
        if(now != 0) ans.push_back({i, now});
    }
    if(x != 1) ans.push_back({x, 1});
    return ans;
}
inline vector<int> ckz(int x) {
    if(x == 1) return {{1, 1}};
    vector<int>ans;
    for(int &i : prime) {
        int now = 1;
        while(x % i == 0) x = x / i, now = now * i;
        if(now != 1) ans.push_back(now);
    }
    if(x != 1) ans.push_back(x);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    int n;
    int t = 0;
    while(cin>>n && n != 0) {
        auto f = ckz(n);
        debug(f);
        cout<<"Case "<<++t<<": ";
        cout<<accumulate(f.begin(), f.end(), (f.size() == 1 ? 1LL : 0LL))<<"\n";
    }
    return 0;
}