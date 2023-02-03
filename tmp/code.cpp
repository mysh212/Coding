// Author : ysh
// 02/03/2023 Fri 13:58:35.77
#include<bits/stdc++.h>
using namespace std;
bool ok(string a,string b) {
    // cerr<<a<<" "<<b<<"\n";
    bool c = 0;
    for(int i = 0;i<a.size();i++) {
        if(a.at(i) != b.at(i) && c) return 0;
        if(a.at(i) != b.at(i)) c = 1;
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a,b;cin>>a>>b;
    int n = a.size() - (b.size() - 1);
    int ans = 0;
    vector<int>aans;
    for(int i = 0;i<n;i++) {
        if(ok(a.substr(i,b.size()),b)) ans++,aans.push_back(i + 1);
    }
    cout<<ans<<"\n";
    for(int i = 0;i<aans.size();i++) cout<<aans.at(i)<<" \n"[i == aans.size() - 1];
    return 0;
}