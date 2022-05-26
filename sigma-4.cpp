// Author : ysh
// 05/02/2022 Mon 18:56:36.25
// TLE
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    // long long tmp = 0;
    while(n--) {
        long long tmp = 0,temp = 0;
        cin>>tmp;
        int i = 0;
        bool c = false;
        while(1) {
            if(INT_MAX - temp < i) break;
            temp += i++;
            if(temp == tmp) {
                c = true;
                break;
            }
        }
        if(c) cout<<"YES";
        else cout<<"NO";
        cout<<"\n";
    }
}