#include<iostream>
#include<cstring>
using namespace std;

int water[1001][1001]={0};
int vis[1001][1001]={0};

int check(int i,int j){
 if(vis[i][j]==1) return 0;
 int count=1;
 vis[i][j]=1;
 if(i!=0){
  if(water[i-1][j]==1 && vis[i-1][j]!=1){
   count+=check(i-1,j);
  }
 }
 if(j!=0){
  if(water[i][j-1]==1 && vis[i][j-1]!=1){
   count+=check(i,j-1);
  }
 }
 if(water[i+1][j]==1 && vis[i+1][j]!=1){
  count+=check(i+1,j);
 }
 if(water[i][j+1]==1 && vis[i][j+1]!=1){
  count+=check(i,j+1);
 }
 return count; 
}

int main(){
 int N,M,MAX=0,MIN=0,NUM=0;
 string s;
 cin>>N>>M;
 if(N == 0) {
 	cout<<0<<" "<<0<<" "<<0;
 	return 0;
 }
 int size[N*M]={0};
 for(int i=0;i<N;i++){
  cin>>s;
  for(int j=0;j<M;j++){
   if(s[j]=='W'){
    water[i][j]=1;    
   }else if(s[j]=='#'){
    water[i][j]=0;
   }
  }
 }
 for(int i=0;i<N;i++){
  for(int j=0;j<M;j++){
   if(water[i][j]==1 && vis[i][j]!=1){
    size[NUM]=check(i,j);
    if(size[NUM]!=0){
     NUM+=1;
    }
   }
  }
 }
 MAX=MIN=size[0];
 if(size[0]==0){
  cout<<0<<" "<<0<<" "<<0;
 }else{
  for(int i=0;i<NUM;i++){
   MAX=max(MAX,size[i]);
   MIN=min(MIN,size[i]);
  }
  cout<<MAX<<" "<<MIN<<" "<<NUM;
 }
}
