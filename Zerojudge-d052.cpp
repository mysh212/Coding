// Author : ysh
// 06/23/2022 Thu 11:27:10.65
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;cin>>m;
    while(m--) {
        int n;cin>>n;
        if(n == 0) {
            cout<<"0\n";
            continue;
        }
        vector<int>g(n);
        for(int &i : g) {
            cin>>i;
        }
        reverse(g.begin(),g.end());
        vector<int>f;
        for(int k = 1;k<=2;k++) {
            for(int i : g) {
                auto found = lower_bound(f.begin(),f.end(),i);
                if(found == f.end()) {
                    f.push_back(i);
                    continue;
                }
                *found = i;
            }
            reverse(g.begin(),g.end());
        }
        cout<<f.size()<<"\n";
    }
    return 0;
}