// Author : ysh
// 02/04/2022 Fri 13:21:34.43
// http://choj.me/problem/00115
#include<bits/stdc++.h>
using namespace std;
inline int cl(int x,int y,int xx,int yy) {
    return pow((x - xx),2) + pow((y - yy),2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int a[n][3] = {};
    int now[n] = {};
    for(int i = 0;i<n;i++) {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        now[i] = a[i][2];
    }
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>f;
    for(int i = 0;i<n;i++) {
        for(int j = i+1;j<n;j++) {
            int tmp = cl(a[i][0],a[i][1],a[j][0],a[j][1]);
            f.push({tmp,{i,j}});
        }
    }
    int non = -1;
    while(!f.empty()) {
        auto m = f.top();f.pop();
        int l = m.first;
        auto mm = m.second;
        int nn = mm.first;
        int nnn = mm.second;
        //cout<<l<<" "<<nn<<" "<<nnn<<"\n";
        //continue;
        if(now[nn] == 0||now[nnn] == 0) continue;
        if(now[nn]>now[nnn]) {
            now[nn] = now[nn] + now[nnn];
            now[nnn] = 0;
            non = nn;
        } else if(now[nn] == now[nnn]) {
            if(a[nn][2] > a[nnn][2]) {
                now[nnn] = now[nnn] + now[nn];
                now[nn] = 0;
                non = nnn;
            } else {
                now[nn] = now[nn] + now[nnn];
                now[nnn] = 0;
                non = nn;
            }
        } else {
            now[nnn] = now[nnn] + now[nn];
            now[nn] = 0;
            non = nnn;
        }
    }
    //return 0;
    cout<<non + 1;
    return 0;
}