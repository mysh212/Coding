#include<bits/stdc++.h>
using namespace std;
struct stu {
	int id;
	string name;
};
int main() {
	stu first[6];
	stu second;
	first[5].id=01;
	first[5].name="June";
	second = first[5];
	//strcpy(first[5].name,"June");
	cout<<first[5].id<<"\t"<<first[5].name<<"\n";
	cout<<second.id<<"\t"<<second.name;
}
