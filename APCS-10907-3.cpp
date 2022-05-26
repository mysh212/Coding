// Author : ysh
// 05/21/2022 Sat 16:20:49.79
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;cin>>n>>m;
    vector<int>f(n);
    for(int i = 0;i<n;i++) {
        cin>>f[i];
        if(i != 0) f[i] += f[i - 1];
    }
    int now = 0;
    int tmp;
    for(int i = 0;i<m;i++) {
        cin>>tmp;
        int np = (now == 0 ? 0 : f[now - 1]);
        if(np + tmp > f[n - 1]) {
            tmp = (np + tmp) % f[n - 1];
            np = 0;
        }
        int a = lower_bound(f.begin(),f.end(),np + tmp) - f.begin();
        a++;
        now = a;
        now = now % n;
    }
    cout<<now;
    return 0;
}