// Author : ysh
// 12/13/2022 Tue 16:48:13.91
// https://tioj.ck.tp.edu.tw/problems/2253
#include<bits/stdc++.h>
using namespace std;
struct box{
    int x,y;
    vector<int>f;
    box(int x = 0,int y = 0,vector<int>f = vector<int>()):
        x(x), y(y), f(f) {};
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vector<int>v(a);
    for(int &i : v) {
        cin>>i;
    }
    vector<box>f;
    for(int i = 0;i<b;i++) {
        int x,y;cin>>x>>y;
        vector<int>tmp;
        for(int i = 0;i<c;i++) {
            int r;cin>>r;
            tmp.push_back(r);
        }
        f.push_back(box(x,y,tmp));
    }
}