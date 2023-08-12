// Author : ysh
// 2023/08/02 Wed 12:19:18
#include<bits/stdc++.h>
using namespace std;
struct box{
    int a,b,r;
    box(int a = 0,int b = 0,int r = 0):
        a(a), b(b), r(r) {};
    inline bool operator<(const box &a) const {
        return r < a.r;
    }
};

vector<int>color;
int ff(int x) {
    if(color.at(x) == x) return x;
    return color.at(x) = ff(color.at(x));
}
void mg(int a,int b) {
    color.at(ff(a)) = ff(b);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    while(cin>>a>>b) {
        color = vector<int>(a);
        iota(color.begin(),color.end(),0);

        vector<box>f;
        for(int i = 0;i<b;i++) {
            int a,b,c;cin>>a>>b>>c;
            f.push_back(box(a,b,c));
        }
        sort(f.begin(),f.end());

        long long ans = 0;
        for(box &i : f) {
            if(ff(i.a) == ff(i.b)) continue;
            mg(i.a,i.b);
            ans = ans + i.r;
        }

        bool c = 1;
        for(int i = 1;i<a;i++) {
            if(ff(i) != ff(i - 1)) {
                c = 0;
                break;
            }
        }
        if(c) cout<<ans<<"\n";
        else cout<<"-1\n";
    }
    return 0;
}