// Author : ysh
// 2024/02/22 Thu 15:16:21
// https://codeforces.com/contest/1926/problem/D
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>f(n);
        for(int &i : f) cin>>i;

        multiset<int>s(f.begin(),f.end());
        int ans = 0;
        while(s.size() != 0) {
            int now = *s.begin();
            s.erase(s.begin());
            auto found = s.lower_bound((~(now)) & INT_MAX);
            if(found != s.end() && *found == ((~(now)) & INT_MAX)) s.erase(found);
            ans++;
        }

        cout<<ans<<" ";
    }
    return 0;
}