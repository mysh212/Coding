// Author : ysh
// 03/10/2022 Thu 13:05:02.91
// WA
#include<bits/stdc++.h>
using namespace std;
int main() {
  	int a,b;cin>>a>>b;
  	vector<int>f(a+1);
  	int tmp;
  	int ans = 0;
  	int n = 0;
  	for(int i = 0;i<a;i++) {
    	cin>>tmp;
    	f[i] = tmp - n;
    	n = tmp;
    }
    f[a] = b - n;
	while(f.size() != 1) {
	    int mmin = INT_MAX;
	    int m = 0;
        int a = f.size();
	    for(int i = 0;i<a - 1;i++) {
	    	if(f[i] + f[i+1] < mmin) {
	    		mmin = f[i] + f[i+1];
	    		m=i;
	    	}
		}
		ans += mmin;
		f[m] = f[m] + f[m+1];
		f.erase(f.begin() + m+1);
        // for(int i : f) {
        //     cout<<i<<" ";
        // }
        // cout<<"\n";
	}
	cout<<ans;
	return 0;
}