// Author : ysh
// 2024/02/20 Tue 09:35:35
// https://codeforces.com/contest/1926/problem/C
#include<bits/stdc++.h>
using namespace std;
#include<slow>
const int R = 5;
int check(int x) {
    int ans = 0;
    while(x != 0) {
        ans = ans + (x % 10);
        x = x / 10;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>>mark(R + 1,vector<int>(10));
    re(i,1,10) {
        mark.at(0).at(i) = mark.at(0).at(i - 1) + i;
    }
    for(int i = 1;i<=R;i++) {
        re(j,1,10) {
            mark.at(i).at(j) = mark.at(i - 1).at((i == 1 ? j - 1 : j)) * 10 + ((45 * j) * pow(10,i - 1));
        }
    }
    debug(mark);
    
    // re(i,5,5 + 1) re(j,1,9 + 1) {
    //     int ans = 0;
    //     int t = j * pow(10,i);
    //     re(i,1,t) {
    //         ans += check(i);
    //     }
    //     cerr<<ans<<" "<<mark.at(i).at(j);
    //     assert(ans == mark.at(i).at(j));
    // }

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        int ans = 0;
        re(i,R + 1) {
            ans = ans + mark.at(i).at(n % 10) + (check(n / 10) * ((n % 10) - 0 + (i == 0 ? 1 : 0)) * int(pow(10,i)));
            n = n / 10;
            debug(ans);
        }
        outl(ans);
    }
    return 0;
}