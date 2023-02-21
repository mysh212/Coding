// Author : ysh
// 02/11/2023 Sat 13:55:57.48
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    char t;
    deque<pair<int,bool>>f(n),g(n);
    vector<bool>tof(n),tog(n);
    for(auto &i : f) cin>>i.first;
    int x;cin>>x;
    for(auto &i : f) {
        cin>>t;
        i.second = (t == '1');
        if(i.second == '1') {
            tof.at(i.first - 1) = 1;
        }
        i.first--;
    }
    for(auto &i : g) cin>>i.first;
    for(auto &i : g) {
        cin>>t;
        i.second = (t == '1');
        if(i.second == '1') {
            tog.at(i.first - 1) = 1;
        }
        i.first--;
    }

    vector<bool>mark(n);
    while(1) {
        vector<int>tmp;
        int r = 0;
        for(int i = 0;i<x;i++) {
            if(!f.at(i).second && tog.at(f.at(i).first)) {
                tmp.push_back(f.at(i).first);
                mark.at(f.at(i).first) = 1;
            }
        }
    }

}