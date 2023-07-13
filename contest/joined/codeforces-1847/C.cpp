// Author : ysh
// 2023/07/06 Thu 23:20:32
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>f(n);
        for(int &i : f) cin>>i;

        bitset<(1 << 8)>s;
        s.reset();
        s.set(0);
        int last = 0,ans = 0;
        for(int &i : f) {
            last = last xor i;
            s.set(last);
            for(int i = 0,len = (1 << 8);i < len;i++) if(s.test(i)) ans = max(ans,last xor i);
        }
        cout<<ans<<"\n";
    }
    return 0;
}