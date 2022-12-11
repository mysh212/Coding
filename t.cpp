// Author : ysh
// 12/10/2022 Sat 22:16:52.05
#include<bits/stdc++.h>
using namespace std;
int a,b,c;
// void check(int a,int b,int c,int d) {
//     if(b == -1) {
//         for(int i = a;i<=13;i++) {
//             check()
//         }
//     }
// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 1;i<=52;i++) {
        for(int j = i + 1;j<=52;j++) {
            for(int k = 1;k<=52;k++) {
                for(int l = k + 1;l<=52;l++) {
                    if(l == i || l == j || k == i || k == j) continue;
                    if(l <= 13 && k <= 13) a++;
                    if((i > 13 && j > 13) && (k <= 13 && l <= 13)) b++;
                    c++;
                }
            }
        }
    }
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}