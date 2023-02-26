// Author : ysh
// 02/25/2023 Sat  7:08:07.73
// https://cses.fi/problemset/task/2138
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
#define N 50000
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<int>>f(a);
    vector<int>to(a);
    bitset<N>s[a];
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        swap(a,b);
        f.at(a).push_back(b);
        to.at(b)++;
    }
    
    for(int i = 0;i < a;i++) s[i].set(i);
    queue<int>q;
    for(int i = 0;i<a;i++) {
        if(to.at(i) == 0) q.push(i);
    }
    
    while(!q.empty()) {
        int now = q.front();q.pop();
        for(int i : f.at(now)) {
            s[i] = s[i] | s[now];
            if(--to.at(i) == 0) {
                q.push(i);
            }
        }
    }
    
    for(int i = 0;i<a;i++) {
        cout<<s[i].count()<<" ";
    }
    return 0;
}