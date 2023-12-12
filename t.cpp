// Author : ysh
// 2023/12/12 Tue 16:12:39
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    bool is_occupied[3][5] = {};
    for(int i = 2;i<5;i++) is_occupied[0][i] = 1;
    for(int i = 3;i<5;i++) is_occupied[1][i] = 1;

    int seat_left[3] = {2,3,5};
    const int seat_count[3] = {2,3,5};
    while(1) {
        if(seat_count[0] == 0 && seat_count[1] == 0 && seat_count[2] == 0) {
            printf("N\n");
            return 0;
        }

        printf("請輸入艙等: ");
        int tmp;
        while(scanf("%d",&tmp)) {
            if(tmp == -1) return 0;
            if(tmp <= 0 || tmp > 3) {
                printf("X\n");
                continue;
            }

            if(seat_left[tmp] == 0) {
                printf("X\n");
                continue;
            }

            break;
        }
        int now = tmp - 1;

        printf("請輸入座位: ");
        while(scanf("%d",&tmp)) {
            if(tmp <= 0 || tmp > seat_count[now]) {
                printf("X\n");
                continue;
            }

            break;
        }

        if(is_occupied[now][tmp - 1]) {
            printf("F\n");
            continue;
        }

        printf("S\n");
        is_occupied[now][tmp - 1] = 1;
    }
}