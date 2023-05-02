// Author : ysh
// 05/02/2023 Tue 23:27:13.46
// https://judge.tcirc.tw/ShowProblem?problemid=b036
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    unordered_set<string>a,b;
    string tmp;
    while(getline(cin,tmp)) {
        if(tmp == "0") {
            swap(a,b);
            continue;
        }
        a.insert(tmp);
    }
    if(a.size() == b.size()) cout<<"Equal";
    if(a.size() > b.size()) cout<<"A";
    if(a.size() < b.size()) cout<<"B";
    return 0;
}