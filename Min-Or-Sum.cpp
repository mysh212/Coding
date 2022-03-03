// Author : ysh
// 02/20/2022 Sun 22:33:53.20
// https://codeforces.com/contest/1635/problem/A
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int tmp,now = 0;
    while(n--) {
        cin>>tmp;
        int temp;
        for(int i = 0;i<tmp;i++) {
            cin>>temp;
            now = now | temp;
        }
        cout<<now<<"\n";
        now = 0;
    }
    return 0;
}