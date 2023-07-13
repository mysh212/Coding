// Author : ysh
// 2023/07/07 Fri 22:50:06
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b,c;cin>>a>>b>>c;
        pair<int,int>pre({-1,-1});
        vector<pair<int,int>>v;
        while(a--) {
            vector<int>f(b);
            for(int &i : f) cin>>i;
            sort(f.begin(),f.end());
            int last = 0;
            int t = 0;
            for(int &i : f) {
                i = last += i;
                if(i > c) break;
                t++;
            }
            int ans = 0;
            for(int i = 0;i<t;i++) {
                ans = ans + f.at(i);
            }
            v.push_back({b - t,ans});
            if(pre == make_pair(-1,-1)) pre = {b - t,ans};
        }
        sort(v.begin(),v.end());
        auto found = lower_bound(v.begin(),v.end(),pre);
        cout<<found - v.begin() + 1<<"\n";
    }
    return 0;
}