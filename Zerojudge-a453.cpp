// Author : ysh
// 01/26/2023 Thu 16:00:03.22
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int>f(1002);
    for(int i = 0;i<=1001;i++) {
        f.at(i) = i * i;
    }
    int n;cin>>n;
    while(n--) {
        int a,b,c;cin>>a>>b>>c;
        if(binary_search(f.begin(),f.end(),b * b - (a * c) * 4)) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}