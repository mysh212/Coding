// Author : ysh
// 02/08/2022 Tue 22:41:20.72
// http://choj.me/problem/a053
#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    deque<int>f;
    while(n--) {
        
        int a,b;cin>>a>>b;
        if(a == 1) {
            f.push_back(b);
        }
        if(a == 2) {
            while(b--) {
                f.pop_back();
            }
        }
        if(a == 3) {
            cout<<f.at(b)<<"\n";
        }
    }
    return 0;
}