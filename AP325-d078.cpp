// Author : ysh
// 04/29/2022 Fri 10:15:44.92
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    vector<int>v;
    for(int i : f) {
        auto found = lower_bound(v.begin(),v.end(),i);
        if(found == v.end()) v.push_back(i);
        else *found = i;
    }
    cout<<v.size();
    return 0;
}