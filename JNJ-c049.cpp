#include<iostream>
#include<string.h>
#include<deque>
using namespace std;
int main() {
	int a;cin>>a;
	int b[a] = {-1};
	int c[a] = {-1};
	int l[10000] = {};
	int ll[10000] = {};
	int tmp;
	for(int i = 1;i<=a - 1;i++) {
		cin>>b[i]>>c[i];
		l[b[i]] = i;
		ll[c[i]] = i;
		if(c[i] == 1) {
			tmp = i;
		}
	}
	deque<int>f;
	f.push_back(1);
	int n = 1;
	while(c[l[n]] != -1) {
		n = c[l[n]];
		f.push_back(n);
	}
	n = 1;
	while(b[ll[n]] != -1) {
		n = b[ll[n]];
		f.push_front(n);
	}
	for(int i = 0;i<f.size();i++) {
		cout<<f[i]<<" ";
	}
}
