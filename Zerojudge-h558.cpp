// Author : ysh
// 01/18/2023 Wed  8:55:19.33
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dt;
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
    //     for(int j = 0;j<26;j++) {
    //         cerr<<dt.at(i).at(j)<<" ";
    //     }
    //     cerr<<"\n";
    // }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    int n;cin>>n;
    // string a;cin>>a;
    deque<int>v(n);
    for(int &i : v) {
        char tmp;cin>>tmp;
        i = tmp - 'A';
    }
    v.push_front(0);
    vector<vector<long long>>f(n + 1,vector<long long>(n + 1,INT_MAX));
    vector<vector<int>>left(n + 1,vector<int>(n + 1)),right(n + 1,vector<int>(n + 1));
    for(int i = 0;i<=n;i++) {
        for(int j = i + 1;j<=n;j++) {
            if(i == 0) {
                left.at(i).at(j) = left.at(j).at(i) = dt.at('F' - 'A').at(v.at(j));
                right.at(i).at(j) = right.at(j).at(i) = dt.at('J' - 'A').at(v.at(j));
                continue;
            }
            left.at(i).at(j) = left.at(j).at(i) = dt.at(v.at(i)).at(v.at(j));
            right.at(i).at(j) = right.at(j).at(i) = dt.at(v.at(i)).at(v.at(j));
        }
    }
    f.at(0).at(0) = 0;
    for(int i = 1;i<=n;i++) {
        for(int j = 0;j<=n;j++) {
            f.at(i).at(j) = min({f.at(i - 1).at(j) + left.at(i - 1).at(i),f.at(i).at(j)});
            f.at(i).at(i - 1) = min(f.at(j).at(i - 1) + left.at(j).at(i),f.at(i).at(i - 1));
            f.at(j).at(i) = min({f.at(j).at(i - 1) + right.at(i - 1).at(i),f.at(j).at(i)});
            f.at(i - 1).at(i) = min(f.at(i - 1).at(j) + right.at(j).at(i),f.at(i - 1).at(i));
        }
    }
    // for(auto &i : f) {
    //     for(auto &j : i) {
    //         cout<<j<<" ";
    //     }
    //     cout<<"\n";
    // }
    long long mmin = INT_MAX;
    for(int i = 0;i<=n;i++) {
        mmin = min({f.at(n).at(i),f.at(i).at(n),mmin});
    }
    cout<<mmin * 1LL;
    return 0;
}
