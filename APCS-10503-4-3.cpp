// Author : ysh
// 06/11/2022 Sat 21:31:35.02
#include<bits/stdc++.h>
using namespace std;
struct tree{
    tree* left;
    tree* right;
    int n;
    tree(tree* left,tree* right,int n):
        left(left),right(right),n(n) {};
};
int check(int x);
vector<int>f[100000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    bitset<100000>bs;
    bs.set();
    for(int i = 0;i<n - 1;i++) {
        int a,b;cin>>a>>b;
        f[a].push_back(b);
        bs.reset(b);
    }
    int up = bs._Find_first();
    cout<<up;
    int mmmax,mmax;mmmax=mmax=INT_MIN;
    for(int i : f[up]) {
        int tmp = check(i);
        printf("check(%d) = %d\n",i,tmp);
        if(mmmax >= tmp && tmp > mmax) {
            mmax = tmp;
            continue;
        }
        if(mmmax < tmp) {
            mmax = mmmax;
            mmmax = tmp;
            continue;
        }
        if(mmax > tmp) {
            continue;
        }
    }
    cout<<mmax + mmmax;
    return 0;
}
int check(int x) {
    if(f[x].empty()) return 0;
    int mmax = INT_MIN;
    for(int i : f[x]) {
        mmax = max(mmax,check(i));
    }
    return mmax;
}