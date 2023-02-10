// Author : ysh
// 02/03/2023 Fri 22:13:57.53
// https://codeforces.com/gym/425267
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...);
#endif

deque<int> check(string a) {
    deque<int>f(a.size());
    int l = 0,r = 0;
    for(int i = 1,len = a.size();i<len;i++) {
        f[i] = max(0,min(r - i + 1,f[i - l]));
        while(i + f[i] < len && a[i + f[i]] == a[f[i]]) f[i]++;
        if(i + f[i] - 1 > r) l = i,r = i + f[i] - 1;
    }
    return f;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a,b;cin>>a>>b;
    int aa = a.size(),bb = b.size();
    auto f = check(b + " " + a);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    auto g = check(b + " " + a);
    int ans = 0;
    vector<int>aans;
    for(int i = 0;i<=bb;i++) f.pop_front(),g.pop_front();
    swap(f,g);
    for(int i = 0,len = aa - bb;i<=len;i++) {
        if(g.at(i) + f.at((aa - 1) - (i + bb - 1)) >= bb - 1) ans++,aans.push_back(i + 1);
    }
    cout<<ans<<"\n";
    for(int &i : aans) {
        cout<<i<<" ";
    }
    return 0;
}