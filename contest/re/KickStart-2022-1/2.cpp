// Author : ysh
// 04/17/2022 Sun 13:44:20.17
#include<bits/stdc++.h>
using namespace std;
#define alice(t) cout<<t<<" is ruled by Alice.\n"
#define nobody(t) cout<<t<<" is ruled by nobody.\n"
#define bob(t) cout<<t<<" is ruled by Bob.\n"
const char a[10] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    string t = "";
    set<char>s(a,a+10);
    for(int i = 1;i<=n;i++) {
        cout<<"Case #"<<i<<": ";
        cin>>t;
        char l = t[t.size() - 1];
        if(s.find(l) != s.end()) {
            alice(t);
            continue;
        }
        if(l == 'y'||l == 'Y') {
            nobody(t);
            continue;
        }
        bob(t);
    }
    return 0;
}