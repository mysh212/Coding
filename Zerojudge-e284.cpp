// Author : ysh
// 06/23/2022 Thu 13:29:51.68
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n = 1;
    vector<int>f;
    while(n <= INT_MAX) {
        f.push_back(n);
        n = n << 1;
    }
    while(cin>>n) {
        if(binary_search(f.begin(),f.end(),n)) {
            cout<<"Yes\n";
            continue;
        }
        cout<<"No\n";
    }
    return 0;
}