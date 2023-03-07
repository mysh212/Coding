// Author : ysh
// 03/04/2023 Sat 19:55:15.91
// https://tioj.ck.tp.edu.tw/problems/2054
#include<bits/stdc++.h>
#include<fast>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vector<pair<int,int>>f(a);
    for(auto &i : f) {
        cin>>i.second>>i.first;
    }
    sort(f.begin(),f.end());
    int l = 0;
    int ans = 1;
    for(int i = 0;i<a;i++) {
        while(f.at(i).first - f.at(l).first > b) l++;
        vector<int>tmp;
        for(int j = l;j<=i;j++) {
            tmp.push_back(f.at(j).second);
        }
        sort(tmp.begin(),tmp.end());
        int ll = 0;
        for(int j = 0,len = tmp.size();j<len;j++) {
            while(tmp.at(j) - tmp.at(ll) > c) ll++;
            ans = max(ans,j - ll + 1);
        }
    }
    cout<<ans;
    return 0;
}