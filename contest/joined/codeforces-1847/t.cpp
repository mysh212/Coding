// Author : ysh
// 2023/07/31 Mon 20:01:52
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c;
vector<int>f;
bool check(int x) {
    auto now = f.begin();
    int r = x;
    int ans = 0;
    for(int i = 0;i<c;i++) {
        if(r == -1) {
            r = x;
            now = f.begin();
        }
        if(now != f.end()) {
            ans = ans + *now;
            now = next(now);
        }
        r--;
    }
    cerr<<x<<" "<<ans<<"\n";
    return ans >= b;
}
int ck(int l,int r) {
    if(l + 1 == r) return l;
    int mid = (l + r) >> 1;
    if(check(mid)) return ck(mid,r);
    return ck(l,mid);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        cin>>a>>b>>c;
        f = vector<int>(a);
        for(int &i : f) {
            cin>>i;
        }
        sort(f.rbegin(),f.rend());

        // int last = 0;
        // for(int &i : f) {
        //     i = last += i;
        // }

        int tmp = ck(0,c);

        if(f.front() * c < b) cout<<"Impossible\n";
        else if(tmp == c - 1) cout<<"Infinity\n";
        else cout<<tmp<<"\n";
    }
    return 0;
}