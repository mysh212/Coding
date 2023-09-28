// Author : ysh
// 06/02/2023 Fri 18:42:57.23
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<array<int,3>>f(n);
    for(auto &i : f) {
        cin>>i[1]>>i[2];
        i[0] = i[2] - i[1];
    }
    sort(f.begin(),f.end());

    for(auto &i : f) {
        cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<"\n";
    }
    
    vector<int>v(n);
    v.at(n - 1) = 
    for(int i = n - 2;i>=0;i--) {

    }
    cout<<v.at(n - 1);
    return 0;
}