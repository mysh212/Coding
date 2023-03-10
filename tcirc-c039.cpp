// Author : ysh
// 03/09/2023 Thu 13:32:02.65
// https://judge.tcirc.tw/ShowProblem?problemid=c039
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
#include<fast>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<pair<int,int>>f(a);
    for(auto &i : f) {
        cin>>i.first;
    }
    for(auto &i : f) {
        cin>>i.second;
    }
    vector<int>mark(b + 1,(int) -1e9);
    mark.at(b) = 0;
    for(auto &i : f) {
        for(int j = 0;j <= 17;j++) {
            int item = (1 << j);
            if(item > i.second) break;
            int now = i.first * item; 
            i.second = i.second - item;  
            for(int k = 0;k <= b;k++) {
                if(k <= b - now) mark.at(k) = max(mark.at(k),mark.at(k + now) + item);
            }
        }
        int now = i.first * i.second; 
        for(int k = 0;k <= b;k++) {
            if(k <= b - now) mark.at(k) = max(mark.at(k),mark.at(k + now) + i.second);
        }
        // for(int &i : mark) cout<<(i == (int) 1e9 ? 0 : i)<<" ";
        // cout<<"\n";
    }
    cout<<(mark.at(0) < 0 ? -1 : mark.at(0));
    return 0;
}