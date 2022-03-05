// Author : ysh
// 03/05/2022 Sat 20:16:46.11
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int ans = 0;
    string tmp;
    unordered_set<string>f;
    while(n--) {
        cin>>tmp;
        f.insert(tmp);
    }
    for(string i : f) {
        int l = i.length();
        for(int j = 1;(j << 1) < l;j++) {
            if(i.substr(0,j) == i.substr(l - j)) {
                if(f.find(i.substr(j,l - (j << 1))) != f.end()) ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}