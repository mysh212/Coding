// Author : ysh
// 11/06/2022 Sun 13:39:03.40
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    string a;
    int len = 0;
    while(cin>>a) {
        if(len + a.size() > n) {
            cout<<"\n",len = 0;
            if(a.size() > n) {
                while(1) {
                    if(a.size() < n) {
                        cout<<a;
                        len = a.size();
                        cout<<" ";
                        len++;
                        if(len == n) cout<<"\n";
                        break;
                    }
                    cout<<a.substr(0,n)<<"\n";
                    a = a.substr(n);
                }
                continue;
            }
        }
        len += a.size();
        cout<<a;
        if(len == n) {
            cout<<"\n ";
            len = 1;
        } else {
            cout<<" ";
            len++;
        }
    }
    return 0;
}