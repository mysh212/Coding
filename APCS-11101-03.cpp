// Author : ysh
// 01/10/2022 Mon 11:19:39.61
#include<bits/stdc++.h>
using namespace std;
int check(string a,int b) {
    if(b & 1 == 1) return 0;
    b = b>>1;
    for(int i = 0;i<b;i++) {
        // printf("[%d,%d]",i,b+i);
        if(a.at(i) != a.at(b + i)) return 0;
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<string>f(n);
    int b[n] = {};
    for(int i = 0;i<n;i++) {
        cin>>f[i];
        b[i] = f[i].length();
        // cout<<b[i]<<"\n";
    }
    int ans = 0;
    for(int i = 0;i<n;i++) {
        for(int j = i + 1;j<n;j++) {
            if(!(b[i] == b[j])) {
                if(b[i]>b[j]) {
                    if(f[i].find(f[j]) != -1) {
                        ans+=check(f[i]+f[j],b[i]+b[j]);
                    }
                } else {
                    if(f[j].find(f[i]) != -1) {
                        ans+=check(f[i]+f[j],b[i]+b[j]);
                    }
                }
            }
            // cout<<f[i]+f[j]<<"\n";
        }
    }
    cout<<ans;
    return 0;
}