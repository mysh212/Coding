// Author : ysh
// 04/16/2022 Sat 22:32:19.02
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    for(int i = 1;i<=n;i++) {
        printf("Case #%d: ",i);
        int a;cin>>a;
        int c[a] = {};
        for(int j = 0;j<a;j++) {
            cin>>c[j];
        }
        int b[100005] = {};
        int ans = 0;
        for(int j = 0;j<a;j++) {
            for(int k = ans;k<c[j];k++) {
                b[k]++;
            }
            for(int i = ans;i<100005;i++) {
                if(b[i] < i + 1) {
                    ans = i;
                    break;
                }
            }
            printf("%d ",ans);
        }
        printf("\n");
    }
    return 0;
}