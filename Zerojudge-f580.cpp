// Author : ysh
// 2024/07/24 Wed 23:02:13
#include<bits/stdc++.h>
using namespace std;
struct box{
    vector<int>f;

    static constexpr int R = 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6;
    const int mark[2][6] = {{3,0,2,5,4,1}, {4,1,0,3,5,2}};

    box() {
        f = vector<int>({1,4,2,3,5,6});
    }

    void check(int x) {
        // for(int i : f) cout<<i<<" ";
        // cout<<"\n";
        x--;
        int now[6];
        for(int i = 0;i<6;i++) {
            now[i] = f[mark[x][i]];
        }
        for(int i = 0;i<6;i++) {
            f[i] = now[i];
        }
        return;
    }

    int get() {
        return f.front();
    }

    inline void operator=(const box &a) {
        f = a.f;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<box>f(a);
    while(b--) {
        int a,b;cin>>a>>b;
        if(b > 0) swap(f.at(a - 1),f.at(b - 1));
        else f.at(a - 1).check(-b);
    }
    
    for(auto &i : f) cout<<i.get()<<" ";

    return 0;
}