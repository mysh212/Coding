// Author : ysh
// 11/09/2022 Wed 14:02:08.70
// https://tioj.ck.tp.edu.tw/problems/2267
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<bool>f(n + 1);
    for(int i = 0;i<n;i++) {
        char tmp;cin>>tmp;
        if(tmp == '1') f.at(i) = 1;
    }
    if(n == 1) {
        cout<<"Yes";
        return 0;
    }
    for(int i = 0;i<n - 1;i++) {
        if(f.at(i)) {
            f.at(i) = !f.at(i);
            f.at(i + 1) = !f.at(i + 1);
            f.at(i + 2) = !f.at(i + 2);
        }
    }
    if(!(f.at(n - 2) || f.at(n - 1))) {
        cout<<"Yes";
        return 0;
    }
    if(f.at(n - 2) && f.at(n - 1)) {
        cout<<"Yes";
        return 0;
    }
    if(!f.at(n - 2) && f.at(n - 1)) {
        if(n % 3 == 1 || n % 3 == 0) cout<<"Yes";
        else cout<<"No";
        return 0;
    }
    cout<<"No";
    return 0;
}