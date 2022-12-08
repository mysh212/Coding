// Author : ysh
// 12/03/2022 Sat 20:17:16.51
// https://codeforces.com/contest/1741/problem/F
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

struct box{
    int a,b,c;
    box(int a = 0,int b = 0,int c = 0):
        a(a), b(b), c(c) {};
    inline bool operator<(box a) {
        return c < a.c;
    }
};

template<typename T>
struct seg_tree{
    int n;
    vector<T>f,hold;

    seg_tree(int n) {
        this->n = n;
        f.resize(n << 2);
        hold.resize(n << 2);
    }

    seg_tree(vector<T>&v) {
        this->n = v.size();
        f.resize(n << 2);
        hold.resize(n << 2);
        mt(1,0,n - 1,v);
    }
    
    void push(int t,int l,int r) {
        f.at(t) = f.at(t) || hold.at(t);
        hold.at(t << 1) = hold.at(t << 1) || hold.at(t);
        hold.at((t << 1) | 1) = hold.at((t << 1) | 1) || hold.at(t);
        hold.at(t) = 0;
    }

    T exact(int t,int l,int r) {
        return f.at(t) || hold.at(t);
    }

    T re(int t,int l,int r) {
        return f.at(t) = (exact((t << 1),l,(l + r) >> 1) || exact((t << 1) | 1,((l + r) >> 1) + 1,r));
    }

    T mt(int t,int l,int r,vector<T>&v) {
        if(l == r) return f.at(t) = v.at(l);
        int mid = (l + r) >> 1;
        return f.at(t) = mt((t << 1),l,mid,v) || mt((t << 1) | 1,mid + 1,r,v);
    }

    void add(int nl,int nr,T v,int t = 1,int l = 0,int r = -1) {
        if(r == -1) r = n - 1;
        if(nr < l || nl > r) return;
        if(l == r) {
            f.at(t) = 1;
            return;
        }
        push(t,l,r);
        int mid = (l + r) >> 1;
        if(nl <= l && nr >= r) {
            hold.at(t) = 1;
            return;
        }
        add(nl,nr,v,t << 1,l,mid),add(nl,nr,v,(t << 1) | 1,mid + 1,r);
        re(t,l,r);
        return;
    }

    T sum(int nl,int nr,int t = 1,int l = 0,int r = -1) {
        if(r == -1) r = n - 1;
        if(nr < l || nl > r) return 0;
        if(l == r) return f.at(t) || hold.at(t);
        push(t,l,r);
        int mid = (l + r) >> 1;
        if(nl <= l && nr >= r) return exact(t,l,r);
        return sum(nl,nr,t << 1,l,mid) || sum(nl,nr,(t << 1) | 1,mid + 1,r);
    }
};
map<int,int>re;
int offline(vector<vector<box>>&f,vector<box>&v) {
    map<int,int>m;
    for(box &i : v) {
        m.insert({i.a,0});
        m.insert({i.b,0});
    }
    int t = 0;
    for(auto &i : m) {
        re.insert({t,i.first});
        i.second = t++;
    }
    for(box &i : v) {
        i.a = m.find(i.a)->second;
        i.b = m.find(i.b)->second;
    }
    for(auto &i : f) {
        for(box &j : i) {
            j.a = m.find(j.a)->second;
            j.b = m.find(j.b)->second;
        }
    }
    return m.size();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        re.clear();
        int n;cin>>n;
        vector<vector<box>>f(n);
        vector<box>v;
        for(int i = 0;i<n;i++) {
            int a,b,c;cin>>a>>b>>c;
            a--;b--;c--;
            if(a > b) swap(a,b);
            f.at(c).push_back(box(a,b,c));
            v.push_back(box(a,b,c));
        }
        int k;
        seg_tree<bool>tt(k = offline(f,v));
        function<int(int,int,int,int)> check = [&] (int l,int r,int v,int t) {
            if(t == -1) t = 1;
            if(l == r) {
                if(tt.exact(t,l,r)) {
                    if(v <= l) {
                        return l;
                    }
                }
                return INT_MAX;
            }
            if(!tt.exact(t,l,r)) return INT_MAX;
            tt.push(t,l,r);
            if(v > r) return INT_MAX;
            int mid = (l + r) >> 1;
            int dt = INT_MAX;
            if(v <= r) {
                if(tt.exact(t << 1,l,mid)) {
                    int tmp = check(l,mid,v,t << 1);
                    if(tmp == INT_MAX) return check(mid + 1,r,v,(t << 1) | 1);
                    else return tmp;
                }
                else return check(mid + 1,r,v,(t << 1) | 1);
            }
            return -1;
        };
        function<int(int,int,int,int)> ck = [&] (int l,int r,int v,int t) {
            if(t == -1) t = 1;
            if(l == r) {
                if(tt.exact(t,l,r)) {
                    if(v >= r) return r;
                }
                return INT_MIN;
            }
            if(!tt.exact(t,l,r)) return INT_MIN;
            tt.push(t,l,r);
            if(v < l) return INT_MIN;
            int mid = (l + r) >> 1;
            int dt = INT_MIN;
            if(v >= l) {
                if(tt.exact((t << 1) | 1,mid + 1,r)) {
                    int tmp = ck(mid + 1,r,v,(t << 1) | 1);
                    if(tmp == INT_MIN) return ck(l,mid,v,t << 1);
                    else return tmp;
                }
                else return ck(l,mid,v,t << 1);
            }
            return -1;
        };
        map<pair<int,int>,int>m;
        for(int i = 0;i<=1;i++) {
            for(auto &i : f) {
                for(box &j : i) {
                    int tmp = check(0,k - 1,j.b,1);
                    auto found = m.find({j.a,j.b});
                    int ans = (found == m.end() ? INT_MAX : found->second);
                    if(tt.sum(j.a,j.b)) ans = 0;
                    else {
                        if(tmp != INT_MAX) ans = min(ans,(abs(re.find(tmp)->second - re.find(j.b)->second)));
                        tmp = ck(0,k - 1,j.a,1);
                        if(tmp != INT_MIN) ans = min(ans,abs(re.find(tmp)->second - re.find(j.a)->second));
                    }
                    m.insert({{j.a,j.b},ans});
                    m.find({j.a,j.b})->second = ans;
                }
                for(box &j : i) {
                    tt.add(j.a,j.b,1);
                }
            }
            reverse(f.begin(),f.end());
            tt = seg_tree<bool>(k);
        }
        for(box &i : v) {
            cout<<m.find({i.a,i.b})->second<<" ";
        }
        cout<<"\n";
    }
    return 0;
}