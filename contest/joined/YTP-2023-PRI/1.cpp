// Author : ysh
// 2023/07/28 Fri 12:58:45
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

#define int long long 

void solve1(){
    int a,b;cin>>a>>b;
    vector<int>f(b);
    for(int &i : f) cin>>i;
    f.push_back(a);
    sort(f.begin(),f.end());

    int ans,last;ans = 0;last = 0;
    for(int &i : f) {
        if(last == i) continue;
        int d = max(0LL,((i - last) / 15));
        if((i - last) % 15 == 0) d--;
        debug(last,i,d);
        ans += d;
        last = i;
    }
    cout<<ans;
}

void solve(){
    int l, n;
    cin >> l >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(begin(a), end(a));
    int now = 1;
    vector<int> v;
    debug(a);
    for(int i = 0; i < n; ++i){
        if(a[i] - 14 > now){
            v.push_back(a[i] - 14 - now);
            debug(now);
        }
        now = a[i] + 15;
        cerr << "now:" << now << endl;
    }
    if(now < l){
        v.push_back(l - now + 1);
    }
    int ans = 0;
    for(auto x:v){
        ans += x / 29;
    }
    debug(v);
    cout << ans;
}

using lint = long long;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    lint L;
    int n;
    cin >> L >> n;

    vector<array<lint, 2>> s(n);
    for (int i = 0; i < n; i++) {
        lint x;
        cin >> x;
        s[i] = {max(1ll, x - 14), min(L, x + 14)};
    }

    sort(s.begin(), s.end());

    vector<array<lint, 2>> ns;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            ns.push_back(s[0]);
            continue;
        }
        if (ns.back()[1] >= s[i][0]) {
            ns.back()[1] = max(ns.back()[1], s[i][1]);
        } else {
            ns.push_back(s[i]);
        }
    }

    lint ans = 0;
    ans += (ns[0][0] - 1 + 14) / 15;
    ans += (L - ns.back()[1] + 14) / 15;
    for (int i = 1; i < ns.size(); i++) {
        lint diff = ns[i][0] - ns[i - 1][1] - 1;
        ans += (diff + 14) / 15;
    }
    cout << ans << '\n';

    return 0;
}