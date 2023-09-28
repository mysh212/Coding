// Author : ysh
// 2023/07/28 Fri 12:05:18
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif


struct BIT{
    #define lb(x) x&(-x)
    int n;
    vector<int> bit;
    void modify(int pos, int val){
        while(pos <= n){
            bit[pos] += val;
            pos += lb(pos);
        }
    }

    int query(int pos){
        int ret = 0;
        while(pos){
            ret += bit[pos];
            pos -= lb(pos);
        }
        return ret;
    }

    BIT(int sz){
        n = sz;
        bit.resize(n + 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    BIT bit(n);

    while(true){
        int cmd;
        cin >> cmd;
        if(cmd == 1){
            int pos, val;
            cin >> pos >> val;
            bit.modify(pos, val);
        }else{
            int pos;
            cin >> pos;
            cout << bit.query(pos) << endl;
        }
    }
    
}