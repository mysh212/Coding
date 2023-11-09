// Author : ysh
// 2023/09/21 Thu 23:50:35
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        string a;cin>>a;
        vector<int>f;
        int last = 0;
        for(char i : a) {
            if(i == 'B') {
                f.push_back(last);
                last = 0;
                continue;
            }
            last++;
        }
        f.push_back(last);
        if(f.empty()) {
            cout<<0<<"\n";
            continue;
        }
        if(f.size() == 1) {
            cout<<0<<"\n";
            continue;
        }

        vector<vector<int>>mark(2,vector<int>(f.size() - 1));
        mark.at(0).at(0) = mark.at(1).at(0) = f.at(0);
        mark.at(1).at(0) = max(mark.at(1).at(0),f.at(1));
        for(int i = 0,len = f.size() - 2;i<len;i++) {
            mark.at(0).at(i + 1) = max(mark.at(0).at(i) + f.at(i + 1),mark.at(1).at(i));
            debug(mark.at(1).at(i),mark.at(0).at(i) + f.at(i + 1),mark.at(0).at(i + 1));
            mark.at(1).at(i + 1) = max({mark.at(0).at(i + 1),mark.at(1).at(i) + f.at(i + 2)});
        }
        debug(f,mark);
        cout<<mark.at(1).at(f.size() - 1 - 1)<<"\n";
    }
    return 0;
}