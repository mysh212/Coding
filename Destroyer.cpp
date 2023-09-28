// Author : ysh
// 2023/08/14 Mon 10:18:23
// https://codeforces.com/contest/1836/problem/A
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        bool c = 1;
        vector<int>mark(100);
        for(int i = 0;i<n;i++) {
            int tmp;cin>>tmp;
            mark.at(tmp)++;
        }

        for(int j = 1;j<100;j++) {
            if(mark.at(j) > mark.at(j - 1)) c = false;
        }

        cout<<(c ? "Yes" : "No")<<" ";
    }
    return 0;
}