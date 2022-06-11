// Author : ysh
// 06/02/2022 Thu 17:52:56.28
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a,b;
    while(cin>>a>>b) {
        if(a == "0" && b == "0") break;
        vector<int>aa,bb;
        for(int i = a.size() - 1;i>=0;i--) {
            aa.push_back(stoi(a.substr(i,1)));
        }
        for(int i = b.size() - 1;i>=0;i--) {
            bb.push_back(stoi(b.substr(i,1)));
        }
        int last = 0;
        int ans = 0;
        while(!(aa.empty()&&bb.empty())) {
            int nowa,nowb;nowa=nowb=0;
            if(!aa.empty()) {
                nowa = aa.back();
                aa.pop_back();
            }
            if(!bb.empty()) {
                nowb = bb.back();
                bb.pop_back();
            }
            // cout<<nowa<<" "<<nowb;
            if(nowa + nowb + last >= 10) {
                ans++;
                last = 1;
                continue;
            }
            last = 0;
        }
        if(ans == 0) cout<<"No carry operation.\n";
        else if(ans == 1) cout<<"1 carry operation.\n";
        else cout<<ans<<" carry operations.\n";
    }
    return 0;
}