// Author : ysh
// 2023/06/27 Tue 09:23:13
// https://neoj.sprout.tw/problem/293/
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<vector<int>>f(n);
        for(int i = 1;i<n;i++) {
            int a,b;cin>>a>>b;
            f.at(a).push_back(b);
            f.at(b).push_back(a);
        }

        vector<int>v(n);
        function<int(int,int)> check = [&] (int last,int x) {
            int now = 0;
            for(int &i : f.at(x)) {
                if(i == last) continue;
                int tmp = check(x,i);
                now = now + tmp;
                v.at(x) = max(v.at(x),tmp);
            }
            v.at(x) = max(v.at(x),n - (now + 1));
            return now + 1;
        };

        int ans = -1,mmin = INT_MAX;
        check(-1,0);
        cout<<int(min_element(v.begin(),v.end()) - v.begin())<<"\n";
    }
    return 0;
}