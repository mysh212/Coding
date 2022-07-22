// Author : ysh
// 07/22/2022 Fri 17:50:33
#include<bits/stdc++.h>
using namespace std;
int n = 0;
vector<int>f;
void check(int x) {
    f.push_back(x);
    if(x != n) {
        check(x + 1);
        f.push_back(x);
    }
    for(int i = 1;i <= x - 2;i++) {
        if(i == 1 && x == n) continue;
        f.push_back(i);
        f.push_back(x);
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    if(n == 2) {
        cout<<"5\n0 1 1 0 0";
        return 0;
    }
    // n--;
    check(0);
    cout<<f.size() + (n)<<"\n";
    vector<bool>mark(n);
    for(int &i : f) {
        if(i == n) i = 0;
        cout<<i<<" ";
        if(!mark[i]) {
            cout<<i<<" ";
            mark[i] = 1;
        }
    }
    return 0;
}