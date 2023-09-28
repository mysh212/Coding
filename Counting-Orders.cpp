// Author : ysh
// 06/19/2023 Mon  7:15:30.64
// https://codeforces.com/problemset/problem/1827/A
#include<bits/stdc++.h>
using namespace std;
const int R = (int) 1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>f(n),g(n);
        for(int &i : f) cin>>i;
        for(int &i : g) cin>>i;

        sort(f.rbegin(),f.rend());
        sort(g.rbegin(),g.rend());

        long long ans = 1;
        auto found = f.begin();
        for(int i = 0;i<n;i++) {
            while(*found > g.at(i) && found != f.end()) found = next(found);
            if(found == f.begin()) {
                ans = 0;
                break;
            }
            ans = ans * ((found - f.begin()) - i);
            ans = ans % R;
        }
        cout<<ans<<"\n";
    }
    return 0;
}