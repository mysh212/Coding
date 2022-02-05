// Author : ysh
// 01/27/2022 Thu 15:57:19.69
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a[6];
    cout<<sizeof(a)<<"\n";
    cout<<"\n";
    for(int &i : a) {
        cin>>i;
    }
    for(int &j : a) {
        cout<<j<<" ";
    }
    cout<<"\n";
    memset(a,0,sizeof(a));
    for(int &j : a) {
        cout<<j<<" ";
    }
    return 0;
}