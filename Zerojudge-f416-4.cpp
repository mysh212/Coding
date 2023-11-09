// Author : ysh
// 2023/11/05 Sun 18:08:50
#include<bits/stdc++.h>
using namespace std;
vector<int> check(string a) {
    vector<int>f(a.size());
    for(int i = 1,len = a.size();i<len;i++) {
        int p = f[i - 1];
        while(a[p] != a[i] && p != 0) p = f[p - 1];
        if(a[p] == a[i]) f[i] = p + 1;
    }
    return f;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    string a,b;cin>>a>>b;
    int tmp = a.size(),ans = 0;
    for(int i : check(a + " " + b)) if(i == tmp) ans++;
    cout<<(ans == n ? "YES" : "NO");
    return 0;
}