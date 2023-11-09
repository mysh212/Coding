// Author : ysh
// 2023/11/03 Fri 23:10:45
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>f(n << 1);
        for(int &i : f) cin>>i;
        sort(f.begin(),f.end());
        cout<<(f.at(n - 1) - f.at(0)) + (f.at((n << 1) - 1) - f.at(n));
        cout<<"\n";
        for(int i = 0;i<n;i++) {
            cout<<f.at(i)<<" "<<f.at(n + i)<<"\n";
        }
    }
    return 0;
}