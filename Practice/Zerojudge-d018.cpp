#include<bits/stdc++.h> 
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a;
	float ans = 0;
	while(getline(cin,a)) {
		stringstream d;
		d<<a;
		while(d>>a) {
			int b;
			b = a.find(':');
			string front,back;
			front = a.substr(0,b);
			back = a.substr(b+1);
			stringstream c,e;
			float tmp;
			int pm;
			c<<front;
			c>>pm;
			pm = pm % 2;
			e<<back;
			e>>tmp;
			if(pm == 1) {
				ans = ans + tmp;
			} else {
				ans = ans - tmp;
			}
		}
		cout<<ans<<"\n";
		ans = 0;
	} 
} 
