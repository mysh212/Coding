// Author : ysh
// 05/28/2023 Sun 23:44:09.87
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<pair<int,int>>f(n);
        for(auto &i : f) cin>>i.first;
        for(auto &i : f) cin>>i.second;

        sort(f.begin(),f.end());
        int pre = 0;
        for(int i = 0;i<n;i++) {
            if(f.at(i).first * f.at(i).first > n) {
                pre = i - 1;
                break;
            }
        }

        for(int i = pre + 1;i<n;i++) {
            
        }
    }
    return 0;
}