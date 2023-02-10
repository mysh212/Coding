// Author : ysh
// 02/03/2023 Fri 23:25:11.24
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        vector<int>f(a);
        int t = 0;
        for(int &i : f) cin>>i,i = i + ++t;
        sort(f.begin(),f.end());
        int ans = 0;
        for(int &i : f) {
            if(i > b) break;
            b = b - i;
            ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}