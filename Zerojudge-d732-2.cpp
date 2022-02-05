// Author : ysh
// 01/31/2022 Mon  9:11:43.87
// TLE
#include<bits/stdc++.h>
using namespace std;
int search(int* c,int &a,int mmin,int mmax) {
    if(mmin == mmax) {
        if(c[mmin] == a) return mmin;
        return -1;
    }
    int mid = (mmax - mmin) * (a - c[mmin]) / (c[mmax] - c[mmin]) + mmin;
    if(c[mid] > a) {
        //printf("search(%d,%d)\n",mmin,mid);
        return search(c,a,mmin,mid);
    }
    if(c[mid] < a) {
        //printf("search(%d,%d)\n",mid+1,mmax);
        return search(c,a,mid+1,mmax);
    }
    return mid;
}
/*
    ^
    |      /
    |    /
    |  /
    |/
    |------------->
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int c[a],d[b];
    for(int &i : c) {
        cin>>i;
    }
    int tmp;
    for(int i = 1;i<=b;i++) {
        cin>>tmp;
        cout<<search(c,tmp,0,a - 1) + 1<<"\n";
    }
    return 0;
}