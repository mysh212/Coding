// Author : ysh
// 05/12/2023 Fri 22:37:03.06
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int mark[26] = {};
        string tmp;cin>>tmp;
        for(char i : tmp) {
            mark[i - 'a']++;
        }
        int two,one;two = one = 0;
        for(int i = 0;i<26;i++) {
            if(mark[i] == 0) continue;
            if(mark[i] & 1 && mark[i] != 1) two++;
            else if(mark[i] & 1) one++;
            else two++;
        }
        if(two == 1) {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
    }
    return 0;
}