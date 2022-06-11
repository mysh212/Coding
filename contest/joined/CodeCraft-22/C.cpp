// Author : ysh
// 06/01/2022 Wed 10:18:52.81
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        string t;cin>>t;
        int sig = 0;
        int fl,lr;
        bool c = 0;
        for(int j = 0,len = t.size();j<len;j++) {
            char i = t[j];
            if((!c) && i == '1') {
                fl = j;
                c = 1;
            }
            if(i == '1') {
                lr = j;
            }
            sig += stoi(t.substr(j,1));
        }
        int l,r,ls,rs;
        l = stoi(t.substr(0,1));
        r = stoi(t.substr(t.size() - 1,1));
        ls = sig - r;
        rs = sig - l;
        // printf("l = %d,r = %d,ls = %d,rs = %d,fl = %d,lr = %d,sig = %d",l,r,ls,rs,fl,lr,sig);
        if(l == 1 && r == 1) {
            cout<<ls * 10 + rs<<"\n";
            continue;
        }
        if(l == 1) {
            if(b >= (t.size() - lr - 1)) {
                ls = ls - 1;
                cout<<ls * 10 + rs<<"\n";
                continue;
            }
            cout<<ls * 10 + rs<<"\n";
            continue;
        }
        if(r == 1) {
            if(b >= (fl)) {
                rs = rs - 1;
                cout<<ls * 10 + rs<<"\n";
                continue;
            }
            cout<<ls * 10 + rs<<"\n";
            continue;
        }
        if(b >= (t.size() - lr - 1)) {
            b = b - (t.size() - lr - 1);
            ls = ls - 1;
        }
        if(b >= (fl)) {
            b = b - fl;
            rs = rs - 1;
        }
        cout<<ls * 10 + rs<<"\n";
        continue;
    }
    return 0;
}