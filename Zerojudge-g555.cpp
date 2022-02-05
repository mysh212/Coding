#include<bits/stdc++.h>
using namespace std;
void pc();
int s = 0;
pair<long long,long long> mark[1000000000][1000000000] = {};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    mark[0].first = 1;
    mark[0].second = 1;
    int k;cin>>k;
    long long now = 0;
    while(k--) {
        long long b,w,n;b=w=0;cin>>n;
        if(n>now) {
            w = mark[now].first;
            b = mark[now].second;
            for(int i = now + 1;i<n;i++) {
                if(s == 1) {
                    if(mark[i+1].first != 0) {
                        s = 0;
                        w = mark[i].first;
                        b = mark[i].second;
                    }
                    continue;
                }
                if(b==0&&w==0) {
                    b=w=1;
                    continue;
                }
                swap(b,w);
                w = (b + w) % 998244353;
                mark[i].first = w;
                mark[i].second = b;
                now = i;
            }
        } else {
            w = mark[n-1].first;
            b = mark[n-1].second;
        }
        cout<<(b+w) % 998244353 - 1<<"\n";
        //pc();
    }
    return 0;
}
void pc() {
    for(int i = 0;i<10;i++) {
        cout<<mark[i].first<<" ";
    }
    cout<<"\n";
    for(int i = 0;i<10;i++) {
        cout<<mark[i].second<<" ";
    }
    cout<<"\n";
}