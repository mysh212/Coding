// Author : ysh
// 12/05/2022 Mon 19:12:06.97
// NF
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<pair<int,int>>f;
        int a,b;
        while(cin>>a>>b) {
            if(a == 0 && b == 0) break;
            f.push_back({a,b});
        }
        sort(f.begin(),f.end());
        int r = 0;
        int ans = 0;
        for(int i = 0,len = f.size();i<len - 1;i++) {
            // if(f.at(i).first > r) r = f.at(i - 1).second,ans++;
            if(f.at(i + 1).first > r) r = f.at(i).second,ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}