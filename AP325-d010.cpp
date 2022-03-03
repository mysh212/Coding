// Author : ysh
// 02/23/2022 Wed  8:48:27.42
// https://judge.tcirc.tw/ShowProblem?problemid=d010
#include<bits/stdc++.h>
using namespace std;
const int mmax = 1000000000;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int a[n];
    for(int i = 0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    int tmp = a[0];
    int c = 1;
    queue<int>f({a[0]});
    for(int i = 1;i<n;i++) {
        if(a[i] != tmp) {
            c++;
            f.push(a[i]);
            tmp = a[i];
        }
    }
    cout<<c<<"\n";
    while(!f.empty()) {
        cout<<f.front()<<" ";
        f.pop();
    }
    return 0;
}