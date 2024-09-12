// Author : ysh
// 2024/07/24 Wed 23:52:22
#include<bits/stdc++.h>
using namespace std;
#include<slow>
const int R = 8;
constexpr int N = (__lg(26) + 1) * R;
constexpr long long MAX = (1LL << N);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;cin>>a;
    int n;cin>>n;

    string b;cin>>b;
    set<string>s;
    // sort(all(a));
    function<void(string,int)> check = [&] (string now,int x) {
        // debug(x);
        if(x == 0) return s.insert(now),void();
        repo(&i,a) {
            check(now + i,x - 1);
        }
        return;
    };
    check("",n);
    debug(s);

    string now = "";
    repo(&i,b) {
        now += i;
        if(now.size() > n) now = now.substr(1);
        s.erase(now);
        debug(now);
    }

    if(!s.empty()) out(*s.begin());
    else out(-1);
    return 0;
}