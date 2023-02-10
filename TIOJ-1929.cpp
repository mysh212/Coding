// Author : ysh
// 02/01/2023 Wed 16:38:58.09
// https://tioj.ck.tp.edu.tw/problems/1929
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<int>>f(a);
    vector<int>in(a);
    while(b--) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        in.at(b)++; 
    }
    int root = 0;
    for(int i = 0;i<a;i++) {
        if(in.at(i) == 0) {
            root = i;
            break;
        }
    }
    vector<int>now(a);
}