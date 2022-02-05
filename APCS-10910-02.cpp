#include<iostream>
#include<math.h>
using namespace std;
int main() {
	int r,c,k,m,max,min=-2;
	r=c=k=m=max=min=-2;
	cin>>r>>c>>k>>m;
	int a[r+1][c+1];
	int b[r+1][c+1];
	int e[r+1][c+1];
	int d[r+1][c+1];
	for(int i=1;i<=r;i++) {
		for(int j=1;j<=c;j++) {
			a[i][j]=0;
			b[i][j]=0;
			e[i][j]=0;
			d[i][j]=0;
		}
	}
	for(int i=1;i<=r;i++) {
		for(int j=1;j<=c;j++) {
			cin>>a[i][j];
		}
	}
	/*
	for(int i=1;i<=r;i++) {
		for(int j=1;j<=c;j++) {
			if (a[i][j]!=-1) {
				b[i][j]=a[i][j]/k;
			}
		}
	}
	for(int i=1;i<=r;i++) {
		for(int j=1;j<=c;j++) {
			if (a[i][j]!=-1) {
				int tl,tr,tu,td,t=0;
				tl=0;tr=0;tu=0;td=0;t=0;
				if (i>=2) {
					tu=1;
				}
				if (j>=2) {
					tl=1;
				}
				if (i<=r - 1) {
					td=1;
				}
				if (j<=c - 1) {
					tr=1;
				}
				
				
				if (tu==1) {
					if(a[i - 1][j]!=-1) {
						a[i - 1][j]+=b[i][j];
						t+=1;
					}
				}
				if (td==1) {
					if(a[i + 1][j]!=-1) {
						a[i + 1][j]+=b[i][j];
						t+=1;
					}
				}
				if (tl==1) {
					if(a[i][j - 1]!=-1) {
						a[i][j - 1]+=b[i][j];
						t+=1;
					}
				}
				if (tr==1) {
					if(a[i][j + 1]!=-1) {
						a[i][j + 1]+=b[i][j];
						t+=1;
					}
				}
				e[i][j]=t;
				a[i][j]-= b[i][j] * t;
			}
		}
	}

	m-=1;
	*/
	for(m;m>0;m--) {
	for(int i=1;i<=r;i++) {
		for(int j=1;j<=c;j++) {
			b[i][j]=0;
			e[i][j]=0;
		}
	}
	for(int i=1;i<=r;i++) {
		for(int j=1;j<=c;j++) {
			if (a[i][j]!=-1) {
				b[i][j]=a[i][j]/k;
			}
		}
	}
		for(int i=1;i<=r;i++) {
		for(int j=1;j<=c;j++) {
			if (a[i][j]!=-1) {
				int tl,tr,tu,td,t=0;
				tl=0;tr=0;tu=0;td=0;t=0;
				if (i>=2) {
					tu=1;
				}
				if (j>=2) {
					tl=1;
				}
				if (i<=r - 1) {
					td=1;
				}
				if (j<=c - 1) {
					tr=1;
				}
				
				
				if (tu==1) {
					if(a[i - 1][j]!=-1) {
						a[i - 1][j]+=b[i][j];
						t+=1;
					}
				}
				if (td==1) {
					if(a[i + 1][j]!=-1) {
						a[i + 1][j]+=b[i][j];
						t+=1;
					}
				}
				if (tl==1) {
					if(a[i][j - 1]!=-1) {
						a[i][j - 1]+=b[i][j];
						t+=1;
					}
				}
				if (tr==1) {
					if(a[i][j + 1]!=-1) {
						a[i][j + 1]+=b[i][j];
						t+=1;
					}
				}
			a[i][j]-= (b[i][j] * t);
				e[i][j]=t;
			}
		}
	}
	}
	for(int i=1;i<=r;i++) {
		for(int j=1;j<=c;j++) {
			if(a[i][j]!=-1) {
				if(a[i][j]>max||max==-2) {
					max=a[i][j];
				}
				if(a[i][j]<min||min==-2) {
					min=a[i][j];
				}
			}
		}
	}
			cout<<min<<"\n"<<max;
}
