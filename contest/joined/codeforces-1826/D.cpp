// Author : ysh
// 05/05/2023 Fri 23:53:57.01
#include<bits/stdc++.h>
using namespace std;
vector<int>f;
int dt(pair<int,int>&a,pair<int,int>b,bool c) {
    if(c) return a.first - b.first;
    if(!c) return a.first - (b.second - a.second) - b.first;
}
int check(int l,int r) {
    int n = r + 1;
    vector<pair<int,int>>now(3);
    int ans = 0;
    for(int i = 0;i<=2;i++) {
        now.at(i) = {f.at(i),i};
    }
    ans = f.at(0) + f.at(1) + f.at(2) - 2;
    for(int i = 3;i<n;i++) {
        int mmax,aans;mmax = -1,aans = -1;
        sort(now.begin(),now.end(),[] (pair<int,int>&a,pair<int,int>&b) {
            return a.second < b.second;
        });
        for(int j = 0;j<=2;j++) {
            if(dt(now.at(j),{f.at(i),i},j != 0) <= 0) {
                if(-dt(now.at(j),{f.at(i),i},j != 0) > mmax) {
                    mmax = -dt(now.at(j),{f.at(i),i},j != 0);
                    aans = j;
                }
                if(aans != -1 && -dt(now.at(j),{f.at(i),i},j != 0) == mmax && now.at(j).second > now.at(aans).second) {
                    aans = j;
                }
            }
        }
        if(aans == -1) continue;
        now.at(aans) = {f.at(i),i};
        ans = max(ans,now.at(0).first + now.at(1).first + now.at(2).first - (max({now.at(0).second,now.at(1).second,now.at(2).second}) - min({now.at(0).second,now.at(1).second,now.at(2).second})));
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    for(int i = 0;i<n;i++) {
        int r;cin>>r;
        f = vector<int>(r);
        for(int &i : f) {
            cin>>i;
        }
        cout<<check(0,r - 1)<<"\n";
    }
    return 0;
}