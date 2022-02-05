#include<bits/stdc++.h>
using namespace std;
int main() {
	string a,b;
	cin>>a>>b;
	int c[a.length()] = {},d[b.length()] = {};
	for(int i = 0;i<a.length();i++) {
		if(a.at(i) == 'A') {
			c[i] = 1;
		}
		if(a.at(i) == 'T') {
			c[i] = 2;
		}
		if(a.at(i) == 'C') {
			c[i] = 3;
		}
		if(a.at(i) == 'G') {
			c[i] = 4;
		}
	}
	for(int i = 0;i<b.length();i++) {
		if(b.at(i) == 'A') {
			d[i] = 1;
		}
		if(b.at(i) == 'T') {
			d[i] = 2;
		}
		if(b.at(i) == 'C') {
			d[i] = 3;
		}
		if(b.at(i) == 'G') {
			d[i] = 4;
		}
	}
	int e[max(a.length(),b.length())] = {},f[max(a.length(),b.length())] = {};
	for(int i = 0;i<b.length();i++) {
		for(int j = 0;j<a.length();j++) {
			if(c[j] == d[i]) {
				e[i] = 	
			}
		}
	}
}
