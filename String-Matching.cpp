// Author : ysh
// 07/31/2022 Sun  9:25:04.48
// https://cses.fi/problemset/task/1753
#include<bits/stdc++.h>
using namespace std;
vector<int>f;
int check(string x,int b) {
    int ans = 0;
    f.resize(x.size());
    for(int i = 1,len = f.size();i<len;i++) {
        int p = f[i - 1];
        while(x[p] != x[i] && p != 0) p = f[p - 1];
        if(x[p] == x[i]) f[i] = p + 1;
        if(f[i] == b) ans++;
    }
    f.clear();
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a,b;
    getline(cin,a);
    getline(cin,b);
    cout<<check(b + " " + a,b.size());
    return 0;
}