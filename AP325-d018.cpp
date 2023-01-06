// Author : ysh
// 07/15/2022 Fri 15:15:25
#include<bits/stdc++.h>
using namespace std;
#define int long long
int k = 0;
vector<int>f;
int b;
int gcd(int x,int y,int &a,int &b) {
    if(y == 0) {
        a = 0;b = 1;
        return x;
    }
    int ans = gcd(y,x % y,a,b);
    int tmp = a;
    a = b - (x / y) * a;
    b = tmp;
    return ans;
}
int check(int x) {
    int a,b;a = 0,b = 1;
    gcd(::b,x,a,b);
    return (a % ::b + ::b) % ::b;
}
map<int,int> check(int l,int r) {
    if(l == r) {
        return {map<int,int>({{1,f[l]}})};
    }
    if(l > r) return vector<int>({1});
    int mid = (l + r) >> 1;
    map<int,int>ll(check(l,mid));
    map<int,int>rr(check(mid + 1,r));
    map<int,int>o;
    for(int i : ll) {
        for(int j : rr) {
            o.push_back(i * j % k);
        }
    }
    return o;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;cin>>a>>b;
    for(int i = 0;i<a;i++) {
        int tmp;cin>>tmp;
        tmp = tmp % b;
        f.push_back(tmp);
    }
    k = b;
    int ans = 0;
    vector<int>ll(check(0,a >> 1));
    vector<int>rr(check((a >> 1) + 1,a - 1));
    for(int i : ll) {
        for(int j : rr) {
            if(i * j % b == 1) ans++;
        }
    }
    cout<<ans - 1;
    return 0;
}
