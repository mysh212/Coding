// Author : ysh
// 04/29/2022 Fri 21:49:04.42
#include<bits/stdc++.h>
using namespace std;
vector<int> f[100000];
// bool mark[10000][10000] = {};
int n;
int check(int,int);
int mmmax = 0;
inline pair<int,int> tb(pair<int,int>* a,int b) {
    if(b > a->first) {
        return {b,a->first};
    }
    if(b > a->second) {
        return {a->first,b};
    }
    return *a;
}
// inline bool hasroad(int x,int y) {
//     map<pair<int,int>,bool>::iterator found;
//     if(x > y) found = f.find({x,y});
//     else found = f.find({y,x});
//     if(found != f.end()) {
//         if(found->second == 1) {
//             return 1;
//         }
//     }
//     return 0;
// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    int a,b;

    // pair<int,int>aaa = {2,1};
    // aaa = tb(&aaa,3);
    // cout<<aaa.first<<" "<<aaa.second;
    // return 0;

    vector<bool>c(n);
    for(int i = 0;i<n - 1;i++) {
        cin>>a>>b;
        f[a].push_back(b);
        c[b] = 1;
    }
    int start;int xx = 0;
    for(int i = 0;i<n;i++) {
        if(!c[i]) {
            start = i;
            break;
        }
    }
    //printf("%d\n",start);
    int ck = check(start,0);
    cout<<max(ck,mmmax);
    return 0;
}
int check(int now,int x) {
    //printf("%d ",now);
    // cerr<<" "<<now;
    bool c = 0,d = 0;
    pair<int,int> a = {0,0};
    for(int i : f[now]) {
        // if(hasroad(now,i)) {
            if(c) d = 1;
            c = 1;
            // if(i > now) {
            //     f[{i,now}] = 0;
            // } else {
            //     f[{now,i}] = 0;
            // }
            int ck = check(i,0);
            a = tb(&a,ck);
        // }
    }
    //printf("\n%d : {%d,%d}\n",now,a.first,a.second);
    if(!c) return 0;
    if(d) mmmax = max(mmmax,a.first + a.second + 2);
    return a.first + 1;
}