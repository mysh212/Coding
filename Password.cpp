// Author : ysh
// 11/20/2022 Sun  7:12:03.21
// https://codeforces.com/contest/1743/problem/A
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a;cin>>a;
        // vector<bool>mark(10);
        for(int i = 0;i<a;i++) {
            int tmp;cin>>tmp;
            // mark.at(tmp) = 1;
        }
        int r = 10 - a;
        cout<<(r * (r - 1)) / (1 * 2) * 6<<"\n";
    }
    return 0;
}