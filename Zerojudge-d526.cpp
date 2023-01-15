// Author : ysh
// 01/15/2023 Sun 18:16:48.67
#include<bits/stdc++.h>
using namespace std;
struct box{
    int x = 0,y = -1,z = -1;
    box(int x = 0,int y = -1,int z = -1):
        x(x), y(y), z(z) {};
};
ostream& operator<<(ostream &out,box a) {
    out<<'['<<a.x<<','<<a.y<<','<<a.z<<']';
    return out;
}
#include<fast>
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n) {
        vector<box>t;
        function<void(int,int)> check = [&] (int x,int v) {
            #define now t.at(x)
            if(now.x > v) {
                if(now.y != -1) {
                    check(now.y,v);
                    return;
                }
                t.push_back(box(v,-1,-1));
                now.y = t.size() - 1;
                return;
            }
            if(now.z != -1) {
                check(now.z,v);
                return;
            }
            t.push_back(box(v,-1,-1));
            now.z = t.size() - 1;
            return;
            #undef now
        };
        function<void(int)> walk = [&] (int x) {
            cout<<t.at(x).x<<" ";
            if(t.at(x).y != -1) walk(t.at(x).y);
            if(t.at(x).z != -1) walk(t.at(x).z);
            return;
        };
        int tmp;cin>>tmp;
        t.push_back(box(tmp,-1,-1));
        for(int i = 1;i<n;i++) {
            cin>>tmp;
            // debug(t);
            check(0,tmp);
        }
        walk(0);
        cout<<"\n";
    }
    return 0;
}