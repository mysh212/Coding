// Author : ysh
// 2024/01/05 Fri 13:17:57
#include<bits/stdc++.h>
using namespace std;
vector<int> check(string a) {
    int m = a.size();
    vector<int>f(m);
    for(int i = 1;i<m;i++) {
        int p = f[i - 1];
        while(p != 0 && a.at(i) != a.at(p)) p = f[p - 1];
        if(a.at(i) == a.at(p)) f[i] = p + 1;
    }

    int p = 0;
    while(a.at(p) != ' ') f[p++] = 0;
    return f;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    string a,b;cin>>a>>b;
    int ans = 0;

    for(int &i : check(a + ' ' + b)) if(i == a.size()) ans++;
    cout<<(ans == n ? "YES" : "NO")<<"\n";
    return 0;
}