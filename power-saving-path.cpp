// https://203.64.159.117/ShowProblem?problemid=a269
#include<bits/stdc++.h>
using namespace std;
#define MAX 105
int f[MAX][MAX];
int c[MAX][MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a,b;cin>>a>>b;
	//vector<int,vector<int>>f(a + 1,vector<int>(b + 1));
	//vector<int,vector<int>>c(a + 1,vector<int>(b + 1));
	for(int i = 1;i<=a;i++) {
		for(int j = 1;j<=b;j++) {
			cin>>f[i][j];
		}
	}
	for(int i = 1;i<=a;i++) {
		for(int j = 1;j<=b;j++) {
			if(i == 1 && j == 1) {
				c[i][j] = 0;
				continue;
			}
			if(i == 1) {
				c[i][j] = c[i][j - 1] + abs(f[i][j] - f[i][j - 1]);
				continue;
			}
			if(j == 1) {
				c[i][j] = c[i - 1][j] + abs(f[i][j] - f[i - 1][j]);
				continue;
			}
			c[i][j] = min(c[i - 1][j] + abs(f[i][j] - f[i - 1][j]),c[i][j - 1] + abs(f[i][j] - f[i][j - 1])); 
		}
	}
	/*
	for(int i = 1;i<=a;i++) {
		for(int j = 1;j<=b;j++) {
			cout<<c[i][j]<<" ";
		}
		cout<<"\n";
	}
	*/
	cout<<c[a][b]<<"\n";
	return 0;
}
