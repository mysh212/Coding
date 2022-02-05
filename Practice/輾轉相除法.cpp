#include<bits/stdc++.h>
using namespace std;
int sq(int,int);
int main() {
	int a,b;cin>>a>>b;
	if(a<b) {
		swap(a,b);
	}
	cout<<sq(a,b);
}
int sq(int a,int b) {
	 	a = a % b;
	if(a == 0) {
		return b;
	}
	swap(a,b);
	return sq(a,b);
}
