// Author : ysh
// 2023/08/08 Tue 18:28:28
// https://codeforces.com/contest/1624/problem/G
#include<bits/stdc++.h>
using namespace std;
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

    int n;cin>>n;
    while(n--) {
        vector<array<int,3>>f(31);
        int a,b;cin>>a>>b;

        while(b--) {
            int a,b,c;cin>>a>>b>>c;
            a--;b--;
            f.push_back({a,b,c});
        }

        int ans = (1LL << 31) - 1;
        assert(ans == INT_MAX);
        for(int i = 30;i>=0;i--) {
            int mask = (1 << i);
            color = vector<int>(a);
            iota(color.begin(),color.end(),0);

            for(auto &i : f) {
                if(i[0] == -1 || i[2] & mask) continue;
                mg(i[0],i[1]);
            }

            bool c = 1;
            for(int i = 1;i<a;i++) {
                if(ff(i) != ff(i - 1)) c = 0;
            }

            if(c) {
                for(auto &i : f) {
                    if(i[2] & mask) i[0] = i[1] = i[2] = -1;
                }
                ans = ans ^ mask;
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
}