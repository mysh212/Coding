// Author : ysh
// 2023/07/28 Fri 13:17:25
#include<bits/stdc++.h>

using namespace std;

using lint = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> h;

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    vector<int> depth(n);
    vector<int> p(n, -1);
    for (int i : order) {
        for (int j = 0; j < a[i]; j++) {
            auto ver = h.top();
            int d = ver.first;
            int k = ver.second;
            h.pop();
            p[k] = i;
            depth[i] = max(depth[i], depth[k] + 1);
        }
        h.emplace(depth[i], i);
    }

    cout << *max_element(depth.begin(), depth.end()) << '\n';
    for (int i = 0; i < n; i++) {
        cout << p[i] + 1 << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}