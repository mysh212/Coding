// Author : ysh
// 09/14/2022 Wed 10:46:41.51
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
    }
    sort(f.begin(),f.end());
    long long ans = 0;
    for(int i = 0;i<b;i++) {
        int tmp;cin>>tmp;
        auto found = lower_bound(f.begin(),f.end(),tmp);
        if(found != f.end()) {
            ans += *found;
        }
    }
    cout<<ans;
    return 0;
}