// Author : ysh
// 03/06/2023 Mon 12:23:41.81
// https://judge.tcirc.tw/ShowProblem?problemid=c014
#include<bits/stdc++.h>
using namespace std;
#include<fast>
#include<table>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    table<int>t(f);
    while(n--) {
        int a,b;cin>>a>>b;
        a--;b--;
        cout<<t.get(a,b) + 1<<"\n";
    }
    return 0;
}