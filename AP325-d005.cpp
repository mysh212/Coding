// Author : ysh
// 07/14/2022 Thu 17:05:33.66
#include<bits/stdc++.h>
using namespace std;
string s;
int t = 0;
int check(int a) {
    // cout<<s<<"\n";
    if(s.at(t) == '1') {
        t++;
        // s = s.substr(2,s.size());
        return a;
    }
    if(s.at(t) == '0') {
        t++;
        // s = s.substr(2,s.size());
        return 0;
    }
    int ans = 0;
    if(s.at(t) == '2') {
        t++;
        // s == s.substr(2,s.size());
        for(int i = 1;i <= 4;i++) {
            ans += check(a >> 2);
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>s;
    int n;cin>>n;
    cout<<check(n * n);
    return 0;
}