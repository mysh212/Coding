// Author : ysh
// 07/01/2022 Fri 20:16:50.82
// https://choj.me/problem/c004
#include<bits/stdc++.h>
using namespace std; 
struct box{
    int x,y,z,r;
    box(int a,int b,int c,int d = 0):
        x(a), y(b), z(c), r(d) {};
    bool operator<(box a) {
        return z < a.z;
    }
    void check() {
        printf("[%d,%d,%d]\n",x,y,z);
        return;
    }
    void operator|(int a) {
        check();
        return;
    }
};
inline int dt(int a,int b,int c,int d) {
    return abs(a - c) + abs(b - d);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b,c,d;cin>>a>>b>>c>>d;
        vector<box>f;
        for(int i = 0;i<a;i++) {
            int a,b,c;cin>>a>>b>>c;
            f.emplace_back(a,b,c,i);
        }
        // for(int i = 0;i<a;i++) {
        //     f[i]|1;
        // }
        vector<bool>mark(a);
        queue<box>q;
        q.emplace(b,c,d);
        bool e = 0;
        while(!q.empty()) {
            box i = q.front();q.pop();
            int x = i.x;
            int y = i.y;
            int z = i.z;
            int t = i.r;
            t = t + 1;
            for(box j : f) {
                if((!mark[j.r]) && (dt(x,y,j.x,j.y) <= z)) {
                    if(j.z == 0) {
                        cout<<t<<"\n";
                        e = 1;
                        break;
                    }
                    mark[j.r] = 1;
                    q.push(box(j.x,j.y,j.z,t));
                }
            }
            if(e) break;
        }
        if(e) continue;
        cout<<-1<<"\n";
    }
    return 0;
}
