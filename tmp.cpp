// Author : ysh
// 03/18/2023 Sat 20:49:14.23
#include<bits/stdc++.h>
using namespace std;
int check(vector<int>&f) {
    int last = f.at(0);
    vector<int>mark((4e5) + 1);
    for(int i = 1;i<f.size();i++) {
        mark.at(f.at(i) + last) = 1;
        last = f.at(i);
    }
    for(int i = 0;i<=(4e5);i++) {
        if(!mark.at(i)) return i;
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>f(n);
        for(int &i : f) {
            cin>>i;
        }
        int mmin = INT_MAX;
        do{
            mmin = min(check(f),mmin);
        } while(next_permutation(f.begin(),f.end()));
        cout<<mmin<<"\n";
    }
    return 0;
}