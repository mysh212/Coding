// Author : ysh
// 09/06/2022 Tue 17:35:51.97
#include<bits/stdc++.h>
using namespace std;
#include<strint.h>
template<typename T>
string check(T a,T b) {
    T tmp = min(a,b) - 1;
    if(a == b) {
        if(a % 3 == 0) {
            return "Win " + str(((tmp / 3) << 1) + 1);
        }
        return "Lose " + str((tmp / 3) << 1);
    }
    if(tmp % 3 == 0) {
        // if(a == b) return "Win " + str(((tmp / 3) << 1) + 1);
        return "Lose " + str((tmp / 3) << 1);
    }
    // if(a == b) return "Lose " + str(((tmp / 3) << 1) + 1);
    return "Win " + str(((tmp / 3) << 1) + 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    cout<<check(a,b);
    return 0;
}