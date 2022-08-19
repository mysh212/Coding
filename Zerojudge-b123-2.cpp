// Author : ysh
// 08/19/2022 Fri 19:39:27.37
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    while(cin>>a>>b) {
        bool c[a][b] = {};
        int l[b] = {};
        int ans = 0;
        for(int i = 0;i<a;i++) {
            for(int j = 0;j<b;j++) {
                cin>>c[i][j];
                l[j] = (c[i][j] == 0 ? 0 : l[j] + 1);
            }
            for(int j = 0;j<b;j++) {
                int tmp = l[j];
                for(int k = j + 1;k<b;k++) {
                    if(tmp == 0) break;
                    ans = max(ans,(k - j + 1 - 1) * tmp);
                    tmp = min(tmp,l[k]);
                }
                ans = max(ans,(b - 1 - j + 1) * tmp);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}