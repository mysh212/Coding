// Author : ysh
// 06/12/2022 Sun 17:32:48.08
#include<bits/stdc++.h>
using namespace std;
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n;cin>>n;
    map<pair<int,int>,int>m;
    for(int i = 0;i<n;i++) {
        int a,b,c;cin>>a>>b>>c;
        m.insert({{a,b},c});
    }
    int ans = 0;
    int x = 0,y = 0,d = 0;
    while(1) {
        // system("pause");
        // cout<<x<<" "<<y<<"\n";
        if(x == 30000 || y == 30000 || x == -30000 || y == -30000) {
            break;
        }
        auto found = m.find({x,y});
        if(found != m.end()) {
            ans++;
            int c = found->second;
            if(c == 0) {
                if(d == 0) {
                    y++;
                    d = 3;
                } else if(d == 1) {
                    x--;
                    d = 2;
                } else if(d == 2) {
                    y--;
                    d = 1;
                } else {
                    x++;
                    d = 0;
                }
            } else {
                if(d == 0) {
                    y--;
                    d = 1;
                } else if(d == 1) {
                    x++;
                    d = 0;
                } else if(d == 2) {
                    y++;
                    d = 3;
                } else {
                    x--;
                    d = 2;
                }
            }
            continue;
        }
        if(d == 0 || d == 2) {
            if(d == 0) {
                x++;
            } else {
                x--;
            }
        }
        if(d == 1 || d == 3) {
            if(d == 1) {
                y--;
            } else {
                y++;
            }
        }
    }
    cout<<ans;
    return 0;
}