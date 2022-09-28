// Author : ysh
// 09/28/2022 Wed 11:08:56.35
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    multiset<int>s;
    int n;cin>>n;
    while(n--) {
        int tmp;cin>>tmp;
        s.insert(tmp);
    }
    cin>>n;
    while(n--) {
        int tmp;cin>>tmp;
        s.erase(s.lower_bound(tmp));
        for(int i : s) cout<<i;
    }
    return 0;
}