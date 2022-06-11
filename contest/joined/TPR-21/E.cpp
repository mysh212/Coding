// Author : ysh
// 05/29/2022 Sun 15:42:42.22
#include<bits/stdc++.h>
using namespace std;
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n;cin>>n;
    // while(n--) {
    //     string tmp;
    //     cin>>tmp;
    //     if(tmp != "/cf_register") continue;
    //     cin>>tmp;
    //     string h;
    //     cin>>h;
    //     cin>>tmp;
    //     cout<<"?"<<h<<"\n";
    //     cout<<"!password 212\n";
    //     cin>>tmp;
    //     if(tmp == "/check") {
    //         cin>>tmp;
    //         cout<<"?"<<h<<"\n";
    //         cin>>tmp;
    //         if(tmp == "212") cout<<"!result Success\n";
    //     }
    //     cin>>tmp;
    // }
    string tmp,h;
    int t;
    int id = 0;
    while(cin>>tmp) {
        id++;
        //cout<<1;
        if(id == 1) continue;
        if(id == 2) {
            h = tmp;
            continue;
        }
        if(id == 3) {
            t = stoi(tmp);
            cout<<"?"<<h<<"\n";
            continue;
        }
        if(id == 4) {
            cout<<"!password 212\n";
            continue;
        }
        if(id == 6) {
            if(t + 60 < stoi(tmp)) {
                cout<<"!result Failed\n";
                id = 0;
                continue;
            }
            if(h == "212") {
                cout<<"?"<<h<<"\n";
                t = 0;
                continue;
            }
        }
        if(id == 7) {
            if(tmp == h) {
                cout<<"!result Success\n";
                id = 0;
                continue;
            }
            cout<<"!result Failed\n";
            id = 0;
            continue;
        }
    }
}