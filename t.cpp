#include<iostream>
using namespace std;

int main() {
	int n,m;
	while(cin >> n >> m) {
	int a[n][n] = {};
	for(int i = 0;i<n;i++) {
		cin>>a[i][0];
		for(int j = 1;j<n;j++) {
			cin>>a[i][j];
			a[i][j] = a[i][j - 1] + a[i][j];
		}
	}
	while(m--) {
		int ans = 0;
		int y,x,yy,xx;cin>>y>>x>>yy>>xx;
		for(int i = y - 1;i<=yy - 1;i++) {
			if(x != 1) { 
				ans += a[i][xx - 1] - a[i][x - 2];
			} else {
				ans += a[i][xx - 1];
			}
		}
		cout<<ans<<"\n";
		m = m - 1;
	}	
}
}