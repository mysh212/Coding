// Author : ysh
// 2023/09/21 Thu 22:52:28
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        string aa;cin>>aa;
        vector<bool>f(a);
        for(int i = 0;i<a;i++) {
            f.at(i) = (aa.at(i) == 'B');
        }

        int ans = 0;
        int now = 0;
        for(int i = 0;i<a;i++) {
            now--;
            if(f.at(i)) {
                if(now <= 0) {
                    now = b;
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}