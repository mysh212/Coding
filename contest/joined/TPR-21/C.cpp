// Author : ysh
// 05/29/2022 Sun 15:25:57.71
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(b);
    int sig = 0;
    for(int &i : f) {
        cin>>i;
        sig += i;
    }
    double tmp = (double) a / sig;
    for(int i = 0;i<b;i++) {
        cout<< fixed << setprecision(1) << (double) round((double) tmp * f[i] * 10) / 10.0 <<" \n"[i == b - 1];
    }
    return 0;
}