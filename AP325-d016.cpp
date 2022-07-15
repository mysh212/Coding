// Author : ysh
// 07/15/2022 Fri 10:04:07
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int ans = 0;
    map<int,int>s;
    bitset<26>q;
    for(int i = 0;i<a;i++) {
        q.set(i);
    }
    int r = q.to_ulong();
    //cout<<r<<"\n";
    for(int i = 0;i<b;i++) {
        string tmp;cin>>tmp;
        bitset<26>t;
        for(char j : tmp) {
            t.set((int) j - 'A');
        }
        unsigned long long tt = t.to_ullong();
        // cout<<tt<<" "<<(r xor tt)<<"\n";
        int tp = r xor tt;
        auto found = s.find(tp);
        if(found != s.end()) {
            ans = ans + found->second;
        }
        s[tt]++;
    }
    // int ans = 0;
    cout<<ans;
    return 0;
}
