// Author : ysh
// 02/20/2022 Sun 22:51:17.00
// https://codeforces.com/contest/1635/problem/B
// WA
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int tmp;cin>>tmp;
        int ans = 0;
        vector<int>f(tmp);
        for(int &i : f) {
            cin>>i;
        }
        for(int i = 1;i<tmp-1;i++) {
            if(f[i-1]<f[i]&&f[i]>f[i+1]) {
                if(f[i-1]<=f[i+1]) {
                    ans += f[i] - f[i+1];
                    f[i+1] = f[i];
                } else {
                    ans += f[i] - f[i-1];
                    f[i-1] = f[i];
                }
            }
        }
        cout<<ans<<"\n";
        for(int i : f) {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}