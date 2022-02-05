#include<bits/stdc++.h>
using namespace std;
void print(int*,int,int);
void find(int*,int,int,int);
int main() {
	int a[6] = {92, 35, 8, 4, -1, 15};
	print(a,0,5); 
}
void print(int* a,int f,int t) {
	if(!(f>=0&&f<t)) {
		cout<<"ERROR!!";
		return;
	}
	for(int i = f;i<=t;i++) {
		cout<<a[i]<<" ";
	}
	return;
}
void find(int* a,int f,int t,int n) {
	int back = 0;
	if(!(f>=0&&f<t)) {
		cout<<"ERROR!!";
		return;
	}
	for(int i = f;i<=t;i++) {
		if(a[i] == n) {
			cout<<i;
			back = 1;
			break;
		}
	}
	if(back != 1) {
		cout<<"Not found!";
		return;
	}
	return;
}
