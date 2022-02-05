#include<bits/stdc++.h>
using namespace std;
void test(int,int);
void pc();
const int xx[4] = {-1,0,1,0};
const int yy[4] = {0,-1,0,1};
int a[9][9];
int mark[9][9]={0};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 0;i<9;i++) {
		string tmp;
		cin>>tmp;
		for(int j = 0;j<9;j++) {
			if(tmp.at(j) == '.') a[i][j] = 0;
			if(tmp.at(j) == 'B') a[i][j] = 1;
			if(tmp.at(j) == 'W') a[i][j] = 2;
		}
	}
	//check
	
	for(int i = 1;i<8;i++) {
		for(int j = 1;j<8;j++) {
			if(a[i][j] == 0) {
				int color = 0;
				for(int k = 0;k<4;k++) {
					if(a[i+xx[k]][j+yy[k]] != 0 && color == 0) {
						color = a[i+xx[k]][j+yy[k]];
					}
				}
				if(color != 0) {
					for(int k = 0;k<4;k++) {
						if(a[i+xx[k]][j+yy[k]] != 0 && a[i+xx[k]][j+yy[k]] != color) {
							cout<<"Wrong";
							return 0;
						}
					}
				}
			}
		}
	}
	//write
	for(int i = 1;i<8;i++) {
		for(int j = 1;j<8;j++) {
			if(a[i][j] != 0&&mark[i][j] != 1) {
				test(i,j);
			}
		}
	}
	//count
	int bb,ww;bb=ww=0;
	for(int i = 0;i<9;i++) {
		for(int j = 0;j<9;j++) {
			if(a[i][j] == 1) {
				bb += 1;
			}
			if(a[i][j] == 2) {
				ww += 1;
			}
		}
	}
	cout<<(bb>ww?"Black wins!!\n":"White wins!!\n")<<bb<<":"<<ww<<"\n";
	for(int i = 0;i<9;i++) {
		for(int j = 0;j<9;j++) {
			if(a[i][j] == 1) {
				cout<<"B";
			}
			if(a[i][j] == 2) {
				cout<<"W";
			}
		}
		cout<<"\n";
	}
}
void test(int x,int y) {
	mark[x][y] = 1;
	for(int i = 0;i<4;i++) {
		if(x+xx[i] >= 0 && x+xx[i] < 9 && y+yy[i] >= 0 && y+yy[i] < 9 && a[x+xx[i]][y+yy[i]] == 0) {
			a[x+xx[i]][y+yy[i]] = a[x][y];
			test(x+xx[i],y+yy[i]);
		}
	}
}
void pc() {
	for(int i = 0;i<9;i++) {
		for(int j = 0;j<9;j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
}
