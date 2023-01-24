// Author : ysh
// 01/24/2023 Tue  9:27:53.66
// https://tioj.ck.tp.edu.tw/problems/2193
#include<bits/stdc++.h>
using namespace std;
// inline bool cp(int a,int b) {
//     int aa = __builtin_popcount(a);
//     int bb = __builtin_popcount(b);
//     // if(aa != bb) {
//         return aa < bb;
//     // }
//     // return a < b;
// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<int,int>>f(n);
    for(auto &i : f) {
        cin>>i.first;
        i.second = __builtin_popcount(i.first);
    }
    vector<int>v;
    for(int i = 0;i<=10;i++) {
        for(auto &j : f) {
            if(j.second == i) v.push_back(j.first);
        }
    }
    // sort(f.begin(),f.end(),cp);
    for(int &i : v) {
        cout<<i<<" ";
    }
    return 0;
}