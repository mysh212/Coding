#include<bits/stdc++.h>
using namespace std;
const int dx[8] = {1,0,-1,0,1,1,-1,-1};
const int dy[8] = {0,1,0,-1,-1,1,-1,1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b,n = 0;
    while(cin>>a>>b) {
    	n++;
    	if(a == b&&b == 0) {
    		return 0;
		} else {
			cout<<"Field #"<<n<<":\n";
		}
    int c[a+2][b+2] = {};
    for(int i = 1;i<=a;i++) {
        string tmp;
        cin>>tmp;
        for(int j = 1;j<=b;j++) {
            if(tmp.at(j - 1) == '*') {
                c[i][j] = -1;
                for(int k = 0;k<8;k++) {
                    if(c[i+dx[k]][j+dy[k]] != -1) {
                        c[i+dx[k]][j+dy[k]] += 1;
                    }
                }
            }
        }
    }
    for(int i = 1;i<=a;i++) {
        for(int j = 1;j<=b;j++) {
            if(c[i][j] == -1){
                cout<<"*";
                continue;
            }
            cout<<c[i][j];
        }
        cout<<"\n";
    }
}
}
