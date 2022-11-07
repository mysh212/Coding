// Author : ysh
// 11/06/2022 Sun 14:10:34.45
#include<bits/stdc++.h>
using namespace std;
char lower(char x) {
    if(x >= 'A' && x <= 'Z') {
        return x - 'A' + 'a';
    }
    return x;
}
string read(string &x) {
    string a;
    for(char &i : x) {
        if(i == ' ' && !a.empty()) break;
        if(i == ' ') continue;
        a = a + i;
    }
    return a;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;getline(cin,a);
    string b;getline(cin,b);
    string aa,bb;
    for(char i : a) {
        if(isalpha(i)) {
            aa = aa + lower(i);
            continue;
        }
        if(i == ' ' || i == ',' || i == '.') {
            aa = aa + ' ';
            continue;
        }
        aa = aa + i;
    }
    for(char i : b) {
        if(isalpha(i)) {
            bb = bb + lower(i);
            continue;
        }
        if(i == ',' || i == '.') continue;
        if(i == ' ') {
            bb = bb + ' ';
            continue;
        }
        bb = bb + i;
    }
    vector<string>aaa,bbb;
    stringstream aaaa,bbbb;
    aaaa << aa;
    bbbb << bb;
    string tmp;
    while(aaaa >> tmp) {
        aaa.push_back(tmp);
    }
    while(bbbb >> tmp) {
        bbb.push_back(tmp);
    }
    int n,m;n = aaa.size(),m = bbb.size();
    // for(auto i : aaa) cout<<i<<" ";
    vector<vector<int>>idontknow(n + 1,vector<int>(m + 1));
    set<string>s;
    int mmax = 0;
    for(int k = 0;k<=1;k++) {
        for(int i = 0;i<n;i++) {
            int combo = 0;
            for(int j = 0;j<m;j++) {
                int r = j + i;
                if(j >= aaa.size() or r >= bbb.size()) continue;
                if(aaa.at(j) == bbb.at(r)) combo++,mmax = max(mmax,combo);
                else combo = 0;
            // cerr<<j<<" "<<r<<endl;
            }
        }
        swap(aaa,bbb);
        swap(n,m);
    }
    // for(auto &i : idontknow) {for(int &j : i) cerr<<j<<" "; cerr<<"\n";}
    // for(string i : s) cerr<<i<<" ";
    cout<<fixed<<setprecision(2)<<mmax * 100.0 / aaa.size()<<"%";
    return 0;
}