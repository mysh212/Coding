// Author : ysh
// 01/17/2023 Tue 21:23:38.16
#include<bits/stdc++.h>
using namespace std;
#define endno {cout<<"-1\n";return 0;}
void show(bool x,vector<int>f) {
    for(int &i : f) {
        for(int j = 1;j<=i;j++) {
            cout<<(x ? 2 : 0);
        }
        x = !x;
    }
    cout<<"\n";
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    if(a == 0 || b == 0 || (b & 1 && b < 11)) endno;
    if(b & 1) {
        if(a < 10) endno;
        if(b == 11) {
            if(a < 11) endno;
            if(a == 11) {
                for(int i = 1;i<=b - 11;i++) cout<<2;
                for(int i = 1;i<=11;i++) cout<<"02";
                cout<<"\n";
                for(int i = 1;i<=11;i++) cout<<20;
                for(int i = 1;i<=b - 11;i++) cout<<2;
                return 0;
            } else {
                vector<int>tmp;
                for(int i = 0;i<b - 11;i++) cout<<2;
                for(int i = 1;i<=10;i++) cout<<"20";
                cout<<"002";
                for(int i = 1;i <= a - 12;i++) cout<<"0";
                cout<<"\n";
                for(int i = 1;i <= a - 11;i++) cout<<"0";
                for(int i = 1;i<=11;i++) cout<<"20";
                for(int i = 1;i<=b - 11;i++) cout<<"2";
                cout<<"\n";
                return 0;
            }
        } else {
            if(a == 10) {
                for(int i = 0;i<b - 12;i++) cout<<2;
                cout<<"0222";
                for(int i = 1;i<=9;i++) cout<<"02";
                cout<<"\n";
                for(int i = 1;i <= a - 10;i++) cout<<"0";
                for(int i = 1;i<=9;i++) cout<<"20";
                cout<<"2220";
                for(int i = 1;i<=b - 12;i++) cout<<"2";
                cout<<"\n";
                return 0;
            }
            if(a == 11) {
                for(int i = 1;i<=b - 11;i++) {
                    cout<<2;
                }
                for(int i = 1;i<=11;i++) cout<<"02";
                cout<<"\n";
                for(int i = 1;i<=9;i++) cout<<"02";
                cout<<"02220";
                for(int i = 1;i<=b - 12;i++) cout<<2;
                return 0;
            }
            for(int i = 0;i<b - 11;i++) cout<<2;
            for(int i = 1;i<=10;i++) cout<<"20";
            cout<<"002";
            for(int i = 1;i <= a - 12;i++) cout<<"0";
            cout<<"\n";
            for(int i = 1;i <= a - 10;i++) cout<<"0";
            for(int i = 1;i<=9;i++) cout<<"20";
            cout<<"2220";
            for(int i = 1;i<=b - 12;i++) cout<<"2";
            cout<<"\n";
            return 0;
        }
    }
    if(a == 1) {
        for(int i = 0;i<b - 2;i++) {
            cout<<2;
        }
        cout<<"022\n220";
        for(int i = 0;i<b - 2;i++) {
            cout<<2;
        }
        cout<<"\n";
    } else {
        for(int i = 0;i < b - 1;i++) {
            cout<<2;
        }
        cout<<"002";
        for(int i = 0;i<a - 2;i++) {
            cout<<0;
        }
        cout<<"\n";
        for(int i = 0;i<a - 1;i++) {
            cout<<0;
        }
        cout<<"220";
        for(int i = 0;i < b - 2;i++) {
            cout<<2;
        }
        cout<<"\n";
    }
    return 0;
}