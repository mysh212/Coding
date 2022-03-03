// Author : ysh
// 02/23/2022 Wed  8:38:30.62
// https://judge.tcirc.tw/ShowProblem?problemid=d011
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int a[n],b[n];
    for(int i = 0;i<n;i++) {
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b,b+n);
    map<int,int>f;
    int k = 0;
    for(int i = 0;i<n;i++) {
        if(f.find(b[i]) == f.end()) {
            //printf("f.insert({%d,%d});\n",b[i],k);
            f.insert({b[i],k});
            k++;
        }
    }
    for(int i = 0;i<n;i++) {
        cout<<f.find(a[i]) -> second<<" ";
    }
    return 0;
}