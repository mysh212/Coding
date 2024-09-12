// Author : ysh
// 2024/09/07 Sat 10:43:47
#include<bits/stdc++.h>
using namespace std;
#include<slow>
vector<int>pre;
int n;
vector<bool>mark;
vector<int>f;
vector<int> check(int x,int now) {
    // debug(x,now,mark);
    if(x == n) return vector<int>({now});
    for(int i = 0;i<n;i++) {
        if(mark.at(i)) continue;
        if(f.at(i) % now == 0 && f.at(i) / now <= 100) {
            mark.at(i) = 1;
            auto ans = check(x + 1,f.at(i) / now);
            if(ans.size() != 1 || ans.at(0) != -1) return ans.push_back(now),ans;
            mark.at(i) = 0;
        }
    }
    return {-1};
}
vector<int>ck() {
    int now = *min_element(all(f));
    re(i,1,100) {
        // if(i * i > now) return {-1};
        // if(now % i != 0) continue;
        // debug(i);
        auto ans = check(0,i);
        // debug(ans,mark);
        if(!(ans.size() == 1 && ans.at(0) == -1)) return ans;
        // return ans;
        // ans = check(0,now / i);

    }
    return {-1};
}
bitset<10001>s;
vc<int>prime;
void init() {
    re(i,2,10000 + 1) {
        if(!s.test(i)) prime.pb(i);
        for(int j = i * i;j<=10000;j = j + i) {
            s.set(j);
        }
    }
    return;
}
vector<int> walk(vector<pair<int,int>>f,int x = 0,int sig = 1) {
    if(x == f.size()) return {sig};
    int a,b;
    a = f.at(x).first;
    b = f.at(x).second;
    int last = 1;
    vc<int>ans;
    repo(&i,walk(f,x + 1,1)) ans.push_back(i);
    vc<int>aans(all(ans));
    re(i,b) {
        last = last * a;
        repo(&i,ans) aans.push_back(i * last);
    }
    return aans;
}
void pt() {
    repo(i,f) {
        vc<pair<int,int>>ans;
        repo(&j,prime) {
            int now = 0;
            while(i % j == 0) i = i / j,now++;
            if(now != 0) ans.push_back({j,now});
        }
        repo(i,walk(ans)) pre.push_back(i);
    }
    sort(all(pre));
    pre.resize(unique(all(pre)) - pre.begin());
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;n--;
    f = vc<int>(n);
    mark = vc<bool>(n);
    cin>>f;

    // init();pt();
    // debug(pre);
    auto ans = ck();
    if(ans.size() == 1 && ans.at(0) == -1) return outl("No"),0;

    outl("Yes");
    outl(ans);
}