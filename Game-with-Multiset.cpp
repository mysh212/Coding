// Author : ysh
// 2023/12/27 Wed 00:49:30
// https://codeforces.com/problemset/problem/1913/C
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(30);
    while(n--) {
        int a,b;cin>>a>>b;
        if(a == 1) {
            f.at(b)++;
        }
        if(a == 2) {
            for(int i = 29;i>=0;i--) {
                for(int j = 0;j<f.at(i);j++) if(b >= (1 << i)) b = b - (1 << i);
            }
            if(b == 0) cout<<"YES";
            else cout<<"NO";
            cout<<"\n";
        }
    }
    return 0;
}