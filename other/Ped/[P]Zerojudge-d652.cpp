#include<bits/stdc++.h> 
using namespace std;
int main() {
	int n;cin>>n;
	stack<int> c = {};
	for(int i = 0;i<n;i++) {
		int tmp;cin>>tmp;
		c.push(tmp);
	}
	while(c.length > 4) {
		int mmin = c[0] * c[1] * c[2];
		int mmintmp = 1;
		for(int i = 2;i<c.length() - 1;i++) {
			if(mmin>c[i - 1] * c[i] * c[i + 1]) {
			mmin = c[i - 1] * c[i] * c[i + 1];
			mmintmp = min(mmin,c[i - 1] * c[i] * c[i + 1]); 
		}
	c.remove(mmintmp);
	}
	cout<<mmin;
	return 0;
}
