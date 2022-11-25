// Author : ysh
// 11/24/2022 Thu 22:15:39.54
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    for(int t = 1;t<=n;t++) {
        cout<<"Case #"<<t<<":\n";
        int mmax = 0;
        vector<string>a;
        string tmp;
        for(int i = 1;i<=10;i++) {
            cin>>tmp;
            int r;cin>>r;
            if(r > mmax) {
                mmax = r;
                a = vector<string>({tmp});
                continue;
            }
            if(r == mmax) a.push_back(tmp);
        }
        for(string &i : a) {
            cout<<i<<"\n";
        }
    }
}