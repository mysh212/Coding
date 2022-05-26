// Author : ysh
// 05/01/2022 Sun 16:30:04.98
#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
vector<int>f[MAX];
bitset<MAX>s;
long long ans = 0;
int check(int,int);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,tmp,tmpt;cin>>n;
    if(n == 0) return 0;
    s.set();
    for(int i = 0;i<n;i++) {
        cin>>tmp;
        for(int j = 0;j<tmp;j++) {
            cin>>tmpt;
            f[i].push_back(--tmpt);
            s.reset(tmpt);
        }
    }
    int start = s._Find_first();
    int ans = check(start,0);
    cout<<start + 1<<"\n"<<::ans;
    return 0;
}
int check(int now,int x) {
    //printf("[%d]",now);
    int mmax = 0;
    int tmp;
    if(f[now].empty()) return 0;
    for(int i : f[now]) {
        mmax = max(mmax,check(i,x + 1));
    }
    ::ans += (mmax + 1);
    //printf("(%d)",mmax + 1);
    return mmax + 1;
}