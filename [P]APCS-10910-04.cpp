// Author : ysh
// 03/05/2022 Sat 13:07:33.27
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    long long ans = 2;
    bool on = 0;
    long long tmp;
    for(int i = 0;i<(n<<1);i++) {
        cin>>tmp;
        if(tmp == n) {
            if(on == 0) {
                on = 1;
                continue;
            } else {
                break;
            }
        }
        if(on&&tmp < n) ans++;
    }
    cout<<ans;
    return 0;
}