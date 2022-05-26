// Author : ysh
// 05/11/2022 Wed  9:53:21.21
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX LONG_LONG_MAX
#define INT_MIN LONG_LONG_MIN
#define left l,mid - 1
#define right mid + 1,r
vector<int>f((int) 3e5 + 5);
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
inline int sig(int l,int r) {
    if(l > r) return INT_MIN;
	if(l == 0) return f[r];
	return f[r] - f[l - 1];
}
int check(int l,int r) {
	auto now = q.top();q.pop();
	while(now.second < l || now.second > r) {
		now = q.top();q.pop();
	}
	int mid = now.second;
	/*
    int mid;int tmp = INT_MAX;
    for(int i = l;i<=r;i++) {
        int s = sig(i,i);
        if(s < tmp) {
            tmp = s;
            mid = i;
        }
    }
	*/
    //cout<<"("<<l<<","<<r<<")"<<"\t";
    //system("pause");
    if(l == r - 1) return max(sig(l,l),sig(r,r));
	if(l == r) return f[r] - (r != 0 ? f[r - 1] : 0);
	if(sig(left) <= sig(right)) return check(right);
    return check(left);
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin>>n;
	int last = 0;
	for(int j = 0;j<n;j++) {
		cin>>f[j];
		q.push(make_pair(f[j],j));
		f[j] = last + f[j];
		last = f[j];
	}
	/*
	while(!q.empty()) {
		cout<<q.top().first<<" ";q.pop();
	}
	cout<<"\n";
	return 0;
	*/
	//for(int i = 0;i<n;i++) cout<<f[i]<<" ";
	//cout<<"\n";
	cout<<check(0,n - 1);
	return 0;	
}