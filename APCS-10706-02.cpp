#include<iostream>
#include<math.h> 
using namespace std;
int main() {
	int a = 0;cin>>a;
	int aa = a;
	int aans,bbns;aans=bbns=0;
	while(1) {
		int r = 0;
		for(int i=0;i<=log10(a);i++) {
			if((a/(int)pow(10,i) % 10)% 2 != 1) {
				r = 1;
			}
		}
		if(r == 0) {
			aans = a;
			break;
		}
		
		a -= 1;
	}
	a = aa;
	while(1) {
		int r = 0;
		a += 1;
		for(int i=0;i<=log10(a);i++) {
			if((a/(int)pow(10,i) % 10)% 2 != 1) {
				r = 1;
				break;
			}
		}
		if(r == 0) {
			bbns = a;
			break;
		}
	}
	a = aa;
	cout<<min(bbns - a,a - aans);
	return 0;
}
