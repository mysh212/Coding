// Author : ysh
// 05/01/2022 Sun 17:35:10.40
// http://192.168.193.20/problem/22/
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(1,0);
    // long long tmp = 0;
    {
    int i = 0;
    while(1) {
        if(INT_MAX - f.back() < i) break;
        f.push_back(f.back() + i++);
    }
    }
    int tmp;
    while(n--) {
        cin>>tmp;
        if(binary_search(f.begin(),f.end(),tmp)) cout<<"YES";
        else cout<<"NO";
        cout<<"\n";
    }
    return 0;
}