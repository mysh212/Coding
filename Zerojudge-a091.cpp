// Author : ysh
// 04/24/2022 Sun 18:56:20.43
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,tmp;
    multiset<int>f;
    while(cin>>n) {
        if(n == 1) {
            cin>>tmp;
            f.insert(tmp);
        }
        if(n == 2&&(!f.empty())) {
            cout<<*(--f.end())<<"\n";
            f.erase((--f.end()));
        }
        if(n == 3&&(!f.empty())) {
            cout<<*f.begin()<<"\n";
            f.erase(f.begin());
        }
    }
    return 0;
}