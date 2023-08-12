// Author : ysh
// 2023/07/28 Fri 13:03:35
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int a = 1, b = 1, ans = 0;
    for(int i = 0; i < n; ++i){
        int aa, bb;
        cin >> aa >> bb;
        if(a == 1 && aa == 2){
            ++ans;
            a = aa;
        }
        if(a == 2 && aa == 1){
            ++ans;
            a = aa;
        }
        if(b == 1 && bb == 2){
            ++ans;
            b = bb;
        }
        if(b == 2 && bb == 1){
            ++ans;
            b = bb;
        }
    }

    cout << ans;
}