// Author : ysh
// 07/01/2022 Fri  6:48:54.97
// https://choj.me/problem/c003
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int ans = 0;
        int a,b,c;cin>>a>>b>>c;
        vector<int>f(a);
        int last = 0;
        map<int,int>m;
        m.insert({0,1});
        int mmax = b + c,mmin = b - c;
        for(int &i : f) {
            cin>>i;
            i = i + last;
            last = i;
            int tmp = i - mmax;
            auto found = m.lower_bound(tmp);
            for(auto j = found;j != m.end();j++) {
                if(i - j->first < mmin) break;
                // if(i - j->first > mmax) continue;
                ans = ans + j->second;
            }
            m[i]++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}