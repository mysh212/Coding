// Author : ysh
// 04/25/2023 Tue  9:49:45.41
#include<bits/stdc++.h>
using namespace std;
int offline(vector<int>&f) {
    vector<int>v(f);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end()) - v.begin());
    for(int &i : f) {
        i = lower_bound(v.begin(),v.end(),i) - v.begin();
    }
    return v.size();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
    }
    int r = offline(f);
    
    vector<int>now(r);
    int ans = 0;
    int l;l = 0;
    int sig = 0;
    assert(b != 0);
    for(int i = 0;i<a;i++) {
        now.at(f.at(i))++;
        if(now.at(f.at(i)) == 1) sig = sig + 1;
        while(sig > b) {
            now.at(f.at(l))--;
            if(now.at(f.at(l)) == 0) sig = sig - 1;
            l++;
        }
        ans = max(ans,(i - l) + 1);
    }
    cout<<ans;
    return 0;
}