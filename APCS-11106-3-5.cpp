// Author : ysh
// 06/27/2022 Mon 11:34:20.47
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    
}
void check(int &c,int &d,int &x,int &y) {
            if(c == 0) {
                if(d == 0) {
                    d = 1;
                } else if(d == 1) {
                    d = 0;
                } else if(d == 2) {
                    d = 3;
                } else {
                    d = 2;
                }
            } else {
                if(d == 0) {
                    d = 3;
                } else if(d == 1) {
                    d = 2;
                } else if(d == 2) {
                    d = 1;
                } else {
                    d = 0;
                }
            }
            return;
}