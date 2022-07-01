// Author : ysh
// 06/26/2022 Sun 10:52:36.74
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vector<bool>f(c + 1);
    int ans = 0;
    for(int i = a;i<=c;i = i + a) {
        f[i] = 1;
        ans += i;
        ans = ans % 26;
    }
    for(int i = b;i<=c;i = i + b) {
        if(f[i] == 0) {
            ans += i;
            ans = ans % 26;
        }
    }
    int tmp = (((int) 'A') - 1 + (ans % 26));
    cout<<(char) (tmp == ((int) 'A' - 1) ? 'Z' : tmp);
    return 0;
}