#include<bits/stdc++.h> 
using namespace std;
template<typename T>
struct tree{
    std::vector<T>f;
    T n;

    tree(T n) {
        this->n = n;
        f.resize(n);
    }

    tree(std::vector<T>&v):
    tree(v.size()) {
        T t = 0;
        for(T i : v) add(t++,i);
    }

    void add(T a,T b) {
        for(;a < n;a = a | (a + 1)) {
            f[a] += b;
        }
    }

    T sum(T a) {
        T ans = 0;
        for(;a >= 0;a = (a & (a + 1)) - 1) {
            ans = ans + f[a];
        }
        return ans;
    }

    T sum(T a,T b) {
        if(a > b) std::swap(a,b);
        return sum((std::min(n - 1,b))) - sum(a - 1);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int aa,b;cin>>aa>>b;
        deque<int>f(aa);
        vector<vector<int>>pre(aa+1,vector<int>(11));
        tree<int>v(aa + 1);

        function<int(int)> get = [&] (int x) {
            return v.sum(x);
        };

        function<void(int,int)> add = [&] (int a,int b) {
            v.add(a,1);
            if(b < aa) v.add(b + 1,-1);
            return;
        };

        for(int &i : f) cin>>i;
        for(int i=1;i<=aa;i++) {
            pre[i][0]=f[i-1];
            for(int j=1;j<=10;j++)  {
                int r = pre[i][j];
                int now=pre[i][j-1];
                    while(now != 0) {
                        r = r + now % 10;
                        now = now / 10;
                    }
                    pre[i][j]=r;
            }
        }
        f.push_front(0);
        while(b--) {
            int a;cin>>a;
            if(a == 1) {
                int a,b;cin>>a>>b;
                add(a,b);
            } else {
                int c;cin>>c;
                int tmp = get(c);               
                cout<<pre[c][min(10,tmp)]<<"\n";
            }
        }
    }
    return 0;
}
