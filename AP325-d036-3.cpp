// Author : ysh
// 09/09/2022 Fri 14:26:04.52
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    gp_hash_table<int,int>m;
    vector<int>f(b);
    int t = 0;
    for(int &i : f) {
        cin>>i;
        if(m.find(i) == m.end()) m.insert({i,t++});
        i = m.find(i)->second;
    }
    vector<bool>mark(b);
    int l,r;l = r = 0;
    int s = 1;
    mark.at(f.at(0)) = 1;
    int ans = 0;
    while(r < b - 1) {
        r++;
        if(mark.at(f.at(r))) {
            while(mark.at(f.at(r)) && l < r) {
                mark.at(f.at(l)) = 0;
                s--;
                l++;
            }
            mark.at(f.at(r)) = 1;
            s++;
            if(s == t) {
                ans++;
            }
            continue;
        }
        mark.at(f.at(r)) = 1;
        s++;
        
        if(s == t) {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}