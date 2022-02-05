#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m,n;
    cin>>m>>n;
    int a[m+2][n+2] = {},k[n+2] = {},r[n+2] = {};
    for(int i = 1;i<=m;i++) {
        for(int j = 1;j<=n;j++) {
            cin>>k[j];
            if(j == 1) {
                a[i][j] = a[i - 1][j] + k[j];
            } else {
                a[i][j] = max(a[i][j - 1],a[i - 1][j]) + k[j];
            }
        }
        for(int j = n;j>=1;j--) {
            if(j == n) {
                r[j] = a[i - 1][j] + k[j];
            } else {
                r[j] = max(r[j + 1],a[i - 1][j]) + k[j];
            }
            a[i][j] = max(a[i][j],r[j]);
        }
    }
    int ans = a[m][1];
    for(int i = 1;i<=n;i++) {
        ans = max(ans,a[m][i]);
    }
    cout<<ans;
}
