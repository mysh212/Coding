// Author : ysh
// 2023/07/09 Sun 22:30:08
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n) {
        int f[n];
        for(int i = 0;i<n;i++) {
            cin>>f[i];
        }

        for(int i = 0;i<n;i++) {
            for(int j = i + 1;j<n;j++) {
                if(f[i] > f[j]) swap(f[i],f[j]);
            }
        }

        for(int i = 0;i<n;i++) {
            cout<<f[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}