// Author : ysh
// 07/18/2022 Mon  7:04:23

#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;cin>>a;
    vector<int>m(a);
    queue<int>q;
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
        // m.insert({i,0});
    }
    int all = m.size();
    int now = 0;
    int l = 0;
    int mmax = 0;
    for(int i : f) {
        q.push(i);
        m[i]++;
        l++;
        if(m[i] == 2) {
            now++;
        }
        // cout<<now<<" "<<l<<"\n";
        while(now != 0) {
            int left = q.front();q.pop();
            m[left]--;
            if(m[left] == 1) {
                now--;
            }
            l--;
            // if(now == 0) mmax = max(mmax,l);
        }
        // cout<<l<<" ";
        if(now == 0) mmax = max(mmax,l);
    }
    cout<<mmax;
    return 0;
}