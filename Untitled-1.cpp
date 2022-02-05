#include<bits/stdc++.h>
using namespace std;
void fast(int a,int b,int mmax,int n) {
    int na = ((int) pow(a,2) - ((int) pow(b,2))) % 1000000007;
    int nb = (a * b * 2) % 1000000007;
    //printf("%d %d %d\n",na,nb,mmax);
    if(n == mmax) return;
    fast(na,nb,mmax,n+1);
    printf("%d==>%d,%d\n",n,na,nb);
    return;
}
inline void times(int a,int b,int aa,int bb) {
    int na = ((int) a*aa - ((int) b*bb)) % 1000000007;
    int nb = ((b * aa + a * bb)) % 1000000007;
    return;
}
inline void positive(int &a,int &b) {
    if(a < 0) a += 1000000007;
    if(b < 0) b += 1000000007;
    return;
}
int main() {
    int a,b,c,d;cin>>a>>b>>c>>d;
    fast(a,b,c,d);
}