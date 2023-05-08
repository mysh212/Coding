// Author : ysh
// 05/08/2023 Mon 20:07:59.02
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        string tmp;cin>>tmp;
        string s = tmp;
        bool c = 0;
        for(int i = 1,len = s.size();i<len;i++) {
            if(s.at(i) != s.at(i - 1)) {
                c = 1;
                break;
            }
        }
        if(!c) {
            cout<<"-1\n";
            continue;
        }
        reverse(s.begin(),s.end());
        if(s == tmp) {
            cout<<s.size() - 1<<"\n";
        }
        if(s != tmp) {
            cout<<s.size()<<"\n";
        }
    }
    return 0;
}