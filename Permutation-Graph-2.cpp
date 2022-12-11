// Author : ysh
// 12/09/2022 Fri  9:13:44.30
// https://codeforces.com/contest/1696/problem/D
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>f(n);
        int d = 0;
        for(int i = 0;i<n;i++) {
            cin>>f.at(i);
            if(f.at(i) == n) d = i;
        }
        vector<int>l(n),r(n);
        l.at(0) = r.at(0) = f.at(0);
        for(int i = 1;i<n;i++) {
            l.at(i) = max(l.at(i - 1),f.at(i));
            r.at(i) = min(r.at(i - 1),f.at(i));
        }
        int ans = 0;
        int now = INT_MAX;bool find_min = 1;
        for(int i = d - 1;i >= 0;i--) {
            if(i == 0) {
                ans++;
                continue;
            }
            if(find_min) {
                if(r.at(i - 1) != r.at(i)) {
                    find_min = 0;
                    ans++;
                }
                continue;
            }
            if(l.at(i - 1) != l.at(i)) {
                find_min = 1;
                ans++;
            }
        }
        l.at(n - 1) = r.at(n - 1) = f.at(n - 1);
        for(int i = n - 2;i>=0;i--) {
            l.at(i) = max(l.at(i + 1),f.at(i));
            r.at(i) = min(r.at(i + 1),f.at(i));
        }
        find_min = 1;
        for(int i = d + 1;i < n;i++) {
            if(i == n - 1) {
                ans++;
                continue;
            }
            if(find_min) {
                if(r.at(i + 1) != r.at(i)) {
                    find_min = 0;
                    ans++;
                }
                continue;
            }
            if(l.at(i + 1) != l.at(i)) {
                find_min = 1;
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}