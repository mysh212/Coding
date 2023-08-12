// Author : ysh
// 2023/07/28 Fri 12:30:27
#include<bits/stdc++.h>
using namespace std;
#include<seg_tree>
#include<tree>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    seg_tree<int> st(10);
    st.add(9, 1);
    cout << st.sum(0, 9);
}