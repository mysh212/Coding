#include<bits/stdc++.h>
using namespace std;
void finding(int,int,int,int);
int color[10][10] = {};
int mark[10][10] = {0};
int main() {
	int ans = 0;
	int n;cin>>n;
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			cin>>color[i][j];
			if(color[i][j] == 0) {
				mark[i][j] = 1;
			}
		}
	}
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			if(mark[i][j] != 1&&color[i][j] != 0) {
				finding(i,j,color[i][j],n);
				ans += 1;
			}
		}
	}
	cout<<ans;
	return 0;
}
void finding(int a,int b,int c,int n) {
	int left,right,up,down;left=right=up=down=0;
	if(color[a][b] == c&&mark[a][b] != 1) {
		mark[a][b] = 1;
		if(a==0) up=1;
		if(b==0) left=1;
		if(a==n-1) down=1;
		if(b==n-1) right=1;
		if(down!=1) finding(a+1,b,c,n);//�V�U��
		if(up!=1) finding(a-1,b,c,n);//�V�W��
		if(left!=1) finding(a,b-1,c,n);//�V����
		if(right!=1) finding(a,b+1,c,n);//�V�k��
		return;
	} else {
		return;
	}
}
