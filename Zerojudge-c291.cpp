// Author : ysh
// 01/12/2022 Wed 14:22:35.18
#include<bits/stdc++.h>
using namespace std;
int r = 1;
int check(int*,int*,int,int,int);
void pc(int*,int);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int a[n] = {};
    for(int i = 0;i<n;i++) {
        cin>>a[i];
    }
    int mark[n] = {};
    for(int i = 0;i<n;i++) {
        int tmp = check(a,mark,i,0,1);
        //printf("[%d%]==============\n",r);
    }
    cout<<r - 1;
}
int check(int* a,int* mark,int n,int t,int times) {
    //pc(mark,3);
    if(mark[n] != 0&&times == 1) return 0;
    if(mark[n] != 0&&mark[n] != r) return mark[n];
    if(mark[n] != 0&&mark[n] == r) {
        r++;
        //printf("[%d]\n",r);
        return r-1;
    }
    mark[n] = r;
    return mark[n] = check(a,mark,a[n],1,0);
}
void pc(int* a,int n) {
    for(int i = 0;i<n;i++) {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    return;
}