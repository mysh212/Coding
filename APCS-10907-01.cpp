#include<iostream>
#include<math.h> 
using namespace std;
int main() {
	int a,b;cin>>a>>b;
	int c;cin>>c;
	int ans = 0;
	int tmp = -1;
	int tmpa,tmpb;tmpa=tmpb=0;
	for(int i = 0;i<c;i++) {
		while(tmp!=0) {
			cin>>tmp;
			if(tmp == a) {
				tmpa += 1;
			} 
			if(tmp == a * -1) {
				tmpa -= 1;
			} 
			if(tmp == b) {
				tmpb += 1;
			} 
			if(tmp == b * -1) {
				tmpb -= 1;
			}
		}
		tmp = -1;
		if(tmpa>0&&tmpb>0) {
			ans += 1;
		} 
		tmpa=tmpb=0;
	}
	cout<<ans;
	return 0;
}
