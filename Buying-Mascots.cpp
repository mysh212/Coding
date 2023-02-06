// Author : ysh
// 02/06/2023 Mon 10:28:34.20
// https://codeforces.com/gym/425267
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(b + 1,-1),g(b + 1);
    vector<pair<int,int>>v(a);
    for(auto &i : v) cin>>i.first;
    for(auto &i : v) cin>>i.second;
    
    f.at(0) = 0;
    for(int i = 0;i<a;i++) {
        for(int j = 0;j<=b;j++) {
            g.at(j) = f.at(j);
        }
        int &now = v.at(i).first;
        for(int j = b;j>=0;j--) {
            if(f.at(j) == -1) continue;
            if(j + now <= b) f.at(j + now) = max(f.at(j),f.at(j + now));
            else f.back() = max(f.back(),f.at(j));
        }
        now = v.at(i).second;
        for(int j = 0;j<=b;j++) {
            if(g.at(j) == -1) continue;
            if(j - now >= 0) g.at(j - now) = max(g.at(j - now),g.at(j) + now);
        }
        for(int j = 0;j<=b;j++) {
            f.at(j) = max(f.at(j),g.at(j));
            // cerr<<f.at(j)<<" ";
        }
        // cerr<<"\n";
    }

    cout<<*max_element(f.begin(),f.end());
    return 0;
}