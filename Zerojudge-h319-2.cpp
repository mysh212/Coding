// Author : ysh
// 04/02/2022 Sat 13:05:56.85
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<bool>f(a);
    for(int i = 0;i<a;i++) {
        f[i] = 1;
    }
    string d;int tmp;
    while(b--) {
        cin>>d;
        cin>>tmp;
        if(d == "-") {
            f[tmp - 1] = 0;
        }
        if(d == "?") {
            for(int i = tmp;i<a;i++) {
                if(f[i] == 1) cout<<i + 1<<"\n";
                if(i == a - 1&&f[i] != 1) cout<<-1<<"\n";
            }
        }
    }
    return 0;
}