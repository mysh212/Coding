// Author : ysh
// 02/20/2022 Sun 10:36:21.45
// https://open.kattis.com/problems/alphabet
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;cin>>a;
    int c[27] = {};
    for(char i : a) {
        int now = (int) i - (int) 'a'+1;
        c[now] = max(c[now],c[now-1]+1);
        for(int j = now+1;j<27;j++) {
            c[j] = max(c[j],c[j-1]);
        }
        /*
        for(int k : c) {
            cout<<k<<" ";
        }
        cout<<"\n";
        */
    }
    cout<<26 - c[26];
    return 0;
}