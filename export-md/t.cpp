// Author : ysh
// 2024/01/23 Tue 22:51:53
#include<bits/stdc++.h>
#include<testlib.h>
using namespace std;
int main(int ac,char* as[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    registerGen(ac,as,1);
    int n = atoi(as[1]);
    int m = atoi(as[2]);
    int k = atoi(as[3]);
    int l = atoi(as[4]) & 1;

    map<pair<int,int>,int>r;
    if(l == 1 && k >= (n - 1)) {
        // k = k - (n - 1);
        vector<int>f(n);
        iota(f.begin(),f.end(),1);
        shuffle(f.begin(),f.end());

        for(int i = 1;i<n;i++) {
            r.insert({{f.at(i - 1),f.at(i)},rnd.next(0,int(1e9))});
        }
    }

    while(r.size() < k) {
        int a,b;
        a = rnd.next(1,n);
        b = rnd.next(1,n);
        if(r.find({a,b}) == r.end()) r.insert({{a,b},rnd.next(0,int(1e9))});
    }

    map<int,int>mark;
    while(mark.size() < m) {
        int now = rnd.next(1,n);
        if(mark.find(now) == mark.end()) mark.insert({now,rnd.next(1,int(1e9))});
    }

    vector<pair<pair<int,int>,int>>tmp(r.begin(),r.end());
    shuffle(tmp.begin(),tmp.end());

    cout<<n<<" "<<m<<" "<<k<<"\n";
    for(auto &i : mark) {
        cout<<"+ "<<i.first<<" "<<i.second<<"\n";
    }
    for(auto &i : tmp) {
        cout<<"- "<<i.first.first<<" "<<i.first.second<<" "<<i.second<<"\n";
    }
    return 0;
}