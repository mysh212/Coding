// Author : ysh
// 10/23/2022 Sun 19:07:44.74
using namespace std;
#include<fast>
#define int long long
int ans = 0;
int check() {
    int r = readint();
    if(r == 0) return 0;
    if(r & 1) {
        for(int i = 0;i<=2;i++) {
            int tmp = check();
            if(tmp != 0) ans += abs(r - tmp);
        }
        return r;
    }
    for(int i = 0;i<=1;i++) {
        int tmp = check();
        if(tmp != 0) ans += abs(r - tmp);
    }
    return r;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tmp = check();
    cout<<ans;
    return 0;
}