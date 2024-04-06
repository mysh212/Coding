// Author : ysh
// 2024/03/28 Thu 09:59:13
#include<stdio.h>
using namespace std;
void print(int ** f) {
    for(int i = 0;i<10;i++) {
        for(int j = 0;j<10;j++) {
            printf("%d ",f[i][j]);
        }
        printf("\n");
    }
    return;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int f[10][10] = {};
    int t = 0;
    for(int i = 0;i<10;i++) {
        for(int j = 0;j<10;j++) {
            t = t + 1;
            f[i][j] = t;
        }
    }

    print(&(f[0]));
    return 0;
}