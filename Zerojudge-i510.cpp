// Author : ysh
// 06/27/2022 Mon  7:50:25.96
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;
    while(cin>>a>>a>>a) {
        string b;cin>>b;
        int c = a.find(b);
        if(c == -1) {
            cout<<"No\n";
            continue;
        }
        cout<<"Yes\npos: "<<c<<"\n";
    }
    return 0;
}