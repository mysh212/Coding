// Author : ysh
// 2024/04/13 Sat 23:39:10
#include<bits/stdc++.h>
using namespace std;
#include<slow>
string input() {
    string tmp;cin>>tmp;
    return tmp;
}
string upper(string x) {
    for(char &i : x) {
        if(islower(i)) i = i + ('A' - 'a');
    }
    return x;
}
string replace(string x,string from,string to) {
    while(x.find(from) != string::npos) {
        int now = x.find(from);
        if(now == 0) x = to + x.substr(from.size());
        else x = x.substr(0,now) + to + x.substr(now + from.size());
    }
    return x;
}
inline bool isin(auto a,auto b) {
    for(auto &i : b) if(i == a) return 1;
    return 0;
}
inline void print(auto x,auto end = "\n") {
    cout<<x<<end;
    return;
}

string n;
vc<char>pre({'A','B','C','D'});
vc<char>useless({'(',')',' '});

string check(auto x) {
    auto p = n;
    re(i,pre.size()) {
        p = replace(p,string(pre[i]) + "'",(x[i] ? '0' : '1'));
        p = replace(p,pre[i],x[i]);
    }
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout<<replace("123 456 123","123","789");
    cout<<isin('a',string("abc"));
}