// Author : ysh
// 02/23/2023 Thu 13:39:43.54
#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>>f;
vector<int>now;
void log() {
    int up = 0;
    for(int i = 0;i<5;i++) {
        up = up * 10 + now.at(i);
    }
    int down = 0;
    for(int i = 5;i < 10;i++) {
        down = down * 10 + now.at(i);
    }
    if(up % down != 0) return;
    f.at(up / down).push_back({up,down});
    return;
}
void init(int now) {
    if(__builtin_popcount(now) == 10) return log();
    for(int i = 0;i<10;i++) {
        if(now & (1 << i)) continue;
        ::now.push_back(i);
        int tmp = now;
        now = now | (1 << i);
        init(now);
        now = tmp;
        ::now.pop_back();
    }
    return;
}
string get(int x) {
    string a = "";
    int r = 0;
    while(x != 0) a = a + ((char) ((x % 10) + '0')),x = x / 10,r++;
    while(r < 5) a = a + '0',r++;
    reverse(a.begin(),a.end());
    return a;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    f.resize(80);
    init(0);
    int n;
    while(cin>>n && n) {
        for(auto i : f.at(n)) {
            printf("%s / %s = %d\n",get(i.first).c_str(),get(i.second).c_str(),n);
        }
        if(f.at(n).empty()) printf("There are no solutions for %d.\n",n);
        printf("\n");
    }
    return 0;
}