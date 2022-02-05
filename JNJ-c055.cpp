#include<iostream>
#include<string.h>
using namespace std;
int check();
int c[100000][100000] = {0};
int m[10001] = {0};
int cost[10000][10000] = {0};
int a;
int n = 0; 
int main() {
	cin>>a;
	//int c[100000][100000] = {0}; 
	for(int i = 1;i<=a;i++) {
		cin>>m[i];
	}
	int b;cin>>b;
	int tmp1,tmp2,tmp3;
	for(int j = 0;j<b;j++) {
		cin>>tmp1>>tmp2>>tmp3;
		cost[tmp1][tmp2] = tmp3;
		if(tmp1 == 1) {
			c[1][tmp2] = tmp3 + m[tmp2]; 
		} 
	}
	check();		//¨ì 0 
}
int check() {
	n += 1; 
	int tmp; 
	for(int i = 1;i<=a;i++) {
		if(i!=0) {
			for(int j = 1;j<=a;j++) {
				c[n][j] = c[n - 1][j]; 
				if(cost[i][j]!=0&&c[n - 1][i] == 0) {
					c[n][j] = c[n - 1][i] + cost[i][j] + m[j]; 
				} else if(cost[i][j]!=0) { 
					c[n][j] = min(c[n - 1][i],c[n - 1][i] + cost[i][j] + m[j]);
				}
				if(j == a) {
					tmp = c[n][a]; 
					break;
				}
				if(tmp !=0) { 
					tmp = check();
				} else {
					tmp = min(tmp,check()); 
				} 
			} 
		} 
	} 
	return tmp; 
}
