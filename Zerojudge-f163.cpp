// Author : ysh
// 10/19/2022 Wed 14:20:46.17
// NA (90%)
#include<bits/stdc++.h>
using namespace std;
#include<fast>
#define p system("pause");
struct box{
    int no = 0;
    int num = 0;
    box* up;
    box* left;
    box* right;
    int wei = 0;
};
int count(box*,box*);
int maketree(box*,box*);
int check(box*,box*,int);
int main() {
    //freopen("3.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = readint(),m = readint();
    box b[(n<<1)+5];
    queue<int>f;
    for(int i = n;i<=((n<<1) - 1);i++) {
        b[i].wei = readint();
        b[i].num = i;
    }
    int tmp;
   for(int i = 0;i<m;i++) {
       tmp = readint();
       f.push(tmp);
    }
    int tmpa,tmpb;
    for(int i = 1;i<n;i++) {
        tmp = readint();
        b[tmp].no = tmp;
        tmpa = readint();tmpb = readint();
        b[tmp].left = &b[tmpa];
        b[tmp].right = &b[tmpb];
        b[tmpa].up = &b[tmp];
        b[tmpb].up = &b[tmp];
    }
   maketree(&b[1],b);
   /*
    for(auto i : b) {
        if(i.no == 0) printf("no %d,num %d,wei %d\n",i.no,i.num,i.wei);
        else printf("no %d,left %d,right %d,num %d,wei %d\n",i.no,i.left - &b[0],i.right - &b[0],i.num,i.wei);
    }
    */
    while(!f.empty()) {
        //printf("%d",f.front());
        cout<<check(&b[1],b,f.front())<<" ";f.pop();
        //printf("\n");
    }
    return 0;
}
int count(box* now,box* b) {
    if(now->no == 0) return now->wei;
    return count(now->left,b) + count(now->right,b);
}
int maketree(box* now,box* b) {
    if(now->no == 0) return now->wei;
    return now->wei = maketree(now->left,b) + maketree(now->right,b);
}
int check(box* now,box* b,int wei) {
    //printf("->%d",(now->no == 0 ? now->num : now->no));
    if(now->no == 0) {
        now->wei += wei;
        return now->num;
    } else {
        now->wei += wei;
        if(now->left->wei > now->right->wei) {
            return check(now->right,b,wei);
        } else {
            return check(now->left,b,wei);
        }
    }
}