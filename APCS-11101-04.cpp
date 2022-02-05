// Author : ysh
// 01/31/2022 Mon 14:11:36.51
// https://zerojudge.tw/ShowProblem?problemid=h084
#include<bits/stdc++.h>
using namespace std;
inline bool check(int* c,int* d,int &a,int &b,int now) {
    bool p;
    int e[a],k = 0,tmp = 0;
    if(c[0] >= now) {
        tmp++;
        p = true;
    } else {
        p = false;
    }
    for(int i = 1;i<a;i++) {
        if(p == true) {
            if(c[i] >= now) {
                tmp++;
            } else {
                e[k] = tmp;
                tmp = 0;
                p = false;
                k++;
            }
        } else {
            if(c[i] >= now) {
                tmp++;
                p = true;
            }
        }
    }
    if(tmp != 0) {
        e[k] = tmp;
        k++;
    }
    /*
    cout<<now<<" ";
    for(int i = 0;i<k;i++) {
        cout<<e[i]<<" ";
    }
    */
    //printf("[%d]",d[0]);
    //cout<<"\n";
    int ek = 0;
    p = 1;
    for(int i = 0;i<b;i++) {
        bool ok = 1;
        bool bk = 0;
        while(1) {
            if(ek == k) {
                p = 0;
                bk = 1;
                break;
            }
            if(e[ek]>=d[i]) {
                e[ek] = e[ek] - d[i];
                break;
            } else {
                ek++;
                continue;
            }
        }
        if(bk == 1) break;
    }
    //printf("check(%d) = %d\n",now,(int) p);
    if(p == 1) return 1;
    return 0;
}
int search(int* c,int* d,int &a,int &b,int mmin,int mmax) {
    if(mmin == mmax - 1||mmin == mmax) {
        if(check(c,d,a,b,mmax)) return mmax;
        return mmin;
    }
    int mid = (mmin + mmax) >> 1;
    bool tmp = check(c,d,a,b,mid);
    if(tmp == 0) {
        //printf("search(%d,%d)\n",mmin,mid);
        return search(c,d,a,b,mmin,mid);
    }
    if(tmp) {
        //printf("search(%d,%d)\n",mid+1,mmax);
        return search(c,d,a,b,mid,mmax);
    }
    return mid;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int c[a],d[b];
    int mmax = 0;
    for(int &i : c) {
        cin>>i;
        mmax = max(mmax,i);
    }
    for(int &i : d) {
        cin>>i;
    }
    cout<<search(c,d,a,b,0,mmax);
    return 0;
}