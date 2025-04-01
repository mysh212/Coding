// Author : ysh
// 2024/12/11 Wed 20:42:39
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) cin>>i;

    vector<int>l,r;
    for(int i = 0;i<n;i++) {
        int tmp;cin>>tmp;
        if(f.at(i) > tmp) l.push_back(i + 1);
        else r.push_back(i + 1);
    }

    if(l.empty()) cout<<"-1";
    else for(int &i : l) cout<<i<<" ";
    cout<<"\n";

    if(r.empty()) cout<<"-1";
    else for(int &i : r) cout<<i<<" ";
    cout<<"\n";

    return 0;
}