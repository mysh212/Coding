// Author : ysh
// 05/08/2023 Mon 20:28:17.33
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
        int n,m;cin>>n>>m;
        vector<bool>f(m);
        int left = 0,right = 0;
        int loss = 0;
        for(int i = 0;i<n;i++) {
            int tmp;cin>>tmp;
            if(tmp == -1) right++;
            else if(tmp == -2) left++;
            else if(!f.at(tmp - 1)) loss--,f.at(tmp - 1) = 1;
            else ;
        }
        debug(left,right,loss,f);
        int ans = max({min(m,left - loss),min(m,right - loss)});
        loss = -loss;
        loss = loss - 1;
        left = left + loss;
        for(int i = 0;i<m;i++) {
            //left -> i
            //right -> m - (i + 1)
            if(!f.at(i)) continue;
            ans = max(ans,min(i,right) + 1 + min(m - (i + 1),left));
            right++;
            left--;
        }
        cout<<ans<<"\n";
    }
    return 0;
}