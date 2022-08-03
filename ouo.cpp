// Author : ysh
// 08/02/2022 Tue 22:27:26.95
// https://192.168.193.20/problem/35
#include<bits/stdc++.h>
using namespace std;
vector<int>f;
int check(string a) {
  int ans = 0;
  for(int i = 1,len = a.size();i<len;i++) {
 	int p = f[i - 1];
    while(a[p] != a[i] && p != 0) p = f[p - 1];
    if(a[p] == a[i]) f[i] = p + 1;
    if(f[i] == 3) ans++;
  }
  return ans;
}
int main() {
  int n;cin>>n;
  while(n--) {
    string a;
    cin>>a;
    f.clear();
    f.resize(a.size() + 4);
    cout<<check("ouo " + a)<<"\n";
    // for(int i : f) cout<<i<<" ";
    // cout<<"\n";
  }
  return 0;
}
//挑戰裸寫