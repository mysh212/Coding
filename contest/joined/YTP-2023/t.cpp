#include<bits/stdc++.h>
#define endl '\n'
#define OuO ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define eps 1e-6
using namespace std;

bool cmp(long double a, long double b){
    return a < b;
}

signed main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<long double> v;
        for(int i = 0; i < n; ++i){
            cerr << i << ':' << endl;
            long double a, b, c;
            cin >> a >> b >> c;
            if(!a){
                long double x1 = (-b + sqrtl(b * b - 4 * a * c))  / (2 * a);
                long double x2 = (-b - sqrtl(b * b - 4 * a * c))  / (2 * a);
                v.push_back(x1);
                v.push_back(x2);
            }
            if(a == 0 && b != 0){
                long double x = -c / b;
                v.push_back(x);
            }
        }
        cerr << "tesn\n";
        sort(v.begin(), v.end());
        for(auto x: v) cerr << x << ' ';
        cerr << endl;
        int ans = v.size();
        for(int i = 0; i < v.size() - 1; ++i){
            if(abs(v[i + 1] - v[i]) < eps) 0;
        }
        cout << ans << endl;
    }
}
/*
1
4
1 -1 1
1 2 0
1 -2 1
-50 100 0
*/