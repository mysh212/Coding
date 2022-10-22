// Author : ysh
// 10/20/2022 Thu 11:21:50.95
#include<bits/stdc++.h>
using namespace std;
vector<bool>big({1,0,1,0,1,0,1,1,0,1,0,1});
inline bool abba(string a,string b) {
    string aa = a + b;
    string bb = aa;
    reverse(aa.begin(),aa.end());
    if(aa == bb) return 1;
    return 0;
}
inline bool test(string yy,string a,string b) {
    int y = stoi(yy);
    int m = stoi(a);
    int d = stoi(b);
    if(m >= 1 && m <= 12) {
        if(m == 2) {
            if(y & 3 == 0) {
                if(y % 100 == 0) {
                    if(y % 400 == 0) {
                        if(d >= 1 && d <= 29) {
                            return 1;
                        }
                    }
                    if(d >= 1 && d <= 28) {
                        return 1;
                    }
                }
                if(d >= 1 && d <= 29) {
                    return 1;
                }
            }
            if(d >= 1 && d <= 28) {
                return 1;
            }
        }
        if(big.at(m)) {
            if(d >= 1 && d <= 31) {
                return 1;
            }
        }
        if(d >= 1 && d <= 30) {
            return 1;
        }
    }
    return 0;
}
void check(string &n) {
    int ans = 0;
    string yy = n;
    int y = stoi(n);
    reverse(n.begin(),n.end());
    int now = n.size();
    while(now--) {
        n = yy.substr(0,now);
        if(!abba(yy,n)) break;
        int r = yy.size() + n.size();
        string now = yy + n;
        for(int i = 1;i<r;i++) {
            for(int j = 1;i + j < r;j++) {
                if(test())
            }
        }
    }
    cout<<ans<<"\n";
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        string r;cin>>r;
        check(r);
    }
    return 0;
}