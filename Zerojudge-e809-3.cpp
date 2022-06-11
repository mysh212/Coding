// Author : ysh
// 05/27/2022 Fri 16:32:50.02
#include<bits/stdc++.h>
using namespace std;
string a,b;
int f[26];
inline bool cp(int l,int r) {
    return f[l] < f[r];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a;cin>>b;
    int n;cin>>n;
    int s = b.size();
    int c[s] = {};
    int aa = a.size();
    for(int i = 0;i<aa;i++) {
        f[(int) (a.at(i) - 'A')] = i;
    }
    for(int i = 0;i<s;i++) {
        c[i] = (int) b.at(i);
    }
    sort(c,c+s,cp);
    for(int i = 0;i<n;i++) {
        cin>>s;
        cout<<(char) c[s - 1]<<"\n";
    }
    return 0;
}