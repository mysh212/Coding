#include<bits/stdc++.h>
using namespace std;
int check(int,int,int,int);
	int water[1001][1001] = {0};
	int vtd[1001][1001] = {0};
int main() {
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
	int a,b;cin>>a>>b;
	int size[a*b] = {0};
	string tmp;
	int st,mmax,mmin,lenning;st=mmax=mmin=lenning=0;
	for(int i = 0;i<a;i++) {
			cin>>tmp;
		for(int j = 0;j<tmp.length();j++) {
			if(tmp[j] == 'W') {
				water[i][j] = 1;
			}
			if(tmp[j] == '#') {
				water[i][j] = 0;
			}
		}
	}
	/*
	for(int i = 0;i<a;i++){
		for(int j = 0;j<b;j++) {
			cout<<water[i][j]<<" ";
		}
		cout<<"\n";
	}
	*/
	for(int i = 0;i<a;i++) {
		for(int j = 0;j<b;j++) {
			if(water[i][j] == 1&&vtd[i][j]!=1) {
				size[st] = check(a,b,i,j);
				if(size[st] != 0) {
				//cout<<size[st]<<"\n";
				st += 1;
				}
			}
		}
	}
	mmax=mmin=size[0];
	if(size[0] == 0) {
		cout<<0<<" "<<0<<" "<<0;
	} else {
		for(int n = 0;n<st;n++) {
			mmax = max(mmax,size[n]);
			mmin = min(mmin,size[n]);
		}
		cout<<mmax<<" "<<mmin<<" "<<st;
	}
}
int check(int a,int b,int i,int j) {
	if(water[i][j] == 0) {
		return 0;
	}
	int tmp = 1;
	vtd[i][j] = 1;
	//cout<<"visited:["<<i<<"]["<<j<<"]==>";
	if(i!=0) {
	if(water[i-1][j] == 1&&vtd[i-1][j]!=1) {
		tmp += check(a,b,i-1,j);
	}
	}
	if(j!=0) {
	if(water[i][j-1] == 1&&vtd[i][j-1]!=1) {
		tmp += check(a,b,i,j-1);
	}
	}
	if(water[i+1][j] == 1&&vtd[i+1][j]!=1) {
		tmp += check(a,b,i+1,j);
	}
	if(water[i][j+1] == 1&&vtd[i][j+1]!=1) {
		tmp += check(a,b,i,j+1);
	}
	return tmp;
}
