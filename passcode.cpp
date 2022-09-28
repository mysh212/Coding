// Author : ysh
// 09/17/2022 Sat 10:02:43.17
// https://tioj.ck.tp.edu.tw/problems/1035
#include<iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a,b;getline(cin,a);getline(cin,b);
    int aa = a.size(),bb = b.size();
    // vector<vector<int>>c(2,vector<int>(5e4+2));
    int c[2][(int) 5e4+2] = {};
    // int c[2][bb+1] = {};
    int mmax = 0;
    for(int i = 0;i<aa;i++) {
        for(int j = 1;j<=bb;j++) {
            int now = i & 1;
            int r = j - 1;
            if(a[i] == b[r]) {
                c[now][j] = c[!(now)][r] + 1;
                mmax = max(mmax,c[now][j]);
                continue;
            }
            c[now][j] = c[!(now)][r];
        }
    }
    printf("%d",mmax);
    return 0;
}