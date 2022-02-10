// Author : ysh
// 02/06/2022 Sun 22:41:13.03
// https://codeforces.com/contest/1634/problem/A
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        string c;cin>>c;
        bool did = 0;
        if(b == 0) {
            cout<<1<<"\n";
            continue;
        }
        for(int i = 0;i<((a>>1)+1);i++) {
            if(c.at(i) != c.at(a - (i + 1))) {
                did = 1;
                cout<<2;
                break;
            }
        }
        if(did) cout<<"\n";
        else cout<<1<<"\n";
    }
    return 0;


    /*
    int n;cin>>n;
    string a;
    while(n--) {
        queue<string>f;
        queue<string>v;
        int b;cin>>b;
        cin>>a;
        f.push(a);
        while(b--) {
            while(!f.empty()) {
                auto now = f.front();f.pop();
                auto nnow=now;
                reverse(now.begin(),now.end());
            }
        }
    }
    */
}