// Author : ysh
// 05/06/2023 Sat 22:47:51.88
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        int a,b,r;a = b = r = INT_MAX;
        for(int i = 0;i<n;i++) {
            int tmp;cin>>tmp;
            string aa;cin>>aa;
            if(aa == "11") r = min(tmp,r);
            if(aa.at(0) == '1') a = min(tmp,a);
            if(aa.at(1) == '1') b = min(tmp,b);
        // debug(a,b,r);
        }
        if((a == INT_MAX || b == INT_MAX)) cout<<"-1\n";
        else cout<<min(a + b,r)<<"\n";
    }
    return 0;
}