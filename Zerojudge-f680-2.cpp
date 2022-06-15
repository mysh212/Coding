#include<bits/stdc++.h>
using namespace std;
// void c.check(int,int,int,int);
void pm();
int color[10][10] = {};
int mark[10][10] = {0};
int main() {
    
class finding{
    public:
    void check(int a,int b,int c,int n) {
        int left,right,up,down;left=right=up=down=0;
        if(color[a][b] == c&&mark[a][b] != 1) {
            //pm();
            mark[a][b] = 1;
            if(a==0) up=1;
            if(b==0) left=1;
            if(a==n-1) down=1;
            if(b==n-1) right=1;
            //cout<<up<<down<<right<<left<<"\n";
            if(down!=1) check(a+1,b,c,n);//向下找
            if(up!=1) check(a-1,b,c,n);//向上找
            if(left!=1) check(a,b-1,c,n);//向左找
            if(right!=1) check(a,b+1,c,n);//向右找
    //		if(left!=1&&up!=1) check(a-1,b-1,c,n);//向左上找
    //		if(left!=1&&down!=1) check(a+1,b-1,c,n);//向左下找
    //		if(right!=1&&up!=1) check(a-1,b+1,c,n);//向右上找
    //		if(right!=1&&down!=1) check(a+1,b+1,c,n);//向右下找 
            return;
        } else {
            return;
        }
    }
}c;
	int ans = 0;
	int n;cin>>n;
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			cin>>color[i][j];
			if(color[i][j] == 0) {
				mark[i][j] = 1;
			}
		}
	}
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<n;j++) {
			if(mark[i][j] != 1&&color[i][j] != 0) {
				c.check(i,j,color[i][j],n);
				ans += 1;
			}
		}
	}
	cout<<ans;
	return 0;
}
void pm() {
	for(int i = 0;i<10;i++) {
		for(int j = 0;j<10;j++) {
			cout<<mark[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}