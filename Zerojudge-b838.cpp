// Author : ysh
// 09/02/2022 Fri 23:08:44.10
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        string a;cin>>a;
        int r = 0;
        int t = 0;
        for(char &i : a) {
            if(r < 0) break;
            if(i == '(') {
                r++;
                t++;
            } else if (i == ')') {
                r--;
            }
        }
        if(r == 0) {
            cout<<t<<"\n";
            continue;
        }
        cout<<0<<"\n";
    }
    return 0;
}