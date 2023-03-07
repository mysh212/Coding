// Author : ysh
// 03/06/2023 Mon 11:30:42.59
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<string,string>>f(n);
    while(n--) {
        string a,b;cin>>a>>b;
        f.push_back({a,b});
    }
    string tmp;cin>>tmp;
    for(auto &i : f) {
        if(i.first == tmp) {
            cout<<i.second;
            return 0;
        }
    }
    cout<<"404";
    return 0;
}