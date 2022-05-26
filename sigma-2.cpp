// Author : ysh
// 05/02/2022 Mon 18:48:06.08
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    set<int>f;
    // f.set(0);
    long long tmp = 0;
    {
    int i = 0;
    while(1) {
        if(INT_MAX - tmp < i) break;
        tmp = tmp + i++;
        f.insert(tmp);
    }
    }
    while(n--) {
        cin>>tmp;
        if(f.find(tmp) != f.end()) cout<<"YES";
        else cout<<"NO";
        cout<<"\n";
    }
    return 0;
}