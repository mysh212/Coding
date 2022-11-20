// Author : ysh
// 11/20/2022 Sun 23:06:52.73
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a;cin>>a;
        vector<int>f(a);
        set<int>s;
        for(int &i : f) {
            cin>>i;
            s.insert(i);
        }
        if(s.size() == 2) cout<<(a >> 1) + 1<<"\n";
        else cout<<a<<"\n";
    }
    return 0;
}