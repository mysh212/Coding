// Author : derek
// 03/23/2022 Wed 14:51:28.06
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a[2][2] = {};
    int b[2][2] = {};
    int ans[2][2] = {};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}