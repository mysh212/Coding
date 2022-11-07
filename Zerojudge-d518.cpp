// Author : ysh
// 10/31/2022 Mon 21:48:57.92
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string tmp;
    while(cin>>n) {
        unordered_map<string,int>a;
        int t = 0;
        while(n--) {
            cin>>tmp;
            auto found = a.find(tmp);
            if(found == a.end()) {
                a.insert({tmp,++t});
                cout<<"New! "<<t<<"\n";
                continue;
            }
            cout<<"Old! "<<found->second<<"\n";
        }
    }
    return 0;
}