// Author : ysh
// 09/02/2022 Fri 18:47:39.86
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    c = c / b;
    vector<int>f(a);
    for(int i = 0;i<a;i++) {
        cin>>f[i];
        f[i] = f[i] / b;
    }
    long long ans = 0;
    for(int i = 0;i<a;i++) {
        if(i == 0) continue;
        if(abs(f[i - 1] - f[i]) > c) {
            if(f[i - 1] > f[i]) {
                ans = ans + f[i - 1] - (f[i] + c);
                f[i - 1] = f[i] + c;
            } else {
                ans = ans + f[i] - (f[i - 1] + c);
                f[i] = f[i - 1] + c;
            }
            i = i - 2;
            continue;
        }
    }
    cout<<ans;
    return 0;
}