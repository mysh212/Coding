// Author : ysh
// 2023/09/03 Sun 13:44:56
// https://codeforces.com/gym/103373/problem/B
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

const int N = (int) 1e3;

vector<int>prime;
bitset<N + 1>s;
void init() {
    for(int i = 2;i<N;i++) {
        if(s.test(i)) continue;
        prime.push_back(i);
        for(int j = i * i;j <= N;j = j + i) {
            s.set(j);
        }
    }
    return;
}
vector<pair<int,int>> check(int x) {
    vector<pair<int,int>>ans;
    for(int &i : prime) {
        if(i * i > x) break;
        int tmp = 0;
        while(x % i == 0) tmp++,x = x / i;
        if(tmp != 0) ans.push_back(make_pair(i,tmp));
    }
    if(x != 1) ans.push_back({x,1});
    return ans;
}
long long sum(vector<pair<int,int>>x) {
    long long ans = 1;
    for(auto &i : x) {
        int tmp = 0;
        int now = 1;
        do {
            tmp = tmp + now;
            now = now * i.first;
        } while(i.second--);
        ans = ans * tmp;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    int n;cin>>n;
    while(n--) {
        int tmp;cin>>tmp;
        int ans = sum(check(tmp)) - tmp;
        if(ans > tmp) cout<<"abundant";
        if(ans == tmp) cout<<"perfect";
        if(ans < tmp) cout<<"deficient";
        // debug(ans);
        cout<<"\n";
    }
    return 0;
}