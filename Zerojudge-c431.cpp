// Author : ysh
// 11/24/2022 Thu 23:01:08.67
#include<stdio.h>
using namespace std;
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int c[100] = {};
    int n;scanf("%d",&n);
    int tmp;
    while(n--) {
        scanf("%d",&tmp);
        c[tmp - 1]++;
    }
    for(int i = 0;i<100;i++) {
        int r = i + 1;
        while(c[i]--) {
            printf("%d ",r);
        }
    }
    return 0;
}