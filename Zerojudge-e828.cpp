// Author : ysh
// 05/05/2023 Fri  8:35:29.62
#include<bits/stdc++.h>
using namespace std;
int check(string a,string tmp)  {
    int n = a.size();
    int m = tmp.size();
    vector<vector<int>>f(2,vector<int>(m + 1));
    for(int i = 0;i<=m;i++) {
        f.at(0).at(i) = i << 1;
    }

    for(int i = 1;i<=n;i++) {
        for(int j = 0;j<=m;j++) {
            if(j == 0) {
                f.at(i & 1).at(j) = i << 1;
                continue;
            }
            if(a.at(i - 1) == tmp.at(j - 1)) {
                f.at(i & 1).at(j) = f.at(!(i & 1)).at(j - 1);
                continue;
            }
            f.at(i & 1).at(j) = min({f.at(!(i & 1)).at(j) + 2,f.at(i & 1).at(j - 1) + 2,f.at(!(i & 1)).at(j - 1) + 3});
        }
    }
    return f.at((n) & 1).at(m);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;cin>>a;
    int mmin,ans;mmin = INT_MAX,ans = 0;
    for(int i = 1;i<=3;i++) {
        string tmp;cin>>tmp;
        int now = check(a,tmp);
        if(now <= mmin) {
            mmin = now;
            ans = i;
        }
    }
    cout<<ans<<" "<<mmin;
    return 0;
}