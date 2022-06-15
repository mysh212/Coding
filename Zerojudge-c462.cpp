// Author : ysh
// 06/11/2022 Sat 18:03:48.04
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;cin>>a;
    string s;cin>>s;
    int now,ans;now=ans=0;
    int c = 0;
    bool isbig = (!islower((int) s[0]));
    for(int i : s) {
        if(!(isbig xor islower(i))) {
            isbig = !isbig;
            // c = c + 1;
            if(c % a == 0) {
                c = 1;
                now++;
                ans = max(ans,now / a);
                continue;
            }
            c = 1;
            now = 1;
            continue;
        }
        c = c + 1;
        if(c > a) {
            c = 1;
            now = 1;
            continue;
        }
        c += 1;
        now += 1;
        ans = max(ans,now / a);
    }
    cout<<ans;
    return 0;
}