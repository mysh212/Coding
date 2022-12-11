// Author : ysh
// 12/09/2022 Fri 16:29:56.33
// https://tioj.ck.tp.edu.tw/problems/2259
#include<bits/stdc++.h>
using namespace std;
const int R = (int) 1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<vector<int>>from({{1,3}, {6}, {1,3}, {2,4,5,7}, {2,4,5,7}, {0,1,3,8}, {2,4,5,7}, {6}, {2,4}});
    vector<vector<int>>f(2,vector<int>(9));
    f.at(1).at(0) = f.at(1).at(2) = 1;
    for(int i = 0;i<n - 1;i++) {
        int p = i & 1;
        for(int j = 0;j<=8;j++) {
            f.at(p).at(j) = 0;
            for(int &i : from.at(j)) {
                f.at(p).at(j) += f.at(!p).at(i);
            }
        }
    for(auto i : f) {for(int &j : i) cerr<<j<<" "; cerr<<"\n";}
    }
    cout<<(f.at((n & 1)).at(1) + f.at((n & 1)).at(3)) % R;
    return 0;
}