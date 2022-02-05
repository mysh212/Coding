#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a,b;cin>>a>>b;
	int c[a] = {},d[a + 1] = {};
	int tmp = 0;
	for(int i = 0;i<b;i++) {
		int x,y,z;cin>>x>>y>>z;
		d[x - 1] += z;
		d[y] -= z;
	}
	swap(c[0],d[0]);
	for(int i = 1;i<a;i++) {
		c[i] = c[i - 1] + d[i];
	}
    /*
	for(int i = 0;i<a;i++) {
		cout<<c[i]<<" ";
	}
    */
	for(int i = 0;i<a;i++) {
		cin>>d[i];
	}
	sort(c,c+a);
	sort(d,d+a);	
	long long ans = 0;
	for(int i = 0;i<a;i++) {
		ans += c[i] * d[(a - 1) - i];
	}
	cout<<ans;
	return 0;
}