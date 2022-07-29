// Author : ysh
// 07/24/2022 Sun 18:29:47.98
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int m;cin>>m;
        vector<pair<int,int>>f(m);
        for(pair<int,int> &i : f) {
            cin>>i.first;
        }
        for(pair<int,int> &i : f) {
            cin>>i.second;
        }
        sort(f.begin(),f.end(),[] (pair<int,int>a,pair<int,int>b) {
            if(a.second != b.second) return a.second < b.second;
            return a.first < b.first;
        });
        int now = 0;
        bool c = 0;
        for(auto i : f) {
            if((now += i.first) > i.second) {
                c = 1;
                break;
            }
        }
        if(c) cout<<"no\n";
        else cout<<"yes\n";
    }
    return 0;
}