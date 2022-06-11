// Author : ysh
// 06/01/2022 Wed  9:11:21.82
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int m;cin>>m;
        map<int,int>s;
        for(int i = 0;i<m;i++) {
            int tmp;cin>>tmp;
            s[tmp]++;
        }
        bool c = 0;
        for(auto i : s) {
            if(i.second == 1) {
                cout<<-1<<"\n";
                c = 1;
                break;
            }
        }
        if(c) continue;
        int j = 0;
        for(auto i : s) {
            cout<<j+i.second<<" ";
            for(int k = j + 1,len = j + i.second;k<len;k++) {
                cout<<k<<" ";
            }
            j = j+i.second;
        }
        cout<<"\n";
    }
    return 0;
}