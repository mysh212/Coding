// Author : ysh
// 03/04/2023 Sat 18:00:11.70
// https://tioj.ck.tp.edu.tw/problems/2052
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r;cin>>r;
    string a;cin>>a;
    map<char,int>m;
    for(char i : a) {
        m[i]++;
    }
    int n = a.size();
    
    vector<vector<int>>mark(1025,vector<int>(1025));
    for(int i = 0;i<=1024;i++) {
        mark[i][0] = 1;
        for(int j = 1;j<=i;j++) {
            mark[i][j] = (mark[i - 1][j - 1] + mark[i - 1][j]) % r;
        }
    }
    
    int ans = 0;
    for(int i = 0;i<n;i++) {
        for(auto &k : m) {
            if(k.first == a.at(i)) break;
            int tmp = 1;
            k.second--;
            int now = n - 1 - i;
            for(auto &j : m) {
                tmp = tmp * mark.at(now).at(j.second);
                tmp = tmp % r;
                now = now - j.second;
            }
            k.second++;
            ans = ans + tmp;
            ans = ans % r;
        }
        m[a.at(i)]--;
        if(m.find(a.at(i))->second == 0) m.erase(a.at(i));
    }
    cout<<ans;
    return 0;
}