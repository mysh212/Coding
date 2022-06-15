// Author : ysh
// 06/14/2022 Tue 22:40:14.14
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a;cin>>a;
        vector<int>f(a);
        for(int &i : f) {
            cin>>i;
        }
        sort(f.begin(),f.end());
        auto j = unique(f.begin(),f.end());
        if(f.size() - (j - f.begin()) & 1) cout<<(j - f.begin()) - 1<<"\n";
        else cout<<j - f.begin()<<"\n";
    }
    return 0;
}