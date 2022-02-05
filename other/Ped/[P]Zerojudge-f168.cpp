#include<bits/stdc++.h>
using namespace std;
int r(int,int,int,int,int a,int b[],int);
int show(int r[],int a) {
	for(int i = 0;i<=a;i++) {
		cout<<r[i]<<" ";
	}
}
int aa = 0;
int ab = 0;
int ac = 0;
int main() {
	int a;cin>>a;
	int b[a + 1] = {0};
	int sum = 0;
	for(int i = 0;i<=a;i++) {
		cin>>b[i];
		sum += b[i];
	}
	if(sum%3 != 0) {
		cout<<"NO";
		return 0;
	} else {
		sum = sum / 3;
	}

}

int r(int m,int a,int b[],int mm,int sum) {
	if(m != a) {
		for(int j = 0;j<=a;j++) {
			int tmp = b[j];
			b[j] = 0;
			int y = r(m + 1,a,b,mm + tmp,sum);
			if(y = 1) {
				return 1;
			}
			b[j] = tmp;
		}
		return 0;
	} else {
		if(tmp == sum) {
			return 1;
		} else {
			return 0;
		}
	}
	/*
	if(m == 1) {
		for(int n = i + 1;n<=a;n++) {
			int y = r(2,i,n,0,a,b,sum);
			if(y == 1) {
				return 1;
			}
		}
	} else if(m == 2) {
		for(int n = j + 1;n<=a;n++) {
			int y = r(3,i,j,n,a,b,sum);
			if(y == 1) {
				return 1;
			}
		}
	} else {
		if(b[i] + b[j] + b[k] == sum) {
			aa = i,ab = j;ac = k;
			return 1;
		} else {
			return 0;
		}
	}
	*/
}
