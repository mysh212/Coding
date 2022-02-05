// Author : ysh
// 02/03/2022 Thu 13:28:31.38
// http://choj.me/problem/00076
#include<bits/stdc++.h>
using namespace std;
vector<bool>a(10000000);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int tmp;cin>>tmp;
        if(a[tmp] == 1) a[tmp] = 0;
        else a[tmp] = 1;
    }
    for(int i = 0;i<10000000;i++) {
        if(a[i] == 1) {
            cout<<i;
            return 0;
        }
    }
}