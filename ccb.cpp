// Author : ysh
// 11/22/2022 Tue 10:12:46.19
// https://codeforces.com/contest/1760/problem/F
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) 
#define printf(...) 
#endif
#define int long long
int check(vector<int> &f,int n,int d,int k) {
    k++;
    // debug(n,d,k);
    int ans = 0;
    for(int i = 0;i < d;i++) {
        int r = i % k;
        if(r >= n) continue;
        ans += f.at(r);
        // debug("ans += f.at(r);",r,f.at(r));
    }
    debug(k,ans);
    return ans;
}
int ck(vector<int>&f,int n,int d,int s,int l,int r) {
    if(l + 1 == r && l == 0 && check(f,n,d,0) < s) return -1;
    if(l + 1 == r) return l;
    int mid = (l + r) >> 1;
    int now = check(f,n,d,mid);
    debug(l,r,mid,now);
    debug(now,s);
    if(now < s) return ck(f,n,d,s,l,mid);
    else return ck(f,n,d,s,mid,r);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n,s,d;cin>>n>>s>>d;
        vector<int>f(n);
        for(int &i : f) {
            cin>>i;
        }
        sort(f.rbegin(),f.rend());
        int tmp = ck(f,n,d,s,0,d + 2);
        if(tmp == -1) cout<<"Impossible\n";
        else if(tmp == d + 1) cout<<"Infinity\n";
        else cout<<tmp<<"\n";
    }
    return 0;
}