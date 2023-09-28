// Author : ysh
// 2023/07/01 Sat 18:53:06
// https://codeforces.com/contest/1791/problem/D
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        string a;cin>>a;
        vector<int>left(26),right;
        right = left;
        int l,r;l = r = 0;
        for(char &i : a) {
            left.at(i - 'a')++;
            if(left.at(i - 'a') == 1) l++;
        }

        int ans = l;
        for(char &i : a) {
            left.at(i - 'a')--;
            right.at(i - 'a')++;
            if(left.at(i - 'a') == 0) l--;
            if(right.at(i - 'a') == 1) r++;
            ans = max(ans,l + r);
        }
        cout<<ans<<"\n";
    }
    return 0;
}