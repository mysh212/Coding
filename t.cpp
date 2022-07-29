// Author : ysh
// 07/23/2022 Sat  8:57:56.82
#include<bits/stdc++.h>
using namespace std;
int main(int ac,char* as[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    auto f = fopen("1.in","r");
    auto ff = fopen("1.out","r");
    int a;
    fscanf(f,"%d",&a);
    int c[a][a] = {};
    int n,b;
    bool o = 0;
    int last = -1;
    while(fscanf(ff,"%d",&b) != EOF) {
        if(!o) {
            n = b;
            o = 1;
            continue;
        }
        if(last == -1) {
            last = b;
            continue;
        }
        if(b < a && b >= 0) {
            c[last][b] = c[last][b] + 1;
            last = b;
            continue;
        }
        return 1;
    }
    last = c[0][0];
    if(c[0][0] == 0) return 1;
    for(int i = 0;i<a;i++) {
        for(int j = 0;j<a;j++) {
            if(c[i][j] != last) {
                return 1;
            }
        }
    }
    cout<<"AC";
    return 0;
}