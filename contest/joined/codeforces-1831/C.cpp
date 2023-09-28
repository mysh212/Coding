// Author : ysh
// 05/28/2023 Sun 22:58:47.53
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<vector<pair<int,int>>>f(n);

        for(int i = 1;i<n;i++) {
            int a,b;cin>>a>>b;
            a--;b--;
            f.at(a).push_back(make_pair(b,i));
            f.at(b).push_back(make_pair(a,i));
        }

        int ans = 1;
        function<void(int,int,int,int)> check = [&] (int last,int x,int mmax,int now) {
            ans = max(ans,now);
            for(auto &i : f.at(x)) {
                if(i.first == last) continue;
                if(i.second > mmax) check(x,i.first,i.second,now);
                else check(x,i.first,i.second,now + 1);
            }
            return;
        };
        check(-1,0,-1,1);

        cout<<ans<<"\n";
    }
    return 0;
}