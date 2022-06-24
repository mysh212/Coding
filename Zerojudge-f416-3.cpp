// Author : ysh
// 06/22/2022 Wed 18:08:26.56
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

vector<int> check(string a) {
    vector<int>f(a.size());
    for(int i = 1,len = a.size();i<len;i++) {
        int j = f.at(i - 1);
        while(j > 0 && a.at(i) != a.at(j)) j = f.at(j - 1);
        if(a.at(j) == a.at(i)) f.at(i) = j + 1;
    }
    return f;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    string a,b;cin>>a>>b;
    string c = a + ' ' + b;
    vector<int>f(check(c));
    debug(f);
    int r = a.size();
    int ans = 0;
    for(int i : f) {
        if(i == r) ans++;
    }
    cout<<(ans == n ? "YES" : "NO")<<"\n";
    return 0;
}