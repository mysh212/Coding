// Author : ysh
// 10/31/2022 Mon 21:13:52.47
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    gp_hash_table<string,null_type>a;
    int n;cin>>n;
    string tmp;
    while(n--) {
        cin>>tmp;
        a.insert(tmp);
    }
    int m;cin>>m;
    while(m--) {
        cin>>tmp;
        if(a.find(tmp) != a.end()) {
            cout<<"yes\n";
            continue;
        }
        cout<<"no\n";
        a.insert(tmp);
    }
    return 0;
}