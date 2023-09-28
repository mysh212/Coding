// Author : ysh
// 2023/07/28 Fri 14:48:17
#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    vector<array<int, 3>> ans;

    int mnx = *min_element(x.begin(), x.end());
    int mxx = *max_element(x.begin(), x.end());

    int midx = (mnx + mxx) / 2;

    int mny = *min_element(y.begin(), y.end());
    int mxy = *max_element(y.begin(), y.end());

    int midy = (mny + mxy) / 2;

    int ans1 = max(midx - mnx, mxx - midx);
    if (mxy - ans1 <= mny + ans1) {
        ans.push_back({ans1, midx, max(0ll, mxy - ans1)});
    }

    int ans2 = max(midy - mny, mxy - midy);
    if (mxx - ans2 <= mnx + ans2) {
        ans.push_back({ans2, max(0ll, mxx - ans2), midy});
    }

    int ans3 = 0;
    for (int i = 0; i < n; i++) {
        ans3 = max(ans3, max(abs(midx - x[i]), abs(midy - y[i])));
    }
    ans.push_back({ans3, midx, midy});

    sort(ans.begin(), ans.end());

    assert(!ans.empty());

    cout << ans[0][0] << '\n';
    cout << ans[0][1] << " " << ans[0][2] << '\n';

    return 0;
}