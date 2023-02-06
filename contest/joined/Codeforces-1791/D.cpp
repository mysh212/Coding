// Author : ysh
// 02/03/2023 Fri 22:52:22.97
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int left[26] = {},right[26] = {};
        int n;cin>>n;
        int l,r;l = r = 0;
        vector<char>f;
        for(int i = 0;i<n;i++) {
            char tmp;cin>>tmp;
            f.push_back(tmp);
            right[tmp - 'a']++;
            if(right[tmp - 'a'] == 1) r++;
        }
        int ans = r;
        for(char i : f) {
            i = i - 'a';
            right[i]--;
            if(right[i] == 0) r--;
            left[i]++;
            if(left[i] == 1) l++;
            ans = max(ans,l + r);
        }
        cout<<ans<<"\n";
    }
    return 0;
}