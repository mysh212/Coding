// Author : ysh
// 02/03/2022 Thu 16:15:24.04
// http://choj.me/problem/00074
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    pair<int,int> out;
    out = {1,1};
    queue<pair<int,int>>work;
    while(n--) {
        string a;
        cin>>a;
        if(a == "push") {
            int ta,tb;
            cin>>ta>>tb;
            work.push({ta,tb});
        }
        if(a == "pop") {
            auto now = work.front();work.pop();
            int ta,tb;
            ta = now.first;
            tb = now.second;
            out.first = out.first * ta;
            out.second = out.second * tb;
        }
        if(a == "print") {
            int tmp = __gcd(out.first,out.second);
            int tmpa = out.first/tmp;
            int tmpb = out.second/tmp;
            cout<<tmpa<<"/"<<tmpb<<"\n";
            out.first = tmpa;
            out.second = tmpb;
        }
    }
    return 0;
}