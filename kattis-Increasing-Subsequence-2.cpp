// Author : ysh
// 06/02/2022 Thu 10:10:15.58
// https://open.kattis.com/problems/increasingsubsequence
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(1) {
        int n;cin>>n;
        if(n == 0) return 0;
        vector<int>f(n);
        for(int &i : f) {
            cin>>i;
        }
        vector<int>v;
        bool mark[n][n] = {};
        for(int i = 0;i<n;i++) {
            auto found = lower_bound(v.begin(),v.end(),f[i]);
            if(found == v.end()) {
                v.push_back(f[i]);
                mark[v.size()][i] = 1;
            } else {
                mark[found - v.begin() + 1][i] = 1;
                *found = f[i];
            }
        }
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                cout<<(int) mark[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<v.size();
        cout<<" ";
        // for(int i : v) {
        //     cout<<i<<" ";
        // }
        for(int i = 0,len = v.size();i<len;i++) {
            int mmin = INT_MAX;
            int l = 0;
            for(int j = 0;j<n;j++) {
                if(mark[i][j]) {
                    if(mmin > f[i]) {
                        
                    }
                }
            }
        }
        cout<<"\n";
    }
}