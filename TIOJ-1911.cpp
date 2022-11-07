// Author : ysh
// 11/06/2022 Sun 10:05:12.95
// https://tioj.ck.tp.edu.tw/problems/1911
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    multiset<int>s;
    vector<int>v;
    while(scanf("%d",&n)) {
        if(n == 0) break;
        if(n == -1) {if(!s.empty()) v.push_back(*s.begin()),s.erase(s.begin());}
        else if(n == -2) {if(!s.empty()) v.push_back(*prev(s.end())),s.erase(prev(s.end()));}
        else s.insert(n);
    }
    for(int &i : v) cout<<i<<" ";
    return 0;
}