// Author : ysh
// 02/06/2023 Mon 11:17:51.37
// https://codeforces.com/gym/425267
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>f(n);
        vector<int>v(n);
        int t = 0;
        for(int &i : f) cin>>i,v.at(i - 1) = t++,i--;

        vector<pair<int,int>>ans;
        for(int i = 0;i<n;i++) {
            if(v.at(i) == i) continue;
            ans.emplace_back(v.at(i),i);
            v.at(f.at(i)) = v.at(i);
            swap(f.at(i),f.at(v.at(i)));
            // for(int &i : f) cerr<<i<<" ";
            // cerr<<"\n";
        }

        cout<<ans.size()<<"\n";
        for(auto &i : ans) {
            cout<<min(i.first,i.second) + 1<<" "<<max(i.first,i.second) + 1<<"\n";
        }
    }
    return 0;
}