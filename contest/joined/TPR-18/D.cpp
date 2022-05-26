// Author : ysh
// 04/17/2022 Sun 16:01:20.70
#include<bits/stdc++.h>
using namespace std;
// #define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>in(a);
    vector<int>out(a);
    int c,d;
    //set<pair<int,int>>s;
    for(int i = 0;i<b;i++) {
        cin>>c>>d;
        //if(s.find({c,d}) == s.end()) {
            in[d - 1]++;
            out[c - 1]++;
            //s.insert({c,d});
        //}
    }
    for(int i = 0;i<a;i++) {
        cout<<out[i]<<" \n"[i == a - 1];
    }
    for(int i = 0;i<a;i++) {
        cout<<in[i]<<" \n"[i == a - 1];
    }
    for(int i = 0;i<a;i++) {
        cout<<out[i] + in[i]<<" \n"[i == a - 1];
    }
    return 0;
}