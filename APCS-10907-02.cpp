#include<iostream>
#include<math.h> 
using namespace std;
int main() {
	int n,m;cin>>n>>m;
	if(n == 0) {
		return 0;
	}
	int a,b;
	int d[n][7] = {1};
	int tmp = 0;
	for(int j = 0;j<n;j++) {
		d[j][1] = 1;
		d[j][2] = 4;
		d[j][3] = 6;
		d[j][4] = 3;
		d[j][5] = 5;
		d[j][6] = 2;
	} 
	for(int i = 0;i<m;i++) {
		cin>>a>>b;
		if(a>0&&b>0) { //交換 
			for(int j = 1;j<=6;j++) {
				tmp = d[a - 1][j];
				d[a - 1][j] = d[b - 1][j];
				d[b - 1][j] = tmp;
			} 
		}
		if(b == -1) { //向前 
			tmp = d[a - 1][1];
			d[a - 1][1] = d[a - 1][4];
			d[a - 1][4] = d[a - 1][3];
			d[a - 1][3] = d[a - 1][2];
			d[a - 1][2] = tmp;
		}
		if(b == -2) { //向右 
			tmp = d[a - 1][1];
			d[a - 1][1] = d[a - 1][5];
			d[a - 1][5] = d[a - 1][3];
			d[a - 1][3] = d[a - 1][6];
			d[a - 1][6] = tmp;
		}
	} 
	for(int j = 0;j<n;j++) {
		if(j == n - 1) {
			cout<<d[j][1];
		} else {
			cout<<d[j][1]<<" ";
		}
	} 
	return 0;
}
