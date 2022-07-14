// Author : ysh
// 07/14/2022 Thu 17:18:40.46
#include<bits/stdc++.h>
using namespace std;
vector<int>f;
int n;
int check(int x,int sig = 1) {
    if(x == n) return (int) (sig == 1);
    return check(x + 1,sig * f[x] % 10009) + check(x + 1,sig);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    f.resize(n);
    // int ans = 0;
    for(int &i : f) {
        cin>>i;
        i = i % 10009;
        // if(i == 1) ans = ans + 1;
    }
    cout<<check(0) - 1;
    return 0;
}