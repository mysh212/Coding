#include<iostream>
#include<vector> //³æ¦V 
#include<deque>  //Âù¦V 
using namespace std;
int main() {
	int temp;
	deque<int>f; 
	
//	length=sizeof(a)/sizeof(char);
//	cout<<length;
	for(int i=0;i<5;i++){
		cin>>temp;
		f.push_back(temp); 
	}
	//f.erase(f.begin()+1,f.begin()+2);//sort
	f.insert(f.begin()+1,9);
	for(int i=0;i<f.size();i++){
		cout<<f[i]<<" "; 
	}
	cout<<f.front();
	cout<<f.empty();
}
