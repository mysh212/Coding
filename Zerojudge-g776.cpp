// Author : ysh
// 03/22/2022 Tue 13:02:35.53
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    int m,a,b;cin>>m;
    while(m--) {
        bitset<400000>s;
        s.reset();
        cin>>a>>b;
        for(int i = a - 1;i<=b - 1;i++) {
            s.set(f[i]);
        }
        cout<<s.count()<<"\n";
    }
    return 0;
}