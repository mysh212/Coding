#include<bits/stdc++.h>
using namespace std;
int main() {
    deque<int>f;
    int n,t;cin>>n>>t;
    for(int i = 1;i<=n;i++){
        int m;cin>>m;
        f.push_back(m);
    }
    for(int j = 1;j<=t;j++) {
        int r;cin>>r;
        if(r == 1) {
            int rm;cin>>rm;
            f.erase(f.begin()+rm);
        }
    }
    for(int i = 0;i<f.size() - 1;i++) {
    	cout<<f.at(i)<<" ";
	}
	cout<<f.at(f.size() - 1);
}
