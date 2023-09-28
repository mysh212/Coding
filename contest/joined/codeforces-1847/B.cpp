// Author : ysh
// 2023/07/06 Thu 22:52:54
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>f(n);
        for(int &i : f) cin>>i;

        int now = f.at(0);
        for(int i : f) now = now & i;

        if(now != 0) cout<<1<<"\n";
        else {
            int now = f.at(0);
            int ans = 0;
            for(int i : f) {
                if(now == -1) now = i;
                else now = now & i;

                if(now == 0) ans++,now = -1;
            }

            cout<<ans<<"\n";
        }
    }
    return 0;
}