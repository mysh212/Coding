// Author : ysh
// 2026/11/05 Thu 15:17:05
#include<bits/stdc++.h>
#include <slow>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> f(n);
    for(auto &x : f) cin >> x;
    vector<int> st = vector<int> (f.begin(), f.end());
    sort(st.begin(), st.end());
    st.resize(unique(all(st)) - bg(st));
    debug(st);
    st.assign(st.begin()+1, st.end());
    int ans = 1;
    for(auto &color : st) {
        int i = 0;
        while(i < n) {
            if(f[i] != color) {
                i++;
                continue;
            }
            int j = i+1;
            while(j < n && color <= f[j]) j++;
            ans++, i = j;
            debug(i,j);
        }
    }
    return cout << ans << '\n', 0;
}