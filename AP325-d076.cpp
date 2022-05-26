// Author : ysh
// 04/22/2022 Fri 21:41:23.19
#include<bits/stdc++.h>
using namespace std;
const long long md = (long long) 1e9 + 9;
void mk(int,int);
vector<long long>f(101,-1);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    f[0] = 1;
    mk(n,1);
    cout<<f[n];
    return 0;
}
void mk(int a,int now) {
    int n = now;
    long long tmp = 0;
    for(int i = 0;i<=n - 1;i++) {
        tmp += f[i]*f[now - 1 - i];
        tmp = tmp % md;
    }
    f[now] = tmp;
    if(a > now) mk(a,now + 1);
    return;
}