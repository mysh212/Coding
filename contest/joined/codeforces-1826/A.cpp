// Author : ysh
// 05/05/2023 Fri 22:47:05.44
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>f(n);
        for(int &i : f) {
            cin>>i;
        }
        sort(f.begin(),f.end());
        bool c = 0;
        if(f.back() == 0) {
            cout<<0<<"\n";
            continue;
        }
        for(int i = 0;i<n;i++) {
            while(i != n - 1 && f.at(i + 1) == f.at(i)) i++;
            if(i == n - 1) break;
            if(f.at(i) <= n - i - 1 && f.at(i + 1) > n - i - 1) {
                cout<<n - i - 1<<"\n";
                c = 1;
                break;
            }
        }
        if(!c) cout<<"-1\n";
    }
    return 0;
}