// Author : ysh
// 04/02/2022 Sat 13:35:44.58
// TLE
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>c;
    for(int i = 1;i<=a;i++) {
        c.push_back(i);
    }
    set<int>f(c.begin(),c.end());
    string tmp;int n;
    while(b--) {
        cin>>tmp>>n;
        if(tmp == "-") {
            f.erase(n);
            continue;
        }
        if(tmp == "?") {
            cout<<(f.lower_bound(n) == f.end() ? -1 : *f.lower_bound(n))<<"\n";
        }
    }
    return 0;
}