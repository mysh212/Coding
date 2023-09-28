// Author : ysh
// 05/28/2023 Sun 22:50:22.17
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>f((n << 1) + 1),g((n << 1) + 1);
        vector<int>ff(n),gg(n);
        for(int &i : ff) cin>>i;
        for(int &i : gg) cin>>i;
        for(int i = 0;i<n;i++) {
            int now = i + 1;
            while(now < n && ff.at(now) == ff.at(i)) now++;
            f.at(ff.at(i)) = max(f.at(ff.at(i)),now - i);
            // cerr<<i<<" "<<now<<"  ";
            i = now - 1;
        }
        // cerr<<"\t";
        for(int i = 0;i<n;i++) {
            int now = i + 1;
            while(now < n && gg.at(now) == gg.at(i)) now++;
            g.at(gg.at(i)) = max(g.at(gg.at(i)),now - i);
            // cerr<<i<<" "<<now<<"  ";
            i = now - 1;
        }
        // cerr<<"\n";
        int ans = 0;
        for(int i = 0,len = (n << 1);i<=len;i++) {
            ans = max(ans,f.at(i) + g.at(i));
        }
        cout<<ans<<"\n";
    }
    return 0;
}