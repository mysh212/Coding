// Author : ysh
// 05/02/2022 Mon 18:48:06.08
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(1,0);
    long long tmp = 0;
    {
    int i = 0;
    while(1) {
        if(INT_MAX - f.back() < i) break;
        f.push_back(f.back() + i++);
    }
    }
    set<int>s(f.begin(),f.end());
    while(n--) {
        cin>>tmp;
        if(s.find(tmp) != s.end()) cout<<"YES";
        else cout<<"NO";
        cout<<"\n";
    }
    return 0;
}