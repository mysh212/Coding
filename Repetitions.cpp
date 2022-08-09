// Author : ysh
// 08/08/2022 Mon 16:49:12.98
// https://cses.fi/problemset/task/1069
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;cin>>a;
    int c[4];
    char s[4] = {'A','T','C','G'};
    int mmax = 0;
    int ans = 0;
    char last = 0;
    for(char i : a) {
        for(int j = 0;j<=3;j++) {
            if(i == s[j]) {
                if(i == last) ans++;
                else {
                    mmax = max(mmax,ans);
                    ans = 1;
                }
                last = i;
            }
        }
    }
    mmax = max(mmax,ans);
    cout<<mmax;
    return 0;
}