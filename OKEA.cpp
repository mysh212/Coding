// Author : ysh
// 02/07/2022 Mon 12:10:07.26
// https://codeforces.com/contest/1634/problem/C
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

        int n;cin>>n;
        while(n--) {
            int a,b;cin>>a>>b;
            if(a == 1&&b == 1) {
                cout<<"YES\n1\n";
                continue;
            }
            if(b == 2&&a % 2 == 0) {
                cout<<"YES\n";
                int tmp = 1;
                for(int i = 0;i<(a>>1);i++) {
                    cout<<tmp<<" "<<tmp+2<<"\n"<<tmp + 1<<" "<<tmp + 3<<"\n";
                    tmp = tmp + 4;
                }
                continue;
            }
            if(b == 1) {
                cout<<"YES\n";
                for(int i = 0;i<a;i++) {
                    cout<<i + 1<<"\n";
                }
                continue;
            }
            if(a%2 == 0) {
                cout<<"YES\n";
                int tmp = 1;
                for(int i=0 ;i<(a>>1);i++) {
                    int t = tmp;
                    for(int j = 0;j<b;j++) {
                        cout<<t<<" ";
                        t = t + 2;
                    }
                    cout<<"\n";
                    t = tmp + 1;
                    for(int j = 0;j<b;j++) {
                        cout<<t<<" ";
                        t = t + 2;
                    }
                    cout<<"\n";
                    tmp = tmp + b * 2;
                }
                continue;
            }
            cout<<"NO\n";
        }
}