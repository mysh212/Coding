// Author : ysh
// 02/07/2023 Tue 15:22:51.32
// https://codeforces.com/group/H0qY3QmnOW/contest/425166/problem/B
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a,b;cin>>a>>b;
    string c;cin>>c;
    int n = a.size();
    assert(a.size() == b.size());
    for(int i = 0;i<n;i++) {
        if(c.at(i) == '^') cout<<(int) ((a.at(i) == '1') xor (b.at(i) == '1'));
        else {
            if(b.at(i) == '1') {
                if(a.at(i) == '0') cout<<'X';
                else cout<<1;
            } else {
                cout<<0;
            }
        }
    }
    return 0;
}