// Author : ysh
// 12/07/2022 Wed  9:10:36.25
#include<bits/stdc++.h>
using namespace std;
#define N 500000
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // constexpr int R = (int) sqrt(500000);
    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) cin>>i;
    int r = 710;
    vector<int>g((n / r) + 1);
    for(int i = 0;i<n;i++) {
        g.at(i / r) = max(g.at(i / r),f.at(i));
    }
    int m;cin>>m;
    while(m--) {
        int a,b;cin>>a>>b;
        if(a > b) swap(a,b);
        a--;b--;
        if(a / r == b / r) {
            int ans = 0;
            for(int i = a;i<=b;i++) {
                ans = max(ans,f.at(i));
            }
            cout<<ans<<"\n";
            continue;
        }
        int ans = 0;
        for(int i = (a / r) + 1,len = b / r;i<len;i++) {
            ans = max(ans,g.at(i));
        }
        for(int i = a,len = ((a / r) + 1) * r;i<len;i++) {
            ans = max(ans,f.at(i));
        }
        for(int i = (b / r) * r;i<=b;i++) {
            ans = max(ans,f.at(i));
        }
        cout<<ans<<"\n";
    }
}