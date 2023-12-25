#pragma GCC target("popcnt")
#include<bits/stdc++.h>
using namespace std;
#ifdef ONPC
#include"debug.h"
#else
#define debug(...) 42
#endif
#define endl '\n'
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
const int mod = 1e9 + 7;
const int MAXN = 2e4 + 15;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int a[MAXN];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
    debug(n);
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < k; j++){
			char c; cin >> c;
			a[i] |= ((c - '0') << (k - j - 1));
		}
	}
	int ans = inf;
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			ans = min(ans, __builtin_popcount(a[i] ^ a[j]));
		}
	}
	cout << ans << endl;
}