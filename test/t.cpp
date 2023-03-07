// Author : ysh
// 03/07/2023 Tue 11:42:02.86
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

   int n,k;cin>>n>>k;
   vector<int>f(n);
   for(int &i : f) {
        cin>>i;
   }
   vector<int>g;
   for(int i = 0;i<n;i++) {
        for(int j = i;j<n;j++) {
            g.push_back(f.at(i) + f.at(j));
        }
   }
   sort(g.rbegin(),g.rend());
   cout<<g.at(k - 1);
   return 0;
}