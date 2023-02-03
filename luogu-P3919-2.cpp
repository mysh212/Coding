// Author : ysh
// 02/03/2023 Fri 11:59:36.88
// https://www.luogu.com.cn/problem/solution/P3919
#include<bits/stdc++.h>
using namespace std;
struct box{
    int left;int right;int n;
    box(int a,int b,int c): left(a), right(b), n(c) {};
};
int n;
vector<box>f;

int create(int v,int l = -1,int r = -1) {
    return f.push_back(box(l,r,v)),f.size() - 1;
}

int update(int x,int v,int t = 0,int l = -1,int r = -1) {
    if(l == -1 && r == -1) l = 0,r = n - 1;
    if(l == r) return create(v);
    int mid = (l + r) >> 1;
    if(x <= mid) return update(x,v,f.at(t).left,l,mid);
    else return update(x,v,f.at(t).right,mid + 1,r),create(f.at(f.at(t).left),);
}

int sum(int x,int r,int l = -1,int r = -1) {
    if(l == -1 && r == -1) l = 0,r = n - 1;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    
}