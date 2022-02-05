// Author : ysh
// 01/11/2022 Tue 20:30:45.66
#include<bits/stdc++.h>
using namespace std;
const int xx[] = {-1,0,1,0};
const int yy[] = {0,1,0,-1};
int la,lb;
int r = 1;
int c[101][101] = {};
int mark[101][101] = {};
void check(int a,int b,int n,int k) {
    queue<pair<int,int>>f;
    queue<int>q;
    q.push(1);
    f.emplace(make_pair(a,b));
    while(!f.empty()) {
        auto now = f.front();f.pop();
        int m = q.front();q.pop();
        //if(now.first == 2&&now.second == 6) printf("ok");
        mark[now.first][now.second] = m;
        for(int i = 0;i<4;i++) {
            if(k == 2&&i == 3) continue;
            int x = now.first+yy[i];
            int y = now.second+xx[i];
            if(x<0||y<0||x>la||y>lb) continue;
            if(mark[x][y] != 0) continue;
            if(c[x][y] == 1) {
                f.emplace(make_pair(x,y));
                q.push(m+1);
            }
        }       
    }
    return;
}
void pc(int a,int b) {
    for(int i = 0;i<a;i++) {
        for(int j = 0;j<b;j++) {
            cout<<mark[i][j]<<" ";
        }
        cout<<"\n";
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n) {
        cout<<"Case "<<r<<":\n";
        int a,b;cin>>a>>b;
        la=b;lb=b;
        int start = 0;
        for(int i = 0;i<a;i++) {
            for(int j = 0;j<b;j++) {
                cin>>c[i][j];
                if(i == 0&&c[i][j] == 1) {
                    start = j;
                }
            }
        }
        check(0,start,1,n);
        pc(a,b);
        for(int i = 0;i<=100;i++) {
            for(int j = 0;j<=100;j++) {
                c[i][j] = 0;
                mark[i][j] = 0;
            }
        }
        r++;
    }
    return 0;
}