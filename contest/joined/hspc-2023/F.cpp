// Author : ysh
// 04/10/2023 Mon 13:43:19.62
#include<bits/stdc++.h>
using namespace std;
int check(int a,int b) {
    int now = 1;
    a = a - 1;
    while(a--) {
        now = now * 10 + ((now % 10) + 1);
    }
    while(b--) {
        now = now * 10 + (now % 10);
    }
    return now;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>>mark(10);
    for(int i = 1;i<=9;i++) {
        for(int j = 1;j<i;j++) {
            mark.at(i).push_back(check(i - j,j));
        }
    }
    int n;cin>>n;
    while(n--) {
        int tmp;cin>>tmp;
        bool flag = 0;
        for(int j = 0;j<=9;j++) {
            for(int i = 0,len = mark.at(j).size();i<len;i++) {
                if(mark.at(j).at(i) % tmp == 0) {
                    cout<<"YES\n";
                    cout<<check(j,0)<<" "<<check(i + 1,0)<<"\n";
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) cout<<"NO\n";
    }
    return 0;
}