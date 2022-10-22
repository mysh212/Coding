// Author : ysh
// 10/20/2022 Thu  8:35:24.74
#include<bits/stdc++.h>
using namespace std;
string ans = "";
string two(int x) {
    string tmp;
    do {
        tmp = ((x & 1) ? '1' : '0') + tmp;
    } while(x >>= 1);
    while(tmp.size() < 3) {
        tmp = '0' + tmp;
    }
    return tmp;
}
inline bool check(string &s) {
    bool tmp = (s.at(0) == '1' ? 1 : 0);
    int c = 0;
    for(char &i : s) {
        if(i != '1' && i != '0') return 0;
        if(c != 7 && (i == '1' ? 1 : 0) == tmp) {
            c++;
            continue;
        }
        ans = ans + (tmp ? '1' : '0');
        ans = ans + two(c) + ' ';
        tmp = (i == '1');
        c = 1;
    }
    ans = ans + (tmp ? '1' : '0');
    ans = ans + two(c) + ' ';
    return 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    // cerr<<two(6);
    string s;getline(cin,s);n = stoi(s);
    while(n--) {
        getline(cin,s);
        ans = "";
        if(check(s)) {
            cout<<ans;
            cout<<round((((ans.size() / 5 * 4) * 1.0) / s.size()) * 100)<<"%\n";
            continue;
        }
        cout<<-1<<"\n";
    }
}