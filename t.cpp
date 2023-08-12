#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

int road[200005]={};
int dfs(vector<vi> &v,int parent, int n){
    if(v[n].size() == 1){
        road[n] = 1;
        return 1;
    }
    int ans=0;
    for(int i : v[n]){
        if(i!=parent)ans += dfs(v,n,i);
    }
    return road[n]=ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vi> v(n+1);
        for(int i=1 ; i<n ; i++){
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
            
        }
        int t=dfs(v,0,1);
        int m;
        cin>>m;
        while(m--){
            int a,b;
            cin>>a>>b;
            cout<<road[a]*road[b]<<'\n';
        }
    }
    return 0;
}