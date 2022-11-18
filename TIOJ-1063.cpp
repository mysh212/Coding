// Author : ysh
// 11/18/2022 Fri 15:56:30.20
// https://tioj.ck.tp.edu.tw/problems/1063
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<bool>>f(a,vector<bool>(b));
    vector<vector<bool>>v(a,vector<bool>(b));
    for(int i = 0;i<a;i++) {
        for(int j = 0;j<b;j++) {
            int tmp;cin>>tmp;
            if(tmp == 1) f.at(i).at(j) = 1;
        }
    }
    
}