// Author : ysh
// 03/08/2023 Wed 10:39:25.37
// https://judge.tcirc.tw/ShowProblem?problemid=c055
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
#include<fast>
// vector<string>mark;
int check(vector<char>&f,int n,char last = ' ') {
    if(n == (1 << f.size()) - 1) return 1;
    int ans = 0;
    vector<bool>mk(26);
    for(int i = 0,len = f.size();i<len;i++) {
        if(!(n & (1 << i)) && f.at(i) != last && !mk.at(f.at(i) - 'A')) {
            ans = ans + check(f,n | (1 << i),f.at(i));
            mk.at(f.at(i) - 'A') = 1;
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<char>f(n);
    for(char &i : f) {
        i = readchar();
    }
    cout<<check(f,0);
    // for(string &i : mark) {
    //     cout<<"\n"<<i;
    // }
    return 0;
}