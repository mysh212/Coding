// Author : ysh
// 08/25/2022 Thu 21:45:19.09
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n) {
        vector<int>f;
        for(int i = 0;i<n;i++) {
            int tmp;cin>>tmp;
            auto found = lower_bound(f.rbegin(),f.rend(),tmp);
            if(found == f.rbegin()) {
                f.push_back(tmp);
            } else {
                *prev(found) = tmp;
            }
        }
        cout<<f.size()<<"\n";
    }
    return 0;
}