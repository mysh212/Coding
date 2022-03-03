// Author : ysh
// 02/26/2022 Sat 18:57:26.82
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        vector<int>c(a+1);
        vector<long long>d(a+1);
        map<long long,int>m;
        m.insert({0,1});
        long long ans = (-1) * (INT_MAX-1),mmax = 0;
        for(int i = 1;i<=a;i++) {
            cin>>c[i];
            d[i] = d[i-1] + c[i];
            long long find = d[i] - b;
            auto found = m.lower_bound(find);
            if(found != m.end()) {
                if(ans < d[i] - found->first) {
                    ans = d[i] - found->first;
                    mmax = found -> second;
                } else if(ans == d[i] - found -> first) {
                    mmax += found -> second;
                }
            }
            //printf("[%d] ",mmax);
            m[d[i]]++;
        }
        //cout<<m[8];
        cout<<ans<<" "<<mmax<<"\n";
    }
    return 0;
}