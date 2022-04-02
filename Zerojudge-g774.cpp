// Author : ysh
// 03/19/2022 Sat 18:16:44.54
// NA(20%)
#include<bits/stdc++.h>
using namespace std;
int check(int now,int sig,int a,int b,vector<pair<int,int>> f) {
	if(a - 1 >= 0&&b - 1 >= 0) return min(check(now + 1,sig + f.at(now).first,a - 1,b,f),check(now + 1,sig + f.at(now).second,a,b - 1,f));
	if(a - 1 >= 0) return check(now + 1,sig + f.at(now).first,a - 1,b,f);
	if(b - 1 >= 0) return check(now + 1,sig + f.at(now).second,a,b - 1,f);
	return min(sig + f.at(now).first,sig + f.at(now).second);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
	int n = a + b;
	vector<pair<int,int>>f(n+1);
	int tmpa,tmpb;
	for(int i = 1;i<=n;i++) {
		cin>>tmpa>>tmpb;
		f[i] = make_pair(tmpa,tmpb);
	}
	cout<<check(0,0,a,b,f);
	return 0;
}