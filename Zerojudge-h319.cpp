// Author : ysh
// 04/02/2022 Sat 12:42:12.17
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct box{
    box* l;
    box* r;
    bool s = 1;
    int n = -1;
};
box* fr(box* a,box* b) {
    if(b->s == 1) return b;
    if(b->r->s != 1) {
        return b->r = fr(a,b->r);
    } else {
        return b->r;
    }
}
int input() {
    int ans = 0;
    while(1) {
        int a = (int) getchar();
        // cerr<<(int) a;
        if((char) a == ' ' || (char) a == '\n' || (char) a == EOF) break;
        ans = ans * 10 + (a - 48);
    }
    return ans;
}
char inputchar() {
    char ans = getchar();
    getchar();
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a = input(),b = input();
    box c[a + 2];
    c[a+1].r = &c[a+1];
    c[0].r = &c[1];
    for(int i = 1;i<=a;i++) {
        c[i].n = i;
        c[i].l = &c[i - 1];
        c[i].r = &c[i + 1];
    }
    int tmp;
    while(b--) {
        tmp = input();
        if(inputchar() == '-') {
            if(c[tmp].s == 0) continue;
            c[tmp].r->l = c[tmp].l;
            c[tmp].l->r = c[tmp].r;
            c[tmp].s = 0;
            continue;
        }
        cout<<fr(c,&c[tmp])->n<<"\n";
    }
}