// Author : ysh
// 01/18/2023 Wed  8:55:19.33
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dt({{0,5,3,2,2,3,4,5,7,6,7,8,7,6,8,9,1,3,1,4,6,4,1,2,5,1}
,{5,0,2,3,4,2,1,1,3,2,3,4,2,1,4,5,6,3,4,2,2,1,5,3,2,4}
,{3,2,0,1,2,1,2,3,5,4,5,6,4,3,6,7,4,2,2,2,4,1,3,1,3,2}
,{2,3,1,0,1,1,2,3,5,4,5,6,5,4,6,7,3,1,1,2,4,2,2,1,3,2}
,{2,4,2,1,0,2,3,4,5,5,6,7,6,5,6,7,2,1,1,2,4,3,1,2,3,2}
,{3,2,1,1,2,0,1,2,4,3,4,5,4,3,5,6,4,1,2,1,3,1,3,2,2,3}
,{4,1,2,2,3,1,0,1,3,2,3,4,3,2,4,5,5,2,3,1,2,1,4,3,1,4}
,{5,1,3,3,4,2,1,0,2,1,2,3,2,1,3,4,6,3,4,2,1,2,5,4,1,5}
,{7,3,5,5,5,4,3,2,0,1,1,2,2,2,1,2,7,4,6,3,1,4,6,6,2,7}
,{6,2,4,4,5,3,2,1,1,0,1,2,1,1,2,3,7,4,5,3,1,3,6,5,2,6}
,{7,3,5,5,6,4,3,2,1,1,0,1,1,2,1,2,8,5,6,4,2,4,7,6,3,7}
,{8,4,6,6,7,5,4,3,2,2,1,0,2,3,1,1,9,6,7,5,3,5,8,7,4,8}
,{7,2,4,5,6,4,3,2,2,1,1,2,0,1,2,3,8,5,6,4,2,3,7,5,3,6}
,{6,1,3,4,5,3,2,1,2,1,2,3,1,0,3,4,7,4,5,3,2,2,6,4,2,5}
,{8,4,6,6,6,5,4,3,1,2,1,1,2,3,0,1,8,5,7,4,2,5,7,7,3,8}
,{9,5,7,7,7,6,5,4,2,3,2,1,3,4,1,0,9,6,8,5,3,6,8,8,4,9}
,{1,6,4,3,2,4,5,6,7,7,8,9,8,7,8,9,0,3,2,4,6,5,1,3,5,2}
,{3,3,2,1,1,1,2,3,4,4,5,6,5,4,5,6,3,0,2,1,3,2,2,2,2,3}
,{1,4,2,1,1,2,3,4,6,5,6,7,6,5,7,8,2,2,0,3,5,3,1,1,4,1}
,{4,2,2,2,2,1,1,2,3,3,4,5,4,3,4,5,4,1,3,0,2,2,3,3,1,4}
,{6,2,4,4,4,3,2,1,1,1,2,3,2,2,2,3,6,3,5,2,0,3,5,5,1,6}
,{4,1,1,2,3,1,1,2,4,3,4,5,3,2,5,6,5,2,3,2,3,0,4,2,2,3}
,{1,5,3,2,1,3,4,5,6,6,7,8,7,6,7,8,1,2,1,3,5,4,0,2,4,2}
,{2,3,1,1,2,2,3,4,6,5,6,7,5,4,7,8,3,2,1,3,5,2,2,0,4,1}
,{5,2,3,3,3,2,1,1,2,2,3,4,3,2,3,4,5,2,4,1,1,2,4,4,0,5}
,{1,4,2,2,2,3,4,5,7,6,7,8,6,5,8,9,2,3,1,4,6,3,2,1,5,0}});
const int xx[] = {-1,-1,0,0,1,1};
const int yy[] = {0,1,1,-1,0,-1};
void init() {
    dt.resize(26,vector<int>(26,INT_MAX));
    vector<pair<int,int>>lo(26);
    const string key[] = {"QWERTYUIOP","ASDFGHJKL","ZXCVBNM"};
    for(int i = 0;i<=2;i++) {
        int n = key[i].size();
        for(int j = 0;j<n;j++) {
            lo.at(key[i].at(j) - 'A') = {i,j};
        }
    }
    // for(int i = 0;i<26;i++) {
    //     cout<<(char) (i + 'A')<<" "<<lo.at(i).first<<" "<<lo.at(i).second<<"\n";
    // }
    vector<bool>mark(26);
    function<void(int,int,int,int)> check = [&] (int from,int x,int y,int sig) {
        int now = key[x].at(y) - 'A';
        if(dt.at(from).at(now) < sig) return;
        dt.at(now).at(from) = dt.at(from).at(now) = min(sig,dt.at(from).at(now));
        for(int i = 0;i<=5;i++) {
            int nx = x + xx[i];
            int ny = y + yy[i];
            if(nx < 0 || ny < 0 || nx > 2 || key[nx].size() <= ny) continue;
            check(from,nx,ny,sig + 1);
        }
        return;
    };
    for(int i = 0;i<26;i++) {
        mark = vector<bool>(26);
        check(i,lo.at(i).first,lo.at(i).second,0);
    }
    // for(int i = 0;i<26;i++) {
    //     cerr<<",{";
    //     for(int j = 0;j<26;j++) {
    //         cerr<<dt.at(i).at(j)<<",";
    //     }
    //     cerr<<"\b}\n";
    // }
    return;
}
deque<int>v;
int left(int a,int b) {
    if(a > b) swap(a,b);
    if(a == 0) {
        return dt.at('F' - 'A').at(v.at(b));
    }
    return dt.at(v.at(a)).at(v.at(b));
}
int right(int a,int b) {
    if(a > b) swap(a,b);
    if(a == 0) {
        return dt.at('J' - 'A').at(v.at(b));
    }
    return dt.at(v.at(a)).at(v.at(b));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // init();
    int n;cin>>n;
    v.resize(n);
    // string a;cin>>a;
    for(int &i : v) {
        char tmp;cin>>tmp;
        i = tmp - 'A';
    }
    v.push_front(0);
    vector<vector<int>>f(n + 1,vector<int>(26,1e5));
    // vector<vector<int>>left(n + 1,vector<int>(n + 1)),right(n + 1,vector<int>(n + 1));
    // for(int i = 0;i<=n;i++) {
    //     for(int j = i + 1;j<=n;j++) {
    //         if(i == 0) {
    //             left(i).at(j) = left(j).at(i) = dt.at('F' - 'A').at(v.at(j));
    //             right(i).at(j) = right(j).at(i) = dt.at('J' - 'A').at(v.at(j));
    //             continue;
    //         }
    //         left(i).at(j) = left(j).at(i) = dt.at(v.at(i)).at(v.at(j));
    //         right(i).at(j) = right(j).at(i) = dt.at(v.at(i)).at(v.at(j));
    //     }
    // }
    f.at(0).at('J' - 'A') = 0;
    f.at(0).at('F' - 'A') = 0;
    f.at(1).at('J' - 'A') = dt.at('F' - 'A').at(v.at(1));
    f.at(1).at('F' - 'A') = dt.at('J' - 'A').at(v.at(1));
    for(int i = 1;i<n;i++) {
        for(int j = 0;j<26;j++) {
            f.at(i + 1).at(j) = min({f.at(i).at(j) + dt.at(v.at(i)).at(v.at(i + 1)),f.at(i + 1).at(j)});
            f.at(i + 1).at(v.at(i)) = min({f.at(i).at(j) + dt.at(j).at(v.at(i + 1)),f.at(i + 1).at(v.at(i))});
        }
    }
    // for(auto &i : f) {
    //     for(auto &j : i) {
    //         if(j == 1e5) {
    //             cout<<". ";
    //             continue;
    //         }
    //         cout<<j<<" ";
    //     }
    //     cout<<"\n";
    // }
    int mmin = INT_MAX;
    for(int i = 0;i<26;i++) {
        mmin = min({f.at(n).at(i),mmin});
    }
    cout<<mmin;
    return 0;
}
