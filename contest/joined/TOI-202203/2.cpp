// Author : ysh
// 04/01/2022 Fri 18:32:18.59
// TLE
#include<bits/stdc++.h>
using namespace std;
int n;
int a[18][18] = {};
pair<int,vector<int>> check(int now,vector<bool>f,int sig,int front) {
    int mmin = INT_MAX;
    vector<int>ff;
    for(int i = n - 1;i>=0;i--) {
        if(f[i] == 0) {
            f[i] = 1;
            // printf("check(%d,%d,a[%d][%d]=%d,%d)\n",now + 1,1,front,i,sig + a[front][i],i);
            auto nnow = check(now + 1,f,sig + a[front][i],i);
            if(nnow.first < mmin) {
                mmin = nnow.first;
                ff.assign(nnow.second.begin(),nnow.second.end());
            }
            f[i] = 0;
        }
    }
    // printf("{%d} ",mmin);
    ff.push_back(front);
    if(mmin == INT_MAX) {
        // printf("[%d]\n",sig);
        return {sig,ff};
    }
    return {mmin,ff};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    vector<bool>f(n+1);
    int mmin = INT_MAX;
    vector<int>ff;
    for(int i = n - 1;i>=0;i--) {
        f[i] = 1;
        auto now = check(i,f,0,i);
        if(now.first < mmin) {
            mmin = now.first;
            ff.assign(now.second.begin(),now.second.end());
            // for(int i : now.second) cout<<i<<" ";
            // cout<<"\n";
        }
        f[i] = 0;
    }
    cout<<mmin;
    cout<<"\n";
    for(int i : ff) cout<<i + 1<<" ";return 0;
}