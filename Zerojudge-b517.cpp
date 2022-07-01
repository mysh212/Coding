// Author : ysh
// 06/25/2022 Sat 15:50:16.76
#include<bits/stdc++.h>
using namespace std;
vector<int>mark(81);
int check(int x) {
    if(mark[x] == x) return x;
    return mark[x] = check(mark[x]);
}
void ff(int a,int b) {
    mark[check(a)] = check(b);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string b;getline(cin,b);n = stoi(b);
    while(n--) {
        mark.clear();
        mark.resize(81);
        iota(mark.begin(),mark.end(),0);
        string a;getline(cin,a);
        stringstream s;
        s << a;
        vector<int>f[81];
        while(s >> b) {
            // cerr<<b<<b.find(',')<<stoi(b.substr(0,b.find(',')));
            int aa = stoi(b.substr(0,b.find(',')));
            int bb = stoi(b.substr(b.find(',') + 1,b.size() - b.find(',' + 1) - 1));
            f[aa].push_back(bb);
            ff(aa,bb);
        }
    }
}