// Author : ysh
// 2023/06/21 Wed 07:07:02
// https://codeforces.com/contest/1843/problem/A
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        deque<int>f(n);
        for(int &i : f) cin>>i;

        int ans = 0;
        sort(f.begin(),f.end());
        while(f.size() > 1) {
            ans = ans + (f.back() - f.front());
            f.pop_back();
            f.pop_front();
        }
        cout<<ans<<" ";
    }
    return 0;
}