// Author : ysh
// 04/23/2022 Sat 22:25:31.25
// a055
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string>f;
    string n;
    while(cin>>n) {
        if(n == "0") break;
        f.push_back(n);
    }
    int m;cin>>m;
    string a;
    while(m--) {
        cin>>a;
        if(a == "Add") {
            string tmp;cin>>tmp;
            f.push_back(tmp);
        }
        if(a == "Qry") {
            if(f.size() == 0) {
                cout<<"Empty\n";
                continue;
            }
            for(int i = 0,len = f.size();i<len;i++) {
                cout<<f[i]<<" \n"[i == len - 1];
            }
        }
        if(a == "Del") {
            if(f.empty()) {
                cout<<"Error\n";
                continue;
            }
            f.pop_back();
        }
        if(a == "Clear") {
            f.clear();
        }
    }
}