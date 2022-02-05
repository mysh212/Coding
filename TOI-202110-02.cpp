#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    int a = 1,b = 0;
    int ans = 0;
    while(n--) {
        cin>>b;
        if(b>a) {
            ans += ( b - a ) * 3;
        } else {
            ans += ( a - b ) * 2;
        }
        swap(a,b);
    }
    cout<<ans;
    return 0;
}