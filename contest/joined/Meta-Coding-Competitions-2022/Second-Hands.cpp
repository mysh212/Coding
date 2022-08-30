// Author : ysh
// 08/28/2022 Sun 23:11:43.44
// https://www.facebook.com/codingcompetitions/hacker-cup/2022/qualification-round/problems/A
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    function<void()> check = [&] () {
        int a,b;cin>>a>>b;
        if((b << 1) < a) {
            for(int i = 0;i<a;i++) cin>>b;
            cout<<"NO"<<"\n";
            return;
        }
        vector<int>f(a);
        map<int,int>m;
        for(int &i : f) {
            cin>>i;
            m[i]++;
        }
        for(auto i : m) {
            if(i.second > 2) {
                cout<<"NO\n";
                return;
            }
        }
        cout<<"YES\n";
        return;
    };
    int n;cin>>n;
    for(int i = 1;i<=n;i++) {
        cout<<"Case #"<<i<<": ";
        check();
    }
    return 0;
}