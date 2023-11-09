// Author : ysh
// 2023/10/12 Thu 23:18:29
// https://judge.tcirc.tw/ShowProblem?problemid=d064
#include<stdio.h> 
using namespace std;

inline char readchar() {
 const int S = 1<<20;
 static char buf[S], *p = buf, *q = buf;
 if(p == q && (q = (p=buf)+fread(buf,1,S,stdin)) == buf) return EOF;
 return *p++;
}
bool __flag = 0;
inline int readint() {
 int x = 0, c = readchar(), neg = false;
 __flag = 1;
 while(('0' > c || c > '9') && c!='-' && c!=EOF) c = readchar();
 if(c == '-') neg = true, c = readchar();
 while('0' <= c && c <= '9') x = x*10 + (c^'0'), __flag = 0,c = readchar();
 if(neg) x = -x;
 return x;
}
int f[int(1e6) + 2];
int main() {
    long long ans = 0;

    int n;n = readint();
    // int m = n;
    while(n--) {
        int tmp;tmp = readint();
        for(int a = int(1e6) + 1;a >= 0;a = (a & (a + 1)) - 1) {
            ans = ans + f[a];
        }
        for(int a = tmp;a >= 0;a = (a & (a + 1)) - 1) {
            ans = ans - f[a];
        }
        for(int a = tmp,b = 1;a < int(1e6) + 2;a = a | (a + 1)) {
            f[a] += b;
        }
    }

    printf("%d\n",ans);
    return 0;
}
