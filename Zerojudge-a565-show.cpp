#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	for(n;n!=0;n--) {
	    string a;cin>>a;
	    int p,times;p=times=0;
	    for(int i = 0;i<a.length();i++) {
	    	if(a.at(i) == 'p') {
	    		p += 1;
	    	}
	    	if(a.at(i) == 'q'&&p != 0) {
	    		p -= 1;
	    		times += 1;
			}
		}
		cout<<times<<"\n";
	}
	return 0;
}
