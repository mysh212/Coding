#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n) {
        if(n == 0) return 0;
        int a[n][4] = {};
        cin>>a[0][3];
        a[0][0] = 0;
        a[0][1] = a[0][3];
        a[0][2] = a[0][3] * 2;
        for(int i = 1;i<n;i++) {
            cin>>a[i][3];
            a[i][0] = max(a[i - 1][0],max(a[i - 1][1],a[i - 1][2]));
            a[i][1] = max(a[i - 1][0],a[i - 1][1]) + a[i][3];
            a[i][2] = max(a[i - 1][0],a[i - 1][1]) + a[i][3] * 2;
        }
        cout<<max(a[n - 1][0],max(a[n - 1][1],a[n - 1][2]))<<"\n";
    }
}