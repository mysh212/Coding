#include<bits/stdc++.h>
using namespace std;
int a,b;
#define int long long
bool no = 0;
const int xx[] = {1,1,1,0,-1,-1,-1,0};
const int yy[] = {1,0,-1,-1,-1,0,1,1};
vector<vector<bool>>mark;
int check(int x,int y,int c,int d,int now) {

}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    string tmp;getline(cin,tmp);
    int n;n = stoi(tmp);
    while(n--) {
        int cb,cw;cb=cw=0;
        vector<vector<int>>f(6,vector<int>(6));
        for(int i = 0;i<6;i++) {
            string a;getline(cin,a);
            for(int j = 0;j<6;j++) {
                if(a[i] == 'B') {
                    cb++;
                    f[i][j] = 1;
                }
                if(a[i] == 'W') {
                    cw++;
                    f[i][j] = -1;
                }
            }
        }
        if(n != 0) getline(cin,tmp);
        if(cb == cw + 1 || cb == cw) printf("%c",'Y');
        else printf("%c",'N');
    }
    return 0;
}
