// Author : ysh
// 2023/06/24 Sat 22:23:00
#include<bits/stdc++.h>
using namespace std;
inline bool ok(int a,int b) {
    while(a != 0) {
        if((a & 1) && (!(b & 1))) return 0;
        a = a >> 1;
        b = b >> 1;
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n,k;cin>>n>>k;
        int ans = 0;
        vector<vector<int>>f(3,vector<int>(n));
        for(int i = 0;i<=2;i++) {
            for(int &j : f.at(i)) cin>>j;
            int tmp = ans;
            for(int &i : f.at(i)) {
                tmp = tmp | i;
                if(!((tmp ^ k) & tmp)) ans = tmp;
                else break;
            }
        }
        cout<<(ans == k ? "Yes" : "No")<<"\n";
    }
    return 0;
}