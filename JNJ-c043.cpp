#include<iostream>
#include<string.h>
using namespace std;
int check(int); 
int c[101] = {-1},d[101] = {-1},e[101] = {-1},f[101] = {-1};
int a = 0;
int main() {
	cin>>a;
	int b = 0;cin>>b;
	for(int i = 1;i<=b;i++) {
		cin>>c[i]>>d[i]>>e[i];
		f[c[i]] = i;
	}
	cout<<check(1);
}
int check(int i) {
	int tmp = -1;
	int ttmp = 0;
	//cout<<i<<"==>";
	if(i == a) {
		//cout<<"end!";
		return 0;
	}
	if(f[i] != 0) {
		return(min(e[f[i]] + check(d[f[i]]),100 + check(i + 1)));
		//cout<<"tmp:"<<tmp<<" ";
	}
	return(100 + check(i + 1));
	//cout<<"ttmp:"<<tmp<<" ";
	/*
	if(i == 1) {
		cout<<tmp<<" "<<ttmp<<" ";
	} 
	*/
	/*
	if(tmp == -1) {
		return ttmp;
	}
	return(min(tmp,ttmp)); 
	*/
}
