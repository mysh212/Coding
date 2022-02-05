#include<bits/stdc++.h>
using namespace std;
int main() {
    int a,b;cin>>a>>b;
    int m;cin>>m;
    int ans = 1;
    for(int i = 0;i<b;i++) {
        ans = ans * a;
        ans = ans % m;
    }
    cout<<ans;
    return 0;
}