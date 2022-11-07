// Author : ysh
// 11/06/2022 Sun 16:23:36.33
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int m;cin>>m;
        vector<pair<pair<int,int>,int>>f;
        for(int i = 0;i<m;i++) {
            int a,b,c;cin>>a>>b>>c;
            f.push_back({{a,b},c});
        }
        vector<vector<int>>v(m);
        for(int i = 0;i<m;i++) {
            for(int j = i + 1;j<m;j++) {
                if((f.at(i).second + f.at(j).second) * (f.at(i).second + f.at(j).second) >= (f.at(i).first.first - f.at(j).first.first) * (f.at(i).first.first - f.at(j).first.first) + (f.at(i).first.second - f.at(j).first.second) * (f.at(i).first.second - f.at(j).first.second)) {
                    v.at(i).push_back(j);
                    v.at(j).push_back(i);
                }
            }
        }
        vector<bool>mark(m);
        function<int(int,int)> check = [&] (int last,int x) {
            if(mark.at(x)) return 1;
            mark.at(x) = 1;
            int ans = 0;
            for(int &i : v.at(x)) if(i != last) ans = ans + check(x,i);
            return ans;
        };
        cout<<(check(-1,0) >> 1)<<"\n";
    }
    return 0;
}